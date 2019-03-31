#ifndef INSPECTOR_H
#define INSPECTOR_H

#include <QWidget>
#include <QColor>

namespace Ui {
class gameObjectView;
class compRectTransformView;
class compShapeRendererView;
}

class GameObject;
class MainWindow;

class Inspector : public QWidget
{
    Q_OBJECT

public:
    explicit Inspector(QWidget *parent = nullptr);
    ~Inspector();

    void reloadInspector();
    void ColorDialog(QColor& color);

public slots:

    void FillColor();
    void StrokeColor();
    void changeGameObjectCheckBox();
    void changePosX();

public:

    GameObject* selectedGameObject = nullptr;

private:
    Ui::gameObjectView *uiGameObjectView;
    Ui::compRectTransformView *uiComponentTransformView;
    Ui::compShapeRendererView *uiCompShapeRendererView;

    QWidget* gameObjectView;
    QWidget* compRectTransformView;
    QWidget* compShapeRendererView;
};

#endif // INSPECTOR_H
