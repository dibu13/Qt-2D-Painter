#include "component.h"

Component::Component(GameObject* gameobject, ComponentTYPE type) :
    gameobject(gameobject),
    type(type)
{}
