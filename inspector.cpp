#include "inspector.h"
#include "ui_gameobjectview.h"
#include "ui_comprecttransformview.h"
#include "ui_compshaperendererview.h"

Inspector::Inspector(QWidget *parent) :
    QWidget(parent),
    uiGameobject(new Ui::Form),
    uiRectTransform(new Ui::CompRectTransformView),
    uiShapeRenderer(new Ui::CompShapeRendererView)
{

    gameobjectWidget = new QWidget();
    uiGameobject->setupUi(gameobjectWidget);
    //gameobjectWidget->show();

    rectTransformWidget = new QWidget();
    uiRectTransform->setupUi(rectTransformWidget);
    //rectTransformWidget->show();

    shapeRendererWidget = new QWidget();
    uiShapeRenderer->setupUi(shapeRendererWidget);
    //shapeRendererWidget->show();

    QLayout* layout = new QVBoxLayout();
    layout->addWidget(gameobjectWidget);
    layout->addWidget(rectTransformWidget);
    layout->addWidget(shapeRendererWidget);

    QWidget* inspectorWindow = new QWidget();
    inspectorWindow->setLayout(layout);
    inspectorWindow->show();
}

Inspector::~Inspector()
{
    delete uiGameobject;
    delete uiRectTransform;
    delete uiShapeRenderer;
}
