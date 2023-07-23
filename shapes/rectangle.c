#include <stdio.h>
#include "../include/rectangle.h"

// Virtual function prototypes of Rectangle
static int Rectangle_draw_(Shape const *const me, double x0, double y0);
static double Rectangle_area_(Shape const *const me);

// Rectangle constructor
void Rectangle_ctor(Rectangle *const me, double x, double y, double w, double h, int c)
{
    // Set up the virtual table for Rectangle
    static struct VirtualTable vtbl = {
        &Rectangle_area_,
        &Rectangle_draw_};

    // Initialize Rectangle-specific properties
    me->width = w;
    me->height = h;

    // Call the base Shape constructor to initialize common properties
    Shape_ctor(&me->super, x, y, c);

    // Override the virtual table pointer with Rectangle's virtual table
    me->super.vPtr = &vtbl;
}

/* Getters for width and height */
double Rectangle_getW(Rectangle *const me)
{
    return me->width;
}

double Rectangle_getH(Rectangle *const me)
{
    return me->height;
}

/* Define virtual functions to override base versions */

// Implementation of Rectangle's virtual function to draw the Rectangle
static int Rectangle_draw_(Shape const *const me, double x0, double y0)
{
    // Downcast the Shape pointer to Rectangle pointer
    Rectangle const *const me_ = (Rectangle const *)me;

    // Check if the current point (x0, y0) is within the Rectangle's boundaries
    int vertical = (x0 >= me->x && x0 < me->x + me_->width);
    int horizontal = (y0 >= me->y && y0 < me->y + me_->height);
    return (vertical && horizontal);
}

// Implementation of Rectangle's virtual function to calculate the Rectangle's area
static double Rectangle_area_(Shape const *const me)
{
    // Downcast the Shape pointer to Rectangle pointer
    Rectangle const *const me_ = (Rectangle const *)me;

    // Rectangle area formula: width * height
    return me_->width * me_->height;
}
