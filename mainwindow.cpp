#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_rendering.h"
#include "ui_hierarchy.h"
#include "inspector.h"
#include "myopenglwidget.h"
#include "scene.h"
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

    // Inspector
    /*QWidget *inspectorWidget = new QWidget();
    uiInspector->setupUi(inspectorWidget);
    inspectorWidget->show();*/

    Inspector* inspector = new Inspector();
    inspector->show();
    ui->inspectorDock->setWidget(inspector);

    /*/ Render Settings
    QWidget *renderingWidget = new QWidget();
    uiRendering->setupUi(renderingWidget);
    renderingWidget->show();
    ui->renderingDock->setWidget(renderingWidget);
    QMainWindow::tabifyDockWidget(ui->inspectorDock,ui->renderingDock);*/

    //Menu Bar Connexions
    connect(ui->actionNewScene, SIGNAL(triggered()), this, SLOT(newScene()));
    connect(ui->actionOpenScene, SIGNAL(triggered()), this, SLOT(openScene()));
    connect(ui->actionSaveScene, SIGNAL(triggered()), this, SLOT(saveScene()));
    connect(ui->actionReadme, SIGNAL(triggered()), this, SLOT(openReadme()));
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));

    // Scene
    ui->openGLWidget->scene = scene = new Scene(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete uiHierarchy;
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
