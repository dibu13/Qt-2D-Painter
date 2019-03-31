#include "inspector.h"
#include "gameobject.h"
#include "component.h"
#include "comprecttransform.h"
#include "compshaperenderer.h"
#include "ui_gameobjectview.h"
#include "ui_comprecttransformview.h"
#include "ui_compshaperendererview.h"
#include <iostream>
#include <QSpacerItem>

Inspector::Inspector(QWidget *parent) :
    QWidget(parent),
    uiGameObjectView(new Ui::gameObjectView),
    uiComponentTransformView(new Ui::compRectTransformView),
    uiCompShapeRendererView(new Ui::compShapeRendererView)
{
    QWidget* gameObjectView = new QWidget();
    QWidget* compRectTransformView = new QWidget();
    QWidget* compShapeRendererView = new QWidget();

    uiGameObjectView->setupUi(gameObjectView);
    uiComponentTransformView->setupUi(compRectTransformView);
    uiCompShapeRendererView->setupUi(compShapeRendererView);

    uiCompShapeRendererView->shapeCombo->addItem("Rectangle");
    uiCompShapeRendererView->shapeCombo->addItem("Circle");

    uiCompShapeRendererView->strokeCombo->addItem("Solid");
    uiCompShapeRendererView->strokeCombo->addItem("Dash");
    uiCompShapeRendererView->strokeCombo->addItem("Dot");
    uiCompShapeRendererView->strokeCombo->addItem("Dash dot");
    uiCompShapeRendererView->strokeCombo->addItem("Dash dot dot");

    //Widget Layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(gameObjectView);
    layout->addWidget(compRectTransformView);
    layout->addWidget(compShapeRendererView);

    setLayout(layout);
}

Inspector::~Inspector()
{
    delete uiGameObjectView;
    delete uiComponentTransformView;
    delete uiCompShapeRendererView;
}

void Inspector::reloadInspector()
{
    //GameObjectView
    uiGameObjectView->checkBox->setChecked(selectedGameObject->active);

    //ComponentTransformView
    uiComponentTransformView->posXInput->setValue(selectedGameObject->transform->pos_x);
    uiComponentTransformView->posYInput->setValue(selectedGameObject->transform->pos_y);

    uiComponentTransformView->scaleXInput->setValue(selectedGameObject->transform->scale_x);
    uiComponentTransformView->scaleYInput->setValue(selectedGameObject->transform->scale_y);

    //ComponentShapeRendererView
    if(selectedGameObject->shape_renderer->shape == RECT)
        uiCompShapeRendererView->shapeCombo->setCurrentIndex(0);
    if(selectedGameObject->shape_renderer->shape == CIRCLE)
        uiCompShapeRendererView->shapeCombo->setCurrentIndex(1);

    uiCompShapeRendererView->sizeInput->setValue(selectedGameObject->shape_renderer->size);

    int colorR,colorG,colorB;
    selectedGameObject->shape_renderer->fill_color.getRgb(&colorR,&colorG,&colorB);
    QString qss = QString("background-color: rgb(%1, %2, %3)").arg(colorR).arg(colorG).arg(colorB);
    uiCompShapeRendererView->fillColorButon->setStyleSheet(qss);
    std::cout << colorR << "," << colorG << "," << colorB << std::endl;
    std::cout << qss.toStdString() << std::endl;

    selectedGameObject->shape_renderer->stroke_color.getRgb(&colorR,&colorG,&colorB);
    qss = QString("background-color: rgb(%1, %2, %3)").arg(colorR).arg(colorG).arg(colorB);
    uiCompShapeRendererView->strokeColorButton->setStyleSheet(qss);
    std::cout << colorR << "," << colorG << "," << colorB << std::endl;
    std::cout << qss.toStdString() << std::endl;

    uiCompShapeRendererView->strokeInput->setValue(selectedGameObject->shape_renderer->stroke_thickness);

    if(selectedGameObject->shape_renderer->stroke_style == 1)
        uiCompShapeRendererView->strokeCombo->setCurrentIndex(0);
    if(selectedGameObject->shape_renderer->stroke_style == 2)
        uiCompShapeRendererView->strokeCombo->setCurrentIndex(1);
    if(selectedGameObject->shape_renderer->stroke_style == 3)
        uiCompShapeRendererView->strokeCombo->setCurrentIndex(2);
    if(selectedGameObject->shape_renderer->stroke_style == 4)
        uiCompShapeRendererView->strokeCombo->setCurrentIndex(3);
    if(selectedGameObject->shape_renderer->stroke_style == 5)
        uiCompShapeRendererView->strokeCombo->setCurrentIndex(4);
}
