#include <stdio.h>
#include <math.h>
#include "../include/triangle.h"

// Virtual function prototypes
static int Triangle_draw_(Shape const *const me, double x0, double y0);
static double Triangle_area_(Shape const *const me);

// Triangle constructor
void Triangle_ctor(Triangle *const me, double x, double y, double w, double h, int color)
{
    // Set up the virtual table for Triangle
    static struct VirtualTable vTbl = {
        &Triangle_area_,
        &Triangle_draw_};

    // Initialize Triangle-specific properties
    me->width = w;
    me->height = h;

    // Call the base Shape constructor to initialize common properties
    Shape_ctor(&me->super, x, y, color);

    // Override the virtual table pointer with Triangle's virtual table
    me->super.vPtr = &vTbl;
}

/* Getters */
double Triangle_getW(Triangle *const me)
{
    return me->width;
}

double Triangle_getH(Triangle *const me)
{
    return me->height;
}

/* Define virtual functions to override base versions */

// Implementation of Triangle's virtual function to draw the Triangle
static int Triangle_draw_(Shape const *const me, double x0, double y0)
{
    // Downcast the Shape pointer to Triangle pointer
    Triangle const *const me_ = (Triangle const *)me;

    // Store local variables for readability
    double w = me_->width;
    double h = me_->height;
    double x = me->x;
    double y = me->y;

    // Check if the current point (x0, y0) is within the Triangle's boundaries
    // using the mathematical representation of the Triangle's three sides
    return ((y0 <= y + h) && (y0 + (2.0 * h / w) * x0 >= y + (2.0 * h / w) * (x + w / 2.0)) && (y0 - (2.0 * h / w) * x0 >= y - (2.0 * h / w) * (x + w / 2.0)));
}

// Implementation of Triangle's virtual function to calculate the Triangle's area
static double Triangle_area_(Shape const *const me)
{
    // Downcast the Shape pointer to Triangle pointer
    Triangle const *const me_ = (Triangle const *)me;

    // Triangle area formula: (base * height) / 2
    return me_->width * me_->height / 2.0;
}
