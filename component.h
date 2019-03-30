#ifndef COMPONENT_H
#define COMPONENT_H

#include <QDataStream>

class GameObject;

enum ComponentTYPE : uint
{
    EMPTY,
    RECT_TRANSFORM,
    SHAPE_RENDERER
};

class Component
{
public:
    Component(GameObject* gameobject = nullptr, ComponentTYPE type = EMPTY);
    virtual ~Component();

    virtual void Save(QDataStream& stream) = 0;
    virtual void Load(QDataStream& stream) = 0;

public:
    GameObject* gameobject = nullptr;
    ComponentTYPE type = EMPTY;
};

#endif // COMPONENT_H
