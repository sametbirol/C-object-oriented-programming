#include <stdio.h>
#include <math.h>
#include "triangle.h"

static int Triangle_draw_(Shape const *const me, double x0, double y0);
static double Triangle_area_(Shape const *const me);

void Triangle_ctor(Triangle *const me, double x, double y, double w, double h, int color)
{
    
    static struct VirtualTable vTbl = {
        &Triangle_area_,
        &Triangle_draw_};
    me->width = w;
    me->height = h;
    Shape_ctor(&me->super, x, y, color);
    me->super.vPtr = &vTbl;
}
/* Getters*/
double Triangle_getW(Triangle *const me)
{
    return me->width;
}
double Triangle_getH(Triangle *const me)
{
    return me->height;
}

/* Declare and define virtual functions to override base version*/

static int Triangle_draw_(Shape const *const me, double x0, double y0)
{
    //downcast
    Triangle const *const me_ = (Triangle const *)me;
    //store local variables
    double w = me_->width;
    double h = me_->height;
    double x = me->x;
    double y = me->y;
    // y1  = ((y3-y2)/(x3-x2)) x1 + c;
    // y3 = y;
    // y2 = y + height;
    // x3 = x + width/2;
    // x2 = x;
    // m1 = - 2 * height / width;
    // m2 = - m1;
    // y + 2*h/w*(x + w/2) = c
    // y1 - m1 * x1 >= c; line1
    // y1 + m1 * x1 >= c; line2
    // y1 < y + height; line3
    // check if the current point is in between these three lines
    return ((y0 <= y + h) 
                    && (y0 + (2.0 * h / w) * x0 >= y + (2.0 * h / w) * (x + w / 2.0)) 
                    && (y0 - (2.0 * h / w) * x0 >= y - (2.0 * h / w) * (x + w / 2.0)));
}
static double Triangle_area_(Shape const *const me)
{
    //downcast
    Triangle const *const me_ = (Triangle const *)me;
    //triangle area formula
    return me_->width * me_->height / 2.0;
}