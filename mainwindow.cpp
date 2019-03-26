#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_rendering.h"
#include "inspector.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    uiRendering(new Ui::Rendering)
{
    ui->setupUi(this);

    QMainWindow::tabifyDockWidget(ui->inspectorDock,ui->renderingDock);

    //Create the rendering widget...
    QWidget *renderingWidget = new QWidget();
    uiRendering->setupUi(renderingWidget);
    renderingWidget->show();

    //... and add it to the rendering dock
    ui->renderingDock->setWidget(renderingWidget);

    //Create the inspector widget and add it to the inspector
    inspector = new Inspector();
    ui->inspectorDock->setWidget(inspector);

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
    delete uiRendering;
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
