/* 4. Write a C program to check whether a number is even or odd using switch case. */
#include<stdio.h>
int main()
{
    int a;
    printf("Enter any number:");
    scanf("%d",&a);

    switch(a%2)
    {
        case 0 :
        printf("Number is Even");
        break;
        default:
        printf("Number is Odd");

    }
}
