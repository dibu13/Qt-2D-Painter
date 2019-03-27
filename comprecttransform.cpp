#include "comprecttransform.h"
#include "gameobject.h"

CompRectTransform::CompRectTransform(GameObject* gameobject, double p_x, double p_y, double s_x, double s_y) :
    Component (gameobject, RECT_TRANSFORM),
    pos_x(p_x),
    pos_y(p_y),
    scale_x(s_x),
    scale_y(s_y)
{
}