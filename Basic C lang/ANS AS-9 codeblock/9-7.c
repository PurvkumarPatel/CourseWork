/* 7. Write a C program to check whether a number is palindrome or not using recursion. */
#include <stdio.h>
#include <math.h>
int reverse1(int num1);
void main()
{
   int n1,r1;
   printf("Enter the number to be checked :");
   scanf("%d",&n1);
   r1=reverse1(n1);
   printf("%d \n",r1);
   if (n1 == r1)
   {
       printf("%d is an PALINDROME. \n",n1);
   }
   else
   {
       printf("%d is NOT an PALINDROME. \n",n1);
   }
}
int reverse1(int num)
{
   int revnum=0,dig=0;
   int ndig=log10(num);
   if (num>0)
   {
       dig=num%10;
       revnum=dig*pow(10,ndig)+reverse1(num/10);
   }
   else
   {
       return num;
   }
   return revnum;
}
