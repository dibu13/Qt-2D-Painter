#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_rendering.h"
#include "ui_hierarchy.h"
#include "inspector.h"
#include "myopenglwidget.h"
#include "scene.h"
#include "gameobject.h"
#include <iostream>
#include <QColorDialog>
#include <QDesktopServices>
#include <QUrl>

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

    inspector = new Inspector(this);
    ui->inspectorDock->setWidget(inspector);

    //QMainWindow::tabifyDockWidget(ui->inspectorDock,ui->renderDock);
    //ui->inspectorDock->show();
    inspector->show();

    // Scene
    ui->openGLWidget->scene = scene = new Scene(this);
    newScene();
    setWindowTitle(scene->name);

    QColor c = scene->background_color;
    uiHierarchy->backGroundColorButton->setStyleSheet(QString("background-color: rgb(%1, %2, %3)").arg(c.red()).arg(c.green()).arg(c.blue()));

    // Hide OpenGLWidget
    ui->openGLWidget->setHidden(true);
    //ui->menuBar->setVisible(false);

    //Hierarchy Connexions
    connect(uiHierarchy->addEntityButton, SIGNAL(clicked()), this, SLOT(addEntityButtonClicked()));
    connect(uiHierarchy->removeEntityButton, SIGNAL(clicked()), this, SLOT(removeEntityButtonClicked()));

    connect(uiHierarchy->listWidget, SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)), this, SLOT(changeSelectedGemaObject()));

    //Menu Bar Connexions
    connect(ui->actionNewScene, SIGNAL(triggered()), this, SLOT(newScene()));
    connect(ui->actionOpenScene, SIGNAL(triggered()), this, SLOT(openScene()));
    connect(ui->actionSaveScene, SIGNAL(triggered()), this, SLOT(saveScene()));
    connect(ui->actionReadme, SIGNAL(triggered()), this, SLOT(openReadme()));
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));

    connect(uiHierarchy->backGroundColorButton, SIGNAL(clicked()), this, SLOT(changeBackGroundColor()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete uiHierarchy;
    delete inspector;

    delete scene;
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    QRect display_section = ui->centralWidget->geometry();
    update(display_section);
    scene->Draw(this, display_section);
}

void MainWindow::openScene()
{
    std::cout << "Open scene" << std::endl;
    scene->Load();
    setWindowTitle(scene->name);
    uiHierarchy->listWidget->clear();

    foreach (GameObject* go, scene->gameobjects)
    {
        QListWidgetItem *item = new QListWidgetItem(go->name);
        item->setData(Qt::UserRole,go->id);
        uiHierarchy->listWidget->addItem(item);
    }

    inspector->selectedGameObject = (scene->selected >= 0 ? scene->gameobjects[scene->selected] : nullptr);
    inspector->reloadInspector();
    repaint();
}

void MainWindow::saveScene()
{
    std::cout << "Save scene" << std::endl;
    scene->Save();
}

void MainWindow::newScene()
{
    std::cout << "New scene" << std::endl;
    scene->Clear();
    setWindowTitle(scene->name);
    uiHierarchy->listWidget->clear();
    inspector->selectedGameObject = nullptr;
    inspector->reloadInspector();
    repaint();
}

void MainWindow::openReadme()
{
    std::cout << "Open readme" << std::endl;
    QDesktopServices::openUrl(QUrl("https://github.com/dibu13/Qt-2D-Painter"));
}

void MainWindow::addEntityButtonClicked()
{
    if (!uiHierarchy->newEntityName->text().isEmpty())
    {
        GameObject* go = scene->AddEntity(uiHierarchy->newEntityName->text());
        QListWidgetItem *item = new QListWidgetItem(go->name);
        item->setData(Qt::UserRole,go->id);
        uiHierarchy->listWidget->addItem(item);

        scene->selected = scene->gameobjects.count() - 1;
        inspector->selectedGameObject = go;
        inspector->reloadInspector();
        repaint();
    }
}

void MainWindow::removeEntityButtonClicked()
{
    if(uiHierarchy->listWidget->currentItem())
    {
        QVariant v = uiHierarchy->listWidget->currentItem()->data(Qt::UserRole);
        uiHierarchy->listWidget->takeItem(uiHierarchy->listWidget->currentRow());

        uint id = v.value<uint>();
        scene->RemoveEntity(id);
        scene->selected--;

        if (scene->gameobjects.isEmpty())
        {
            scene->selected = -1;
            inspector->selectedGameObject = nullptr;
            inspector->reloadInspector();
        }
    }

    repaint();
}

void MainWindow::changeSelectedGemaObject()
{
    if (uiHierarchy->listWidget->currentItem())
    {
        QVariant v = uiHierarchy->listWidget->currentItem()->data(Qt::UserRole);
        uint id = v.value<uint>();

        for (int i = 0; i < scene->gameobjects.count(); i++)
        {
            GameObject* go = scene->gameobjects[i];

            if(id == go->id)
            {
                scene->selected = i;
                inspector->selectedGameObject = go;
                inspector->reloadInspector();
                return;
            }
        }
    }
}

void MainWindow::changeBackGroundColor()
{
    QColor new_color = QColorDialog::getColor(scene->background_color, this, "Choose color");

    if (new_color.isValid())
    {
        scene->background_color = new_color;
    }
    uiHierarchy->backGroundColorButton->setStyleSheet(QString("background-color: rgb(%1, %2, %3)").arg(scene->background_color.red()).arg(scene->background_color.green()).arg(scene->background_color.blue()));
}
