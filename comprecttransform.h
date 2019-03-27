#ifndef COMPRECTTRANSFORM_H
#define COMPRECTTRANSFORM_H

#include "component.h"

class CompRectTransform : public Component
{
public:
    CompRectTransform(GameObject* gameobject = nullptr, double p_x = 0, double p_y = 0, double s_x = 0, double s_y = 0);

public:
    double pos_x = 0;
    double pos_y = 0;
    double scale_x = 0;
    double scale_y = 0;
};

#endif // COMPRECTTRANSFORM_H
