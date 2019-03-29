#include "comprecttransform.h"
#include "gameobject.h"

CompRectTransform::CompRectTransform(GameObject* gameobject, float p_x, float p_y, float s_x, float s_y) :
    Component (gameobject, RECT_TRANSFORM),
    pos_x(p_x),
    pos_y(p_y),
    scale_x(s_x),
    scale_y(s_y)
{
}
