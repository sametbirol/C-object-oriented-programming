#ifndef SHAPE_H
#define SHAPE_H

struct VirtualTable;

typedef struct Shape
{
    /*Declare a pointer for vTbl struct to store base functions*/
    struct VirtualTable const *vPtr;
    // Basic attributes
    int color;
    int x;
    int y;
} Shape;
/* Initialize base function pointers*/
struct VirtualTable
{
    int (*area)(Shape const *const me);
    int (*draw)(Shape const *const me, int x0, int y0);
};

void Shape_ctor(Shape *const me, int x, int y,int c);

/* Getters */
int Shape_getX(Shape const *const me);
int Shape_getY(Shape const *const me);

/* I don't know what is this*/
static inline int Shape_area(Shape const *const me)
{
    return (*me->vPtr->area)(me);
}

static inline int Shape_draw(Shape const *const me, int x0, int y0)
{
    return (*me->vPtr->draw)(me,x0,y0);
}
/* generic operations on collections of Shapes */
Shape const * largestShape(Shape const *shapes[], int nShapes);
void drawAllShapes(Shape const *shapes[], int nShapes);
// Shape const *shapes[], int nShapes
#endif