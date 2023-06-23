#include <stdio.h>
#include "circle.h"
#define PI 3.1415926535897932384626433832795;

static int Circle_draw_(Shape const *const me, int x0, int y0);
static int Circle_area_(Shape const *const me);

void Circle_ctor(Circle *const me, int x, int y, int r, int color)
{
    static struct VirtualTable vTbl = {
        &Circle_area_,
        &Circle_draw_};
    me->radius = r;
    me->centerX = r + x;
    me->centerY = r + y;
    Shape_ctor(&me->super, x, y, color);
    me->super.vPtr = &vTbl;
}
/* Getters*/
int Circle_getR(Circle *const me)
{
    return me->radius;
}

/* Declare and define virtual functions to override base version*/

static int Circle_draw_(Shape const *const me, int x0, int y0)
{

    Circle const *const me_ = (Circle const *)me;
    int x = me_->centerX;
    int y = me_->centerY;
    int r = me_->radius;
    int result = ((x0 - x) * (x0 - x)/2 + (y0 - y) * (y0 - y) < r * r);
    return result;
}
static int Circle_area_(Shape const *const me)
{
    Circle const *const me_ = (Circle const *)me;
    printf("calculating area with indexes(%d,%d)",me->x,me->y);
    double r = (double)(me_->radius);
    int result = (int)r * r *PI;
    return result;
}