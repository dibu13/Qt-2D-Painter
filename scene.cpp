#include "scene.h"
#include "gameobject.h"
#include "comprecttransform.h"
#include "compshaperenderer.h"

Scene::Scene(QWidget *parent) : QWidget(parent)
{


}

void Scene::AddEntity(QString name)
{
    GameObject* go = new GameObject(name);
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
