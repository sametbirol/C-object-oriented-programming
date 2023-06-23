#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

typedef struct
{
    Shape super;
    double width;
    double height;
} Rectangle;

void Rectangle_ctor(Rectangle *const me, double x, double y, double w, double h,int color);
double Rectangle_getW(Rectangle *const me);
double Rectangle_getH(Rectangle *const me);

#endif