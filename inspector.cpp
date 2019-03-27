#include "inspector.h"
#include "ui_gameobjectview.h"
#include "ui_comprecttransformview.h"
#include "ui_compshaperendererview.h"
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
