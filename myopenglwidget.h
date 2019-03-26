#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QOpenGLWidget>

namespace Ui {
class MyOpenGLWidget;
}

class MyOpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit MyOpenGLWidget(QWidget *parent = nullptr);

    // OpenGL functions
    void initializeGL() override;
    //void resizeGL(int width, int height) override;
    void paintGL() override;

signals:

public slots:

};

#endif // MYOPENGLWIDGET_H
