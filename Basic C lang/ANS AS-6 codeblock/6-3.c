/* 3. Write a C program to demonstrate working of arithmetic operators. */
#include <stdio.h>

void main()
{
    int a, b;

    printf("Enter the first number a: ");
    scanf("%d",&a);
    printf("Enter the second number b: ");
    scanf("%d",&b);
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n", a % b);
}
