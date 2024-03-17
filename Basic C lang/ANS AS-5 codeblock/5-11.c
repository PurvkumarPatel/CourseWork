/* 11. Write a C program to check whether a number is even or odd using goto statement. */
#include<stdio.h>

void main()
{
    int a;
    printf("Enter any Number:");
    scanf(" %d",&a);

    if(a%2 == 0)
    {
        goto even;
        even:
    printf("Number is Even");
    }
    else
    {
        goto odd;
         odd:
    printf("Number is Odd");
    }
}
