#ifndef CIRCLE_H
#define CIRCLE_H

#include "../include/shape.h"

// Define the Circle struct, which inherits from the Shape struct
typedef struct
{
    Shape super;    // Base Shape struct to support inheritance
    double radius;  // Radius of the circle
    double centerX; // x-coordinate of the center of the circle
    double centerY; // y-coordinate of the center of the circle
} Circle;

// Function prototypes

// Circle constructor: Initializes the Circle object with given properties
void Circle_ctor(Circle *const me, double x, double y, double r, int color);

// Getter for the radius of the Circle
double Circle_getR(Circle *const me);

#endif
