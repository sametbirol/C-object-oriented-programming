#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"

typedef struct
{
    Shape super;
    double width;
    double height;
} Triangle;

void Triangle_ctor(Triangle *const me, double x, double y, double w, double h,int color);
double Triangle_getW(Triangle *const me);
double Triangle_getH(Triangle *const me);

#endif