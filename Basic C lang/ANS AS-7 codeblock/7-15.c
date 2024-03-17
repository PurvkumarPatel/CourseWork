/* 15. Write a C program to calculate the sum of the square of each digit of the given number.
 [Example: 4534  42 + 52 + 32 + 42 = 66] */
#include <stdio.h>
#include <math.h>
void main()
{
   int a,b,sum=0;
   printf("Enter the NUMBER:");
   scanf("%d", &a);
   printf("SUM OF SQUARE OF EACH DIGIT OF %d IS:- \n",a);
   while (a>0)
   {
       b=a%10;
       a=a/10;
       sum=sum+(b*b);
       printf("%d + ",(b*b));
   }
   printf("=%d.",sum);
}
