#ifndef COMPRECTTRANSFORM_H
#define COMPRECTTRANSFORM_H

#include "component.h"

class CompRectTransform : public Component
{
public:
    CompRectTransform(GameObject* gameobject = nullptr, float p_x = 0, float p_y = 0, float s_x = 1.0f, float s_y = 1.0f);

public:
    float pos_x = 0;
    float pos_y = 0;
    float scale_x = 1.0f;
    float scale_y = 1.0f;
};

#endif // COMPRECTTRANSFORM_H
