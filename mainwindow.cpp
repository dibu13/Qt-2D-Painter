#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_rendering.h"
#include "ui_hierarchy.h"
#include "inspector.h"
#include "myopenglwidget.h"
#include "scene.h"
#include "gameobject.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    uiHierarchy(new Ui::Hierarchy)
{
    ui->setupUi(this);

    // Hierarchy
    QWidget *hierarchyWidget = new QWidget();
    uiHierarchy->setupUi(hierarchyWidget);
    hierarchyWidget->show();
    ui->hierarchyDock->setWidget(hierarchyWidget);

    /*/ Render Settings
    QWidget *renderingWidget = new QWidget();
    uiRendering->setupUi(renderingWidget);
    //renderingWidget->show();
    ui->renderDock->setWidget(renderingWidget);*/

    Inspector* inspector = new Inspector();
    ui->inspectorDock->setWidget(inspector);

    //QMainWindow::tabifyDockWidget(ui->inspectorDock,ui->renderDock);
    //ui->inspectorDock->show();
    inspector->show();

    // Scene
    ui->openGLWidget->scene = scene = new Scene(this);

    // Hide OpenGLWidget
    ui->openGLWidget->setHidden(true);

    //Hierarchy Buttons Connexions
    connect(uiHierarchy->addEntityButton, SIGNAL(clicked()), this, SLOT(addEntityButtonClicked()));
    connect(uiHierarchy->removeEntityButton, SIGNAL(clicked()), this, SLOT(removeEntityButtonClicked()));

    //Menu Bar Connexions
    connect(ui->actionNewScene, SIGNAL(triggered()), this, SLOT(newScene()));
    connect(ui->actionOpenScene, SIGNAL(triggered()), this, SLOT(openScene()));
    connect(ui->actionSaveScene, SIGNAL(triggered()), this, SLOT(saveScene()));
    connect(ui->actionReadme, SIGNAL(triggered()), this, SLOT(openReadme()));
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete uiHierarchy;
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    QRect display_section = ui->centralWidget->geometry();
    //QRect display_section()
/*
    std::cout << "Rect { ";
    std::cout << display_section.x();
    std::cout << ", ";
    std::cout << display_section.y();
    std::cout << ", ";
    std::cout << display_section.width();
    std::cout << ", ";
    std::cout << display_section.height();
    std::cout << " } " << std::endl;
*/
    scene->Draw(this, display_section);
}

void MainWindow::openScene()
{
    std::cout << "Open scene" << std::endl;
}

void MainWindow::saveScene()
{
    std::cout << "Save scene" << std::endl;
}

void MainWindow::newScene()
{
    std::cout << "New scene" << std::endl;
}

void MainWindow::openReadme()
{
    std::cout << "Open readme" << std::endl;
}

void MainWindow::addEntityButtonClicked()
{
    GameObject* go = scene->AddEntity(uiHierarchy->newEntityName->text());
    QListWidgetItem *item = new QListWidgetItem(go->name);
    item->setData(Qt::UserRole,go->id);
    uiHierarchy->listWidget->addItem(item);
}

void MainWindow::removeEntityButtonClicked()
{
    if(uiHierarchy->listWidget->currentItem())
    {
        QVariant v = uiHierarchy->listWidget->currentItem()->data(Qt::UserRole);
        uint id = v.value<uint>();
        scene->RemoveEntity(id);

        uiHierarchy->listWidget->takeItem(uiHierarchy->listWidget->currentRow());
    }
}
