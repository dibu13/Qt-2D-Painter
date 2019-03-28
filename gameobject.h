#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QVector>
#include "component.h"

class GameObject
{
public:
    GameObject(QString name);
    ~GameObject();

    void AddComponent(ComponentTYPE type);

public:
    QVector<Component*> components;
    QString name = "Empty GameObject";
    bool active = true;
};

#endif // GAMEOBJECT_H
