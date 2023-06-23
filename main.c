#include <stdio.h>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"

int main()
{
    Rectangle r1, r2,r3,r4;
    // Shape s1,s2;
    Circle c1,c2,c3,c4;
    Shape const * shapes[] = {
        &c1.super,
        &r4.super,
        &c2.super,
        &c4.super,
        &c3.super,
        &r2.super,
        &r3.super,
        &r1.super,
    };

    Shape const* s ;
    Rectangle_ctor(&r1,0,0,80,10,30);//31 and 32 is oclor code for drawing
    Rectangle_ctor(&r2,15,12,61,15,31);
    Rectangle_ctor(&r3,21,31,41,10,32);
    Rectangle_ctor(&r4,22,12,21,20,33);
    Circle_ctor(&c1,50,5,5,34);
    Circle_ctor(&c2,100,10,5,35);
    Circle_ctor(&c3,120,15,5,30);
    Circle_ctor(&c4,150,20,5,36);
    printf("Area of rectangle r1 : %d\n",Shape_area(&r1.super));
    printf("Area of rectangle r2 : %d\n",Shape_area(&r2.super));
    printf("Area of circle c1 : %d\n",Shape_area(&c1.super));
    printf("Area of circle c2 : %d\n",Shape_area(&c2.super));

    s = largestShape(shapes , sizeof(shapes)/sizeof(shapes[0]));

    printf("The largest shape is at the point (%d,%d)\n",
        Shape_getX(s),Shape_getY(s));

    // 
    drawAllShapes(shapes , sizeof(shapes)/sizeof(shapes[0]));
    // Rectangle amaha, mamaha;
    // Shape aloha, maloha;
    // Shape_ctor(&aloha, 10, 20);
    // Shape_ctor(&maloha, 11, 21);

    // Rectangle_ctor(&amaha, 10, 20, 33, 44);
    // Rectangle_ctor(&mamaha, 0, 0, 2, 4);
    // Shape_area(amaha);
}
