/* 17. C program that reads four values a,b,c and d from the user and evaluates
the ratio of (a+b) to (c-d) and prints the result, if (c-d) is not equal to zero.*/
#include<stdio.h>
void main()
{
    float a,b,c,d,r;
    printf("Enter four Number respectively a,b,c,d:");
    scanf("%f%f%f%f", &a,&b,&c,&d);

    r=(a+b)/(c-d);
    if(c-d==0)
    {
        printf("Invalid Input denominator=0 ");
    }
    else
    {
        printf("Ratio of (a+b)/(c-d) is=%f",r);
    }
}

