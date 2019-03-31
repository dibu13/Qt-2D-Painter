#include "scene.h"
#include "gameobject.h"
#include "comprecttransform.h"
#include "compshaperenderer.h"
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>

Scene::Scene(QWidget *parent) : QWidget(parent)
{}

void Scene::Draw(QPaintDevice* p_device, QRect display_section)
{
    QPainter p(p_device);

    // Draw border
    p.drawRect(display_section);

    for (int i = 0; i < gameobjects.count(); i++)
    {
        GameObject* go = gameobjects[i];

        if (go->active)
            go->shape_renderer->Draw(p, display_section, i == selected);
    }
}

GameObject* Scene::AddEntity(QString name)
{
    GameObject* go = new GameObject(name);
    go->id = gameObjectsId;
    gameObjectsId++;
    go->AddComponent(RECT_TRANSFORM);
    go->AddComponent(SHAPE_RENDERER);
    gameobjects.push_back(go);

    return go;
}

void Scene::RemoveEntity(uint id)
{
    foreach (GameObject* go, gameobjects) {
        if(id == go->id)
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

void Scene::Save()
{
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save Scene"), "", tr("Scene (*.scene);;All Files (*)"));

    if (!fileName.isEmpty())
    {
        QFile file(fileName);

        if (file.open(QIODevice::WriteOnly))
        {
            QDataStream out(&file);
            out.setVersion(QDataStream::Qt_4_5);

            out << name;
            out << selected;
            out << gameObjectsId;

            out << gameobjects.count();
            foreach (GameObject* go, gameobjects)
            {
                go->Save(out);
            }
        }
        else
        {
            QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        }
    }
}

void Scene::Load()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Load Scene"), "", tr("Scene (*.scene);;All Files (*)"));

        if (!fileName.isEmpty())
        {
            QFile file(fileName);

            if (file.open(QIODevice::ReadOnly))
            {
                QDataStream in(&file);
                in.setVersion(QDataStream::Qt_4_5);

                in >> name;
                in >> selected;
                in >> gameObjectsId;

                int go_count;
                in >> go_count;


                if (go_count > 0)
                {
                    foreach (GameObject* go, gameobjects)
                    {
                        delete go;
                        gameobjects.pop_front();
                    }

                    gameobjects.clear();

                    for (int i = 0; i < go_count; i++)
                    {
                        GameObject* go = new GameObject();
                        go->Load(in);
                        gameobjects.push_back(go);

                    }
                }
                else
                {
                    QMessageBox::information(this, tr("Empty Scene"), tr("The scene you are attempting to open is empty."));
                }

                // set selected on hierarchy
                //if (selected >= 0) {}
            }
            else
            {
                QMessageBox::information(this, tr("Unable to open file"),file.errorString());
            }
        }
}
