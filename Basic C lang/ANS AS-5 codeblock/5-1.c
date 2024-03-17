/* 1. Write a C program to read number between 1 to 10 and print it in words using switch case. */
#include <stdio.h>
int main()
{
    int n;
    printf("Enter number between 1 to 10 to print in words: ");
    scanf("%d", &n);

        switch(n)
        {
            case 1:
                printf("One ");
                break;
            case 2:
                printf("Two ");
                break;
            case 3:
                printf("Three ");
                break;
            case 4:
                printf("Four ");
                break;
            case 5:
                printf("Five ");
                break;
            case 6:
                printf("Six ");
                break;
            case 7:
                printf("Seven ");
                break;
            case 8:
                printf("Eight ");
                break;
            case 9:
                printf("Nine ");
                break;
            case 10:
                printf("Ten");
                break;
            default :
                printf("Invalid Input");
        }
    return 0;
}
