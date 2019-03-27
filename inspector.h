#ifndef INSPECTOR_H
#define INSPECTOR_H

#include <QWidget>

namespace Ui {
class Inspector;
class CompRectTransformView;
class CompShapeRendererView;
}

class GameObject;

class Inspector : public QWidget
{
    Q_OBJECT

public:
    explicit Inspector(QWidget *parent = nullptr);
    ~Inspector();

public:
    GameObject* reference = nullptr;

private:
    Ui::Inspector *uiInspector;
    Ui::CompRectTransformView *uiRectTransform;
    Ui::CompShapeRendererView *uiShapeRenderer;

    QWidget *inspectorWidget = nullptr;
    QWidget *rectTransformWidget = nullptr;
    QWidget *shapeRendererWidget = nullptr;
};

#endif // INSPECTOR_H
