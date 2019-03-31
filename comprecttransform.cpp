#include "comprecttransform.h"
#include "gameobject.h"
#include <iostream>

CompRectTransform::CompRectTransform(GameObject* gameobject, float p_x, float p_y, float s_x, float s_y) :
    Component (gameobject, RECT_TRANSFORM),
    pos_x(p_x),
    pos_y(p_y),
    scale_x(s_x),
    scale_y(s_y)
{
}

void CompRectTransform::Save(QDataStream& out)
{
    out << pos_x;
    out << pos_y;
    out << scale_x;
    out << scale_y;
}

void CompRectTransform::Load(QDataStream& in)
{
    in >> pos_x;
    in >> pos_y;
    in >> scale_x;
    in >> scale_y;

    std::cout << "Rect("
              << pos_x << ","
              << pos_y << ","
              << scale_x << ","
              << scale_y << ")";
}
