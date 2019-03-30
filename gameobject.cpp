#include "gameobject.h"
#include "comprecttransform.h"
#include "compshaperenderer.h"

GameObject::GameObject(QString name) :
    name(name)
{}

Component* GameObject::AddComponent(ComponentTYPE type)
{
    switch (type)
    {
    case RECT_TRANSFORM:
    {
        components.push_back(transform = new CompRectTransform(this));
        break;
    }
    case SHAPE_RENDERER:
    {
        components.push_back(shape_renderer = new CompShapeRenderer(this));
        break;
    }
    default: break;
    }

    return components.last();
}

void GameObject::Save(QDataStream& out)
{
    out << name;
    out << id;
    out << active;
    out << components.count();

    foreach (Component* comp, components)
    {
        out << comp->type;
        comp->Save(out);
    }
}

void GameObject::Load(QDataStream& in)
{
    in << name;
    in << id;
    in << active;

    int comp_count;
    in >> comp_count;

    for (int i = 0; i < comp_count; i++)
    {
        uint type;
        in >> type;
        Component* comp = AddComponent(ComponentTYPE(type));
        comp->Load(in);
    }
}

GameObject::~GameObject()
{
    foreach (Component* comp, components)
    {
        delete comp;
    }
    components.clear();
}
