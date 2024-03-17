/* 9. Write a C program to print Fibonacci series up to n terms.
[Fibonacci series is a series of numbers where the current number is the sum of previous two terms.
 For Example: 0, 1, 1, 2, 3, 5, 8, 13, 21, ... , (n-1th + n-2th)] */
#include <stdio.h>
void main()
{
   int a=0,b=1,term1,n,c=1;
   printf("Enter the number of terms of Fibonacci Series:");
   scanf("%d", &n);
   printf("FIBONACCI SERIES: \n 0 1 ");
   while (c<(n-1))
   {
      term1=a+b;
      printf("%d ",term1);
      a=b;
      b=term1;
      c+=1;
   }
}
