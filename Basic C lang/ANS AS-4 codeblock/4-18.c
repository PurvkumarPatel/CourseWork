/* 18. C program to evaluate the arithmetic expression ((a + b / c * d - e) * (f - g)),
 if (a + b / c * d - e) and (f-g) are not equal to zero.
Read the values a, b, c, d, e, f, g from the standard input device. */

#include<stdio.h>
int main()
{
    float a,b,c,d,e,f,g,r;
    printf("Enter Number respectively a,b,c,d,e,f,g:");
    scanf("%f%f%f%f%f%f%f", &a,&b,&c,&d,&e,&f,&g);

    r=((a+b/c*d-e)*(f-g));

    if((a+b/c*d-e)==0)
    {
    if ((f-g)==0)
    {
        printf("Invalid Input ");
    }
    else
    {
        printf("Arithmetic Expression is=%f",r);
    }
    }
    else
        printf("Arithmetic Expression is=%f",r);
}
