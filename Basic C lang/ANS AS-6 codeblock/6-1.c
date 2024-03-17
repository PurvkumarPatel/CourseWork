/* 1. Given the radius of a circle, write a C program to compute and display its area.
 Use a symbolic constant to define the pi value. */
#include<stdio.h>
#define PI 3.14
void main()
{
    float area , r;
    printf("Enter the radius of the circle :\n");
    scanf("%f",&r);
    area = PI * r * r;
    printf("The area of the circle with radius %0.2f is %.4f", r , area);
}
