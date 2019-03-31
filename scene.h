#ifndef SCENE_H
#define SCENE_H

#include <QWidget>

class QListWidgetItem;
class GameObject;

class Scene : public QWidget
{
    Q_OBJECT
public:
    explicit Scene(QWidget *parent = nullptr);
    ~Scene();

    void Clear();
    void Draw(QPaintDevice* p_device, QRect display_section);

    GameObject* AddEntity(QString name);
    void RemoveEntity(uint id);
    void SelectEntity(QListWidgetItem* item = nullptr);

public slots:
    void Save();
    void Load();

public:
    QVector<GameObject*> gameobjects;

    QString name = "untitled_scene";
    QColor background_color;
    int selected = -1;
    uint gameObjectsId = 0;
};

#endif // SCENE_H
