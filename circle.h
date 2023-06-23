#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

typedef struct
{
    Shape super;
    int radius;
    int centerX;
    int centerY;
} Circle;

void Circle_ctor(Circle *const me, int x, int y, int r, int color);
int Circle_getR(Circle *const me);

#endif