/* 6. Write a C program to find sum of all natural numbers between 1 to n using recursion. */
#include <stdio.h>
int sum1(int n);
void main()
{
   int n1;
   printf("Enter the number till which sum of natural numbers will be calculated :");
   scanf("%d",&n1);
   printf("SUM OF NATURAL NUMBERS FROM 1 TO %d IS %d",n1,sum1(n1));

}
int sum1(int n)
{
    int sum=0;
    if (n>=1)
    {
        sum=n+(sum1(n-1));
    }
    else
    {
        return 0;
    }
    return sum;
}
