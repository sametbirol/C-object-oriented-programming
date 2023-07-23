#include <stdio.h>
#include "../include/circle.h"
#include "../include/constants.h"

// Virtual function prototypes of Circle
static int Circle_draw_(Shape const *const me, double x0, double y0);
static double Circle_area_(Shape const *const me);

// Circle constructor
void Circle_ctor(Circle *const me, double x, double y, double r, int color)
{
    // Set up the virtual table for Circle
    static struct VirtualTable vTbl = {
        &Circle_area_,
        &Circle_draw_};

    // Initialize Circle-specific properties
    me->radius = r;
    me->centerX = r + x;
    me->centerY = r + y;

    // Call the base Shape constructor to initialize common properties
    Shape_ctor(&me->super, x, y, color);

    // Override the virtual table pointer with Circle's virtual table
    me->super.vPtr = &vTbl;
}

/* Getter for radius */
double Circle_getR(Circle *const me)
{
    return me->radius;
}

/* Define virtual functions to override base versions */

// Implementation of Circle's virtual function to draw the Circle
static int Circle_draw_(Shape const *const me, double x0, double y0)
{
    // Downcast the Shape pointer to Circle pointer
    Circle const *const me_ = (Circle const *)me;

    // Check if the current point (x0, y0) is inside the Circle's boundary
    double x = me_->centerX;
    double y = me_->centerY;
    double r = me_->radius;
    int result = ((x0 - x) * (x0 - x) + (y0 - y) * (y0 - y) < r * r);
    return result;
}

// Implementation of Circle's virtual function to calculate the Circle's area
static double Circle_area_(Shape const *const me)
{
    // Downcast the Shape pointer to Circle pointer
    Circle const *const me_ = (Circle const *)me;

    // Circle area formula: PI * radius^2
    return me_->radius * me_->radius * PI;
}
