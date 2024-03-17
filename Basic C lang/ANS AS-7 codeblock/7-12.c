/* 12. Write a C program to check whether given number is Armstrong number or Not.
 [Example: Armstrong number - 135 = 13 + 33 + 53 ] */
#include <stdio.h>
#include <math.h>
void main()
{
   int a,b,sum=0,c;
   printf("Enter the NUMBER:");
   scanf("%d", &a);
   c=a;
   while (a>0)
   {
       b=a%10;
       a=a/10;
       sum=sum+(b*b*b);
   }
   if (c==sum)
   {
       printf("%d is  an ARMSTRONG NUMBER. \n",c);
   }
   else
   {
       printf("%d is NOT an ARMSTRONG NUMBER. \n",c);
   }
}
