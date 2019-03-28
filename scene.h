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

public slots:
    void AddEntity(QString name);
    void RemoveEntity();
    void SelectEntity(QListWidgetItem* item = nullptr);

public:
    QVector<GameObject*> gameobjects;
    int selected = -1;
};

#endif // SCENE_H
