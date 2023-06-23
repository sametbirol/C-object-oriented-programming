#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

typedef struct
{
    Shape super;
    double radius;
    double centerX;
    double centerY;
} Circle;

void Circle_ctor(Circle *const me, double x, double y, double r, int color);
double Circle_getR(Circle *const me);

#endif