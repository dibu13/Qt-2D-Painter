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

    // Draw border
    p.drawRect(display_section);

    for (int i = 0; i < gameobjects.count(); i++)
    {
        gameobjects[i]->shape_renderer->Draw(p, display_section, i == selected);
    }
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
