/* 13. Write a C program to check whether a number is Perfect number or not.
[Perfect number is a positive integer which is equal to the sum of its proper positive divisors.
 Example: 6 is the first perfect number. Proper divisors of 6 are 1, 2, 3]*/
#include <stdio.h>
#include <math.h>
void main()
{
   int a,b=1,sum=0;
   printf("Enter the NUMBER to be checked for PERFECT NUMBER:");
   scanf("%d", &a);
   while (b<a)
   {
       if (a%b==0)
       {
           sum=sum+b;
       }
       b+=1;
   }
   if (sum== a)
   {
       printf("%d is a PERFECT NUMBER.",a);
   }
   else
   {
       printf("%d is NOT a PERFECT NUMBER.",a);
   }
}
