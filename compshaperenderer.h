#ifndef COMPSHAPERENDERER_H
#define COMPSHAPERENDERER_H

#include "component.h"
#include <QPainter>

enum SHAPE
{
    CIRCLE,
    RECT
};

class QPaintDevice;

class CompShapeRenderer : public Component
{
public:
    CompShapeRenderer(GameObject* gameobject = nullptr);

    void Draw(QPainter& painter, QRect display_section, bool selected = false);

public:
    SHAPE shape = CIRCLE;
    float size = 50.0f;
    QColor fill_color;
    QColor stroke_color;
    float stroke_thickness = 1;
    int stroke_style = 1; // 1-5
};

#endif // COMPSHAPERENDERER_H
