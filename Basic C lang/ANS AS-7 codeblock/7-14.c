/* 14. Write a C program to print all Strong numbers between 1 to n.
[Example: Strong number - 145 = 1! + 4! + 5! ] */
#include <stdio.h>
#include <math.h>
void main()
{
   int a=1,n,b,sum=0,factorial=1,d;
   printf("Value of n till which the STRONG NUMBERS are to be found:");
   scanf("%d", &n);
   while(a<=n)
   {
       d=a;
       sum=0;
       while (a>0)
       {
           b=a%10;
           factorial=1;
           while (b>0)
           {
               factorial=factorial*b;
               b-=1;
           }
           a=a/10;
           sum=sum+factorial;
       }
       if (d==sum)
       {
           printf("%d \n",d);
       }
       a=d+1;
   }
   printf("are STRONG NUMBERS between 1 and %d. \n",n);
}
