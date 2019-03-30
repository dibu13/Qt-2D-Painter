#ifndef INSPECTOR_H
#define INSPECTOR_H

#include <QWidget>

namespace Ui {
class gameObjectView;
class compRectTransformView;
class compShapeRendererView;
}

class GameObject;

class Inspector : public QWidget
{
    Q_OBJECT

public:
    explicit Inspector(QWidget *parent = nullptr);
    ~Inspector();

    GameObject* selectedGameObject = nullptr;

    void reloadInspector();

private:
    Ui::gameObjectView *uiGameObjectView;
    Ui::compRectTransformView *uiComponentTransformView;
    Ui::compShapeRendererView *uiCompShapeRendererView;
};

#endif // INSPECTOR_H
