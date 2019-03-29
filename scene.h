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
    void Draw(QPaintDevice* p_device, QRect display_section);

public slots:
    void AddEntity(QString name);
    void RemoveEntity(QString name);
    void SelectEntity(QListWidgetItem* item = nullptr);

public:
    QVector<GameObject*> gameobjects;
    int selected = -1;
};

#endif // SCENE_H
