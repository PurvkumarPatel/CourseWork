/* 9. Write a C program to check whether a number is even or odd using ternary operator. */
#include<stdio.h>

main()
{
   int n;

   printf("Enter an integer\n");
   scanf("%d",&n);

   n%2 == 0 ? printf("Even number\n") : printf("Odd number\n");

   return 0;
}
