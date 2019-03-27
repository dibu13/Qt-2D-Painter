#include "inspector.h"
#include "ui_inspector.h"
#include "ui_comprecttransformview.h"
#include "ui_compshaperendererview.h"

Inspector::Inspector(QWidget *parent) :
    QWidget(parent),
    uiInspector(new Ui::Inspector),
    uiRectTransform(new Ui::CompRectTransformView),
    uiShapeRenderer(new Ui::CompShapeRendererView)
{
    QWidget* inspectorWindow = new QWidget(this);

    inspectorWidget = new QWidget(inspectorWindow);
    uiInspector->setupUi(inspectorWidget);
    //inspectorWidget->show();

    rectTransformWidget = new QWidget(inspectorWindow);
    uiRectTransform->setupUi(rectTransformWidget);
    rectTransformWidget->show();

    shapeRendererWidget = new QWidget(inspectorWindow);
    uiShapeRenderer->setupUi(shapeRendererWidget);
    shapeRendererWidget->show();

    QLayout* layout = new QVBoxLayout(inspectorWindow);
    layout->addWidget(inspectorWidget);
    layout->addWidget(rectTransformWidget);
    layout->addWidget(shapeRendererWidget);

    inspectorWindow->setLayout(layout);
    inspectorWindow->show();
}

Inspector::~Inspector()
{
    delete uiInspector;
    delete uiRectTransform;
    delete uiShapeRenderer;
}
