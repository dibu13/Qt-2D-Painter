#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QOpenGLWidget>
#include <iostream>

namespace Ui {
class MyOpenGLWidget;
}

class Scene;

class MyOpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit MyOpenGLWidget(QWidget *parent = nullptr);

    // OpenGL functions
    void initializeGL() override;
    void paintGL() override;
    //void resizeGL(int width, int height) override;

public:

    Scene* scene = nullptr;

signals:

public slots:

};

#endif // MYOPENGLWIDGET_H
