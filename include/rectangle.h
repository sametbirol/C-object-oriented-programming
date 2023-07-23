#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../include/shape.h"

// Define the Rectangle struct, which inherits from the Shape struct
typedef struct
{
    Shape super;   // Base Shape struct to support inheritance
    double width;  // Width of the rectangle
    double height; // Height of the rectangle
} Rectangle;

// Function prototypes

// Rectangle constructor: Initializes the Rectangle object with given properties
void Rectangle_ctor(Rectangle *const me, double x, double y, double w, double h, int color);

// Getters for width and height of the Rectangle
double Rectangle_getW(Rectangle *const me);
double Rectangle_getH(Rectangle *const me);

#endif
