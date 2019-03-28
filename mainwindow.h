#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
class Hierarchy;
}

class Scene;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Ui::Hierarchy *uiHierarchy;

    Scene* scene = nullptr;

public slots:
    void openScene();
    void saveScene();
    void newScene();
    void openReadme();

    void updateHierarchy();
};

#endif // MAINWINDOW_H
