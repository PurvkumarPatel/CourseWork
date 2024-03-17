/* 8. Write a C program to find maximum between three numbers using ternary/conditional operator. */
#include<stdio.h>
void main()
{
    int a,b,c,t,max;
    printf("enter 3 numbers\n");
    scanf("%d%d%d",&a,&b,&c);
    t=a>b?a:b;
    max=t>c?t:c;
    printf("\nmax value is %d",max);
}
