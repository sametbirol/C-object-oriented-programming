#include <stdio.h>
#include "circle.h"
#include "constants.h"

static int Circle_draw_(Shape const *const me, double x0, double y0);
static double Circle_area_(Shape const *const me);

void Circle_ctor(Circle *const me, double x, double y, double r, int color)
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
double Circle_getR(Circle *const me)
{
    return me->radius;
}

/* Declare and define virtual functions to override base version*/

static int Circle_draw_(Shape const *const me, double x0, double y0)
{

    Circle const *const me_ = (Circle const *)me;
    double x = me_->centerX;
    double y = me_->centerY;
    double r = me_->radius;
    int result = ((x0 - x) * (x0 - x) + (y0 - y) * (y0 - y) < r * r);
    return result;
}
static double Circle_area_(Shape const *const me)
{
    Circle const *const me_ = (Circle const *)me;
    // printf("calculating area of object centered at point(%lf,%lf)\n",me_->centerX,me_->centerY);
    return me_->radius * me_->radius *PI;;
}