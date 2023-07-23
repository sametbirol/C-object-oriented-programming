#ifndef SHAPE_H
#define SHAPE_H

// Forward declaration of the VirtualTable struct
struct VirtualTable;

// Define the Shape struct, which serves as the base class for various shapes
typedef struct Shape
{
    /* Declare a pointer for the vTbl struct to store base functions */
    struct VirtualTable const *vPtr;

    // Basic attributes of the shape
    int color; // Color code of the shape
    double x;  // x-coordinate of the shape
    double y;  // y-coordinate of the shape
} Shape;

// Initialize base function pointers using the VirtualTable struct
struct VirtualTable
{
    double (*area)(Shape const *const me);
    int (*draw)(Shape const *const me, double x0, double y0);
};

// Function prototypes

// Shape constructor: Initializes the Shape object with given properties
void Shape_ctor(Shape *const me, double x, double y, int c);

// Getters for x and y coordinates of the Shape
double Shape_getX(Shape const *const me);
double Shape_getY(Shape const *const me);

// Calculate the area of the Shape using the virtual function pointer
static inline double Shape_area(Shape const *const me)
{
    return (*me->vPtr->area)(me);
}

// Draw the Shape at the specified (x0, y0) coordinates using the virtual function pointer
static inline int Shape_draw(Shape const *const me, double x0, double y0)
{
    return (*me->vPtr->draw)(me, x0, y0);
}

// Generic operations on collections of Shapes

// Find the largest Shape based on area among an array of Shapes
Shape const *largestShape(Shape const *shapes[], int nShapes);

// Draw all Shapes in an array on a canvas
void drawAllShapes(Shape const *shapes[], int nShapes);

#endif
