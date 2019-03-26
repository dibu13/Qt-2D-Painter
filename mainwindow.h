#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
class Rendering;
}

class Inspector;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Ui::Rendering *uiRendering;
    Inspector *inspector;

public slots:
    void openScene();
    void saveScene();
    void newScene();
    void openReadme();
};

#endif // MAINWINDOW_H
