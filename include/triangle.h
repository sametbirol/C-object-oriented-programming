#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../include/shape.h"

// Define the Triangle struct, which inherits from the Shape struct
typedef struct
{
    Shape super;   // Base Shape struct to support inheritance
    double width;  // Width of the triangle
    double height; // Height of the triangle
} Triangle;

// Function prototypes

// Triangle constructor: Initializes the Triangle object with given properties
void Triangle_ctor(Triangle *const me, double x, double y, double w, double h, int color);

// Getters for width and height of the Triangle
double Triangle_getW(Triangle *const me);
double Triangle_getH(Triangle *const me);

#endif
