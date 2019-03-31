#include "scene.h"
#include "gameobject.h"
#include "comprecttransform.h"
#include "compshaperenderer.h"
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>

Scene::Scene(QWidget *parent) : QWidget(parent)
{
    background_color = Qt::white;
    background_color.setAlphaF(0.5);
}

Scene::~Scene()
{
    Clear();

    name = "untitled_scene";
    selected = -1;
    gameObjectsId = 0;
}

void Scene::Clear()
{
    foreach (GameObject* go, gameobjects)
    {
        delete go;
        gameobjects.pop_front();
    }

    gameobjects.clear();

    background_color = Qt::white;
    background_color.setAlphaF(0.5);
}

void Scene::Draw(QPaintDevice* p_device, QRect display_section)
{
    QPainter p(p_device);

    // Draw border
    p.setBrush(QBrush(background_color));
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
    if (gameobjects.isEmpty())
    {
        QMessageBox::information(this, tr("Empty Scene"), tr("Scene is empty"));
    }
    else
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

                out << gameobjects.count();
                foreach (GameObject* go, gameobjects)
                {
                    go->Save(out);
                }

                out << name;
                out << selected;
                out << gameObjectsId;
                out << background_color;
            }
            else
            {
                QMessageBox::information(this, tr("Unable to open file"), file.errorString());
            }
        }
    }
}

void Scene::Load()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Load Scene"), "", tr("Scene (*.scene)"));

        if (!fileName.isEmpty())
        {
            QFile file(fileName);

            if (file.open(QIODevice::ReadOnly))
            {
                QDataStream in(&file);
                in.setVersion(QDataStream::Qt_4_5);

                int go_count;
                in >> go_count;

                if (go_count > 0)
                {
                    std::cout << "Loaded:" << std::endl;
                    Clear();
                    GameObject* go = nullptr;
                    for (int i = 0; i < go_count; i++)
                    {
                        gameobjects.push_back(go = new GameObject());
                        std::cout << "   ";
                        go->Load(in);
                    }

                    in >> name;
                    in >> selected;
                    in >> gameObjectsId;
                    in >> background_color;
                }
                else
                {
                    QMessageBox::information(this, tr("Empty Scene"), tr("The scene you are attempting to open is empty."));
                }
            }
            else
            {
                QMessageBox::information(this, tr("Unable to open file"),file.errorString());
            }
        }
}
