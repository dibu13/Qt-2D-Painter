#include "scene.h"
#include "gameobject.h"
#include "comprecttransform.h"
#include "compshaperenderer.h"
#include <QPainter>

Scene::Scene(QWidget *parent) : QWidget(parent)
{}

void Scene::Draw(QPaintDevice* p_device, QRect display_section)
{
    QPainter p(p_device);

    p.drawRect(display_section);
    p.drawLine(200, 200, 400, 400);
}

void Scene::AddEntity(QString name)
{
    GameObject* go = new GameObject(name);
    go->AddComponent(RECT_TRANSFORM);
    go->AddComponent(SHAPE_RENDERER);
    gameobjects.push_back(go);
}

void Scene::RemoveEntity(QString name)
{
    foreach (GameObject* go, gameobjects) {
        if(name == go->name)
        {
            delete go;
            gameobjects.removeOne(go);
        }
    }
}

void Scene::SelectEntity(QListWidgetItem* item)
{
    item = nullptr;
}
