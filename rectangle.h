#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

typedef struct
{
    Shape super;
    int width;
    int height;
} Rectangle;

void Rectangle_ctor(Rectangle *const me, int x, int y, int w, int h,int color);
int Rectangle_getW(Rectangle *const me);
int Rectangle_getH(Rectangle *const me);

#endif