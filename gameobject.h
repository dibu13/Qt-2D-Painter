#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QVector>
#include "component.h"

class CompRectTransform;
class CompShapeRenderer;

class GameObject
{
public:
    GameObject(QString name);
    ~GameObject();

    void AddComponent(ComponentTYPE type);

public:
    QVector<Component*> components;
    QString name = "Empty GameObject";
    uint id = 0;
    bool active = true;

    CompRectTransform* transform = nullptr;
    CompShapeRenderer* shape_renderer = nullptr;
};

#endif // GAMEOBJECT_H
