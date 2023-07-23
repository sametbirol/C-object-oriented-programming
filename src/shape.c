#include <stdio.h>
#include <assert.h>
#include "../include/shape.h"

// Virtual function prototypes
static double Shape_area_(Shape const *const me);
static int Shape_draw_(Shape const *const me, double x0, double y0);

// Shape constructor
void Shape_ctor(Shape *const me, double x, double y, int c)
{
    // Set up the virtual table
    static struct VirtualTable vtbl = {
        &Shape_area_,
        &Shape_draw_};
    me->vPtr = &vtbl;

    // Initialize the Shape properties
    me->color = c;
    me->x = x;
    me->y = y;

    /* print out x and y for validation*/
    printf("Shape_ctor getter access => x: %.2lf, y: %.2lf \n", Shape_getX(me), Shape_getY(me));
}

/* Getters */
double Shape_getX(Shape const *const me)
{
    return me->x;
}

double Shape_getY(Shape const *const me)
{
    return me->y;
}

/* Virtual functions which are essentially for asserting calls */

// Default implementation for the virtual function Shape_area_
static double Shape_area_(Shape const *const me)
{
    assert(0); // Purely virtual function should never be called
    return 0;
}

// Default implementation for the virtual function Shape_draw_
static int Shape_draw_(Shape const *const me, double x0, double y0)
{
    assert(0); // Purely virtual function should never be called
    return 0;  // Avoid compiler error for return type
}

// Function to find the largest shape based on area
Shape const *largestShape(Shape const *shapes[], int nShapes)
{
    Shape const *s = (Shape *)0;
    int max = 0.0;
    int i;
    for (i = 0; i < nShapes; i++)
    {
        int area = Shape_area(shapes[i]);
        if (area > max)
        {
            s = shapes[i];
            max = area;
        }
    }
    return s; // The largest shape among all
}

// Function to draw all shapes on a 150x40 pixels canvas
void drawAllShapes(Shape const *shapes[], int nShapes)
{
    printf("The canvas is going to be 150x40 pixels size\n");
    for (double j = 0.0; j < 50.0; j += 1.0)
    {
        for (double i = 0.0; i < 150.0; i += 1.0)
        {
            int count = 0;
            for (int n = 0; n < nShapes; n++)
            {
                if (Shape_draw(shapes[n], i, j))
                {
                    printf("\033[1;%dmI", shapes[n]->color);
                    count++;
                    break;
                }
            }
            if (count == 0)
            {
                printf("\033[1;30mI"); // Default color (black) if no shape is drawn at the (i, j) position
            }
        }
        printf("\n");
    }
}
