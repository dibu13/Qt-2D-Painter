#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
class Hierarchy;
class Rendering;
}

class Scene;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    Ui::MainWindow *ui;
    Ui::Hierarchy *uiHierarchy;
    Ui::Rendering *uiRendering;

    Scene* scene = nullptr;

public slots:
    void openScene();
    void saveScene();
    void newScene();
    void openReadme();

    void addEntityButtonClicked();
    void removeEntityButtonClicked();
};

#endif // MAINWINDOW_H
