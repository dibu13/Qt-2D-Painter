#ifndef COMPSHAPERENDERER_H
#define COMPSHAPERENDERER_H

#include "component.h"

#include <QColor>

class CompShapeRenderer : public Component
{
public:
    CompShapeRenderer(GameObject* gameobject = nullptr);

    QColor fill_color;
    QColor stroke_color;
};

#endif // COMPSHAPERENDERER_H
