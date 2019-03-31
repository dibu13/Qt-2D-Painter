#include "compshaperenderer.h"
#include "gameobject.h"
#include "comprecttransform.h"
#include "iostream"

CompShapeRenderer::CompShapeRenderer(GameObject* gameobject) :
    Component (gameobject, SHAPE_RENDERER),
    stroke_style(Qt::SolidLine)
{
    fill_color = Qt::red;
    stroke_color = Qt::black;
}

void CompShapeRenderer::Draw(QPainter& painter, QRect display_section, bool selected)
{
    painter.setPen(QPen(stroke_color, stroke_thickness, Qt::PenStyle(stroke_style)));
    painter.setBrush(QBrush(fill_color));

    CompRectTransform* t = gameobject->transform;

    switch (shape)
    {
    case CIRCLE:
    {
        painter.drawEllipse(t->pos_x + display_section.x() + stroke_thickness - 1,
                            t->pos_y + display_section.y() + stroke_thickness - 1,
                            t->scale_x * size, t->scale_y * size);
        break;
    }
    case RECT:
    {
        painter.drawRect(t->pos_x + display_section.x() + stroke_thickness - 1,
                         t->pos_y + display_section.y() + stroke_thickness - 1,
                         t->scale_x * size, t->scale_y * size);
        break;
    }
    }
}

void CompShapeRenderer::Save(QDataStream& out)
{
    out << shape;
    out << size;
    out << fill_color;
    out << stroke_color;
    out << stroke_thickness;
    out << stroke_style;

}

void CompShapeRenderer::Load(QDataStream& in)
{
    uint type;
    in >> type;
    shape = SHAPE(type);

    in >> size;
    in >> fill_color;
    in >> stroke_color;
    in >> stroke_thickness;
    in >> stroke_style;

    std::string strokes[5] = { "SolidLine", "DashLine", "DotLine", "DashDotLine", "DashDotDotLine" };

    std::cout << "Shape(" << (type == 0 ? "Circle" : "Rect")<< ","
              << size << ","
              << fill_color.name().toStdString() << ","
              << stroke_color.name().toStdString() << ","
              << stroke_thickness << ","
              << strokes[stroke_style] << ")";
}
