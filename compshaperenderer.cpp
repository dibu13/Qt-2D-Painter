#include "compshaperenderer.h"
#include "gameobject.h"
#include "comprecttransform.h"
#include "iostream"

CompShapeRenderer::CompShapeRenderer(GameObject* gameobject) :
    Component (gameobject, SHAPE_RENDERER)
{
    fill_color = Qt::red;
    stroke_color = Qt::black;
}

void CompShapeRenderer::Draw(QPainter& painter, QRect display_section, bool selected)
{
    CompRectTransform* t = gameobject->transform;

    display_section.setRect(
                display_section.x() + static_cast<int>(t->pos_x),
                display_section.y() + static_cast<int>(t->pos_y),
                static_cast<int>(t->scale_x * size),
                static_cast<int>(t->scale_y * size));

    if(stroke_style == 0 || stroke_thickness <= 0)
    {
        painter.setPen(QPen(stroke_color, stroke_thickness, Qt::PenStyle(0)));
    }
    else
    {
        display_section.setX(display_section.x() + static_cast<int>(stroke_thickness) - 1);
        display_section.setY(display_section.y() + static_cast<int>(stroke_thickness) - 1);

        painter.setPen(QPen(stroke_color, stroke_thickness, Qt::PenStyle(stroke_style)));
    }


    painter.setBrush(QBrush(fill_color));

    switch (shape)
    {
    case CIRCLE:
    {
        painter.drawEllipse(display_section); break;
    }
    case RECT:
    {
        painter.drawRect(display_section); break;
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

    std::string strokes[6] = {"None", "SolidLine", "DashLine", "DotLine", "DashDotLine", "DashDotDotLine" };

    std::cout << "Shape(" << (type == 0 ? "Circle" : "Rect")<< ","
              << size << ","
              << fill_color.name().toStdString() << ","
              << stroke_color.name().toStdString() << ","
              << stroke_thickness << ","
              << strokes[stroke_style] << ")";
}
