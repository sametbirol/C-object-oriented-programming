#include <stdio.h>
#include <assert.h>
#include "shape.h"

static int Shape_area_(Shape const *const me);
static int Shape_draw_(Shape const *const me, int x0, int y0);

void Shape_ctor(Shape *const me, int x, int y, int c)
{
    static struct VirtualTable vtbl = {
        &Shape_area_,
        &Shape_draw_
    };
    me->vPtr = &vtbl;
    me->color = c;
    me->x = x;
    me->y = y;
    /* print out x and y for validation*/
    printf("Shape_ctor getter access => x: %d, y: %d \n", Shape_getX(me), Shape_getY(me));
}

/* Getters */
int Shape_getX(Shape const *const me)
{
    return me->x;
}
int Shape_getY(Shape const *const me)
{
    return me->y;
}

/*virtual functions which are essentially for asserting calls*/
static int Shape_area_(Shape const *const me)
{
    assert(0);
    return 0;
}
static int Shape_draw_(Shape const *const me, int x0, int y0)
{
    assert(0); // purely virtual functions should never be called
    return 0;  // avoid compiler error for return type
}

Shape const *largestShape(Shape const *shapes[], int nShapes)
{
    Shape const *s = (Shape *)0;
    int max = 0;
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
    return s; // The largest of them all
}
// Shape const *shapes[], int nShapes
//print each shape with its own color and create depth
void drawAllShapes(Shape const *shapes[], int nShapes)
{
    printf("The canvas is going to be 44x195 pixels size\n");
    for (int j = 0; j < 44; j++)
    {
        for (int i = 0; i < 195; i++)
        {
            int count = 0;
            for(int n = 0; n < nShapes; n++ ){
                if(Shape_draw(shapes[n],i,j)){
                    printf("\033[1;%dm*",shapes[n]->color);
                    count++;
                    break;
                }
                
            }
            if (count == 0){
                printf("\033[1;0m*");
            }
        }
        printf("\n");
    }
}