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
#include <QColorDialog>

Inspector::Inspector(QWidget *parent) :
    QWidget(parent),
    uiGameObjectView(new Ui::gameObjectView),
    uiComponentTransformView(new Ui::compRectTransformView),
    uiCompShapeRendererView(new Ui::compShapeRendererView)
{
    gameObjectView = new QWidget();
    compRectTransformView = new QWidget();
    compShapeRendererView = new QWidget();

    uiGameObjectView->setupUi(gameObjectView);
    uiComponentTransformView->setupUi(compRectTransformView);
    uiCompShapeRendererView->setupUi(compShapeRendererView);

    uiCompShapeRendererView->shapeCombo->addItem("Circle");
    uiCompShapeRendererView->shapeCombo->addItem("Rectangle");

    uiCompShapeRendererView->strokeCombo->addItem("None");
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

    // Connect Slots
    connect(uiGameObjectView->checkBox, SIGNAL(clicked()), this, SLOT(changeGameObjectCheckBox()));

    connect(uiComponentTransformView->posXInput, SIGNAL(valueChanged(double)), this, SLOT(changePosX()));
    connect(uiComponentTransformView->posYInput, SIGNAL(valueChanged(double)), this, SLOT(changePosY()));
    connect(uiComponentTransformView->scaleXInput, SIGNAL(valueChanged(double)), this, SLOT(changeScaleX()));
    connect(uiComponentTransformView->scaleYInput, SIGNAL(valueChanged(double)), this, SLOT(changeScaleY()));

    connect(uiCompShapeRendererView->fillColorButon, SIGNAL(clicked()), this, SLOT(FillColor()));
    connect(uiCompShapeRendererView->strokeColorButton, SIGNAL(clicked()), this, SLOT(StrokeColor()));

    connect(uiCompShapeRendererView->sizeInput, SIGNAL(valueChanged(double)), this, SLOT(changeSize()));
    connect(uiCompShapeRendererView->strokeInput, SIGNAL(valueChanged(double)), this, SLOT(changeStrokeThick()));

    connect(uiCompShapeRendererView->shapeCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(changeShape()));
    connect(uiCompShapeRendererView->strokeCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(changeStrokeStyle()));
}

Inspector::~Inspector()
{
    delete uiGameObjectView;
    delete uiComponentTransformView;
    delete uiCompShapeRendererView;
}

void Inspector::reloadInspector()
{
    if (selectedGameObject != nullptr)
    {
        gameObjectView->setVisible(true);
        compRectTransformView->setVisible(true);
        compShapeRendererView->setVisible(true);

        //GameObjectView
        uiGameObjectView->checkBox->setChecked(selectedGameObject->active);
        uiGameObjectView->label->setText(selectedGameObject->name);

        //ComponentTransformView
        uiComponentTransformView->posXInput->setValue(static_cast<double>(selectedGameObject->transform->pos_x));
        uiComponentTransformView->posYInput->setValue(static_cast<double>(selectedGameObject->transform->pos_y));

        uiComponentTransformView->scaleXInput->setValue(static_cast<double>(selectedGameObject->transform->scale_x));
        uiComponentTransformView->scaleYInput->setValue(static_cast<double>(selectedGameObject->transform->scale_y));

        //ComponentShapeRendererView
        uiCompShapeRendererView->shapeCombo->setCurrentIndex(static_cast<int>(selectedGameObject->shape_renderer->shape));

        uiCompShapeRendererView->sizeInput->setValue(static_cast<double>(selectedGameObject->shape_renderer->size));

        QColor c = selectedGameObject->shape_renderer->fill_color;
        uiCompShapeRendererView->fillColorButon->setStyleSheet(
                    QString("background-color: rgb(%1, %2, %3)").arg(c.red()).arg(c.green()).arg(c.blue()));

        c = selectedGameObject->shape_renderer->stroke_color;
        uiCompShapeRendererView->strokeColorButton->setStyleSheet(
                    QString("background-color: rgb(%1, %2, %3)").arg(c.red()).arg(c.green()).arg(c.blue()));

        uiCompShapeRendererView->strokeInput->setValue(selectedGameObject->shape_renderer->stroke_thickness);
        uiCompShapeRendererView->strokeCombo->setCurrentIndex(selectedGameObject->shape_renderer->stroke_style);
    }
    else
    {
        gameObjectView->setVisible(false);
        compRectTransformView->setVisible(false);
        compShapeRendererView->setVisible(false);
    }
}

void Inspector::FillColor()
{
    ColorDialog(selectedGameObject->shape_renderer->fill_color);
    reloadInspector();
}

void Inspector::StrokeColor()
{
    ColorDialog(selectedGameObject->shape_renderer->stroke_color);
    reloadInspector();
}

void Inspector::ColorDialog(QColor& color)
{
    QColor new_color = QColorDialog::getColor(color, this, "Choose color");

    if (new_color.isValid())
    {
        color = new_color;
    }
}

void Inspector::changeGameObjectCheckBox()
{
    selectedGameObject->active = uiGameObjectView->checkBox->isChecked();
}

void Inspector::changePosX()
{
    selectedGameObject->transform->pos_x = static_cast<float>(uiComponentTransformView->posXInput->value());
}

void Inspector::changePosY()
{
    if(selectedGameObject != nullptr)
    {
        selectedGameObject->transform->pos_y = uiComponentTransformView->posYInput->value();
    }
}

void Inspector::changeScaleX()
{
    if(selectedGameObject != nullptr)
    {
        selectedGameObject->transform->scale_x = uiComponentTransformView->scaleXInput->value();
    }
}

void Inspector::changeScaleY()
{
    if(selectedGameObject != nullptr)
    {
        selectedGameObject->transform->scale_y = uiComponentTransformView->scaleYInput->value();
    }
}

void Inspector::changeSize()
{
    if(selectedGameObject != nullptr)
    {
        selectedGameObject->shape_renderer->size = uiCompShapeRendererView->sizeInput->value();
    }
}

void Inspector::changeStrokeThick()
{
    if(selectedGameObject != nullptr)
    {
        selectedGameObject->shape_renderer->stroke_thickness = uiCompShapeRendererView->strokeInput->value();
    }
}

void Inspector::changeShape()
{
    if(selectedGameObject != nullptr)
    {
        selectedGameObject->shape_renderer->shape = static_cast<SHAPE>(uiCompShapeRendererView->shapeCombo->currentIndex());
    }
}

void Inspector::changeStrokeStyle()
{
    if(selectedGameObject != nullptr)
    {
        selectedGameObject->shape_renderer->stroke_style = static_cast<SHAPE>(uiCompShapeRendererView->strokeCombo->currentIndex());
    }
}
