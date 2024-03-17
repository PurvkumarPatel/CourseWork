/* 4. Write a C program to enter a number and print its reverse. */
#include <stdio.h>

void main()
{
    int num,rev=0;
    printf("enter a number:\n");
    scanf("%d" , &num);

    for(; num != 0 ;num/=10)
    {
        rev*=10;
        rev = rev + num%10;
    }
    printf("reverse number = %d ." , rev);
}
