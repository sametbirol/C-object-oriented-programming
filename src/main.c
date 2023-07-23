#include <stdio.h>
#include "../include/shape.h"
#include "../include/rectangle.h"
#include "../include/circle.h"
#include "../include/triangle.h"

int main()
{
    // Create instances of Rectangle, Circle, and Triangle
    Rectangle r1, r2, r3, r4;
    Circle c1, c2, c3, c4;
    Triangle t1, t2;
    Shape const *s;

    // Array of shapes (pointers to Shape const)
    Shape const *shapes[] = {
        &t1.super,
        &t2.super,
        &c1.super,
        &r4.super,
        &c2.super,
        &c4.super,
        &c3.super,
        &r2.super,
        &r3.super,
        &r1.super,
    };

    // Initialize the shapes with their respective properties
    Rectangle_ctor(&r1, 0, 0, 80, 10, 34); // (Rectangele const, x, y, width, height, colorCode)
    Rectangle_ctor(&r2, 15, 12, 61, 15, 31);
    Rectangle_ctor(&r3, 21, 31, 41, 10, 32);
    Rectangle_ctor(&r4, 22, 12, 21, 20, 33);

    Circle_ctor(&c1, 50, 5, 5, 34); // (Circle const, x, y, radius, colorCode)
    Circle_ctor(&c2, 100, 10, 5, 35);
    Circle_ctor(&c3, 120, 15, 5, 32);
    Circle_ctor(&c4, 150, 20, 5, 36);

    Triangle_ctor(&t1, 0, 0, 24, 10, 35); // (Triangle const, x1, y1, x2, y2, colorCode)
    Triangle_ctor(&t2, 30, 25, 10, 15, 35);

    // Print the area of each shape
    printf("Area of rectangle r1 : %.3lf\n", Shape_area(&r1.super));
    printf("Area of rectangle r2 : %.3lf\n", Shape_area(&r2.super));
    printf("Area of rectangle r3 : %.3lf\n", Shape_area(&r3.super));
    printf("Area of rectangle r4 : %.3lf\n", Shape_area(&r4.super));
    printf("Area of circle c1 : %.3lf\n", Shape_area(&c1.super));
    printf("Area of circle c2 : %.3lf\n", Shape_area(&c2.super));
    printf("Area of circle c3 : %.3lf\n", Shape_area(&c3.super));
    printf("Area of circle c4 : %.3lf\n", Shape_area(&c4.super));
    printf("Area of triangle t1 : %.3lf\n", Shape_area(&t1.super));
    printf("Area of triangle t2 : %.3lf\n", Shape_area(&t2.super));

    // Find and print the largest shape's coordinates
    s = largestShape(shapes, sizeof(shapes) / sizeof(shapes[0]));
    printf("The largest shape is at the point (%.3lf,%.3lf)\n",
           Shape_getX(s), Shape_getY(s));

    // Draw all the shapes
    drawAllShapes(shapes, sizeof(shapes) / sizeof(shapes[0]));
}
