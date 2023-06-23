#include "rectangle.h"
#include <stdio.h>

/* virtual function prototypes of Rectangle*/
static int Rectangle_draw_(Shape const *const me, double x0, double y0);
static double Rectangle_area_(Shape const *const me);

void Rectangle_ctor(Rectangle *const me, double x, double y, double w, double h, int c)
{
    /* Let's call Shape class constructor */
    /* then define our child class attributes*/
    static struct VirtualTable vtbl = {
        &Rectangle_area_,
        &Rectangle_draw_};

    me->width = w;
    me->height = h;
    // printf("Rectangle_ctor getter access => w: %lf, h: %lf  ", Rectangle_getW(me), Rectangle_getH(me));
    Shape_ctor(&me->super, x, y, c);
    me->super.vPtr = &vtbl;
}

/*Getters for width and height*/
double Rectangle_getW(Rectangle *const me)
{
    return me->width;
}
double Rectangle_getH(Rectangle *const me)
{
    return me->height;
}

/* Declare and define virtual functions to override base version*/

static int Rectangle_draw_(Shape const *const me, double x0, double y0)
{
    Rectangle const *const me_ = (Rectangle const *)me;
    int vertical = (x0 >= me->x && x0 < me->x + me_->width);
    int horizontal = (y0 >= me->y && y0 < me->y + me_->height);
    return (vertical && horizontal);
}
static double Rectangle_area_(Shape const *const me)
{
    Rectangle const *const me_ = (Rectangle const *)me;
    return me_->width * me_->height;
}