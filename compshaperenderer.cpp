#include "compshaperenderer.h"
#include "gameobject.h"
#include "comprecttransform.h"
//#include <QPainter>
//#include <QtCore>

/*
 * Qt::SolidLine = 1
 * Qt::DashLine = 2
 * Qt::DotLine = 3
 * Qt::DashDotLine = 4
 * Qt::DashDotDotLine = 5
*/

CompShapeRenderer::CompShapeRenderer(GameObject* gameobject) :
    Component (gameobject, SHAPE_RENDERER)
{
    stroke_style = Qt::DashDotDotLine;
}

void CompShapeRenderer::Draw(QPainter& painter, QRect display_section, bool selected)
{
    CompRectTransform* t = gameobject->transform;

    switch (shape)
    {
    case CIRCLE:
    {
        painter.drawEllipse(t->pos_x + display_section.x(),
                            t->pos_y + display_section.y(),
                            t->scale_x * size, t->scale_y * size);
        break;
    }
    case RECT:
    {
        painter.drawRect(t->pos_x + display_section.x(),
                         t->pos_y + display_section.y(),
                         t->scale_x * size, t->scale_y * size);
        break;
    }
    }
}
