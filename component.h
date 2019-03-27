#ifndef COMPONENT_H
#define COMPONENT_H

class GameObject;

enum ComponentTYPE
{
    EMPTY,
    RECT_TRANSFORM,
    SHAPE_RENDERER
};

class Component
{
public:
    Component(GameObject* gameobject = nullptr, ComponentTYPE type = EMPTY);

public:
    GameObject* gameobject = nullptr;
    ComponentTYPE type = EMPTY;
};

#endif // COMPONENT_H
