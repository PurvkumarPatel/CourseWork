/* 2. Write a C program to count number of digits in a number using do…while loop. */
#include <stdio.h>

void main(){

    int num,count=0;
    printf("enter a number:\n");
    scanf("%d",&num);

    do
    {
        count++;
        num = num/10;
    }while(num != 0);

    printf("digits = %d", count);
}
