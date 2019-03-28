#include "gameobject.h"
#include "comprecttransform.h"
#include "compshaperenderer.h"

GameObject::GameObject(QString name) :
    name(name)
{}

void GameObject::AddComponent(ComponentTYPE type)
{
    switch (type)
    {
    case RECT_TRANSFORM:
    {
        components.push_back(new CompRectTransform(this));
        break;
    }
    case SHAPE_RENDERER:
    {
        components.push_back(new CompShapeRenderer(this));
        break;
    }
    default: break;
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
