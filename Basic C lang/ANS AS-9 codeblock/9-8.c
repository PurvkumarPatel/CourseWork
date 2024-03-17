/* 8. Write a C program to find sum of digits of a given number using recursion. */
#include <stdio.h>
int digsum1(int n);
void main()
{
   int n1;
   printf("Enter the number whose sum of digits is to be calculated :");
   scanf("%d",&n1);
   printf("SUM OF ALL THE DIGITS OF %d IS %d.",n1,digsum1(n1));
}
int digsum1(int n)
{
    int sum=0,dig1=0;
    if (n>=1)
    {
        dig1=n%10;
        sum=dig1+(digsum1(n/10));
    }
    else
    {
        return 0;
    }
    return sum;
}
