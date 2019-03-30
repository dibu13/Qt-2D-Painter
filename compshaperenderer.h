#ifndef COMPSHAPERENDERER_H
#define COMPSHAPERENDERER_H

#include "component.h"
#include <QPainter>

enum SHAPE : uint
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

    void Save(QDataStream& stream) override;
    void Load(QDataStream& stream) override;

public:
    SHAPE shape = CIRCLE;
    float size = 50.0f;
    QColor fill_color;
    QColor stroke_color;
    double stroke_thickness = 4;
    int stroke_style = 1; // 1-5
};

#endif // COMPSHAPERENDERER_H
