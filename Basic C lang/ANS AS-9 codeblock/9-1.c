/* 1. Write a C program to check whether a number is even or odd using functions. */
#include <stdio.h>
void oddeven1(int a);
void main()
{
   int a;
   printf("Enter the number to be checked :");
   scanf("%d",&a);
   oddeven1(a);
}
void oddeven1(int a)
{
    if (a%2==0)
    {
        printf("%d is an EVEN number. \n",a);
    }
    else
    {
        printf("%d is an ODD number. \n",a);
    }
}
