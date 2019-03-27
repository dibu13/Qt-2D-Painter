#include "scene.h"
#include "gameobject.h"
#include "comprecttransform.h"
#include "compshaperenderer.h"

Scene::Scene(QWidget *parent) : QWidget(parent)
{


}

void Scene::AddEntity()
{
    GameObject* go = new GameObject("Circle" + QString(gameobjects.count()));
    go->AddComponent(RECT_TRANSFORM);
    go->AddComponent(SHAPE_RENDERER);
    gameobjects.push_back(go);
}

void Scene::RemoveEntity()
{

}

void Scene::SelectEntity(QListWidgetItem* item)
{
    item = nullptr;
}
