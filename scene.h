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

/*public slots:
    void AddEntity();
    void RemoveEntity();
    void SelectEntity(QListWidgetItem* item = nullptr);

public:
    QVector<GameObject*> scenegObjectVector;*/
};

#endif // SCENE_H
