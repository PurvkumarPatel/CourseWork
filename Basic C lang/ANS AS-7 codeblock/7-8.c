/* 8. Write a C program to print all prime numbers between 1 to n along with their sum. */
#include <stdio.h>
#include <math.h>
void main()
{
   int n,primecase1=0,sum=0;
   printf("Enter the number till which PRIME NUMBERS are to be found :");
   scanf("%d", &n);
   for (int i=2;i<=n;i+=1)
   {
       for (int j=2;j<i;j+=1)
       {
           if (i%j==0)
           {
               primecase1=1;
               break;
           }
       }
       if (primecase1==0)
       {
           printf("%d \n",i);
           sum=sum+i;
       }
       primecase1=0;
   }
   printf("are the PRIME NUMBERS between 1 and %d. \n",n);
   printf("The sum of All the PRIME NUMBERS between 1 and %d is %d. \n",n,sum);
}
