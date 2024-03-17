/* 5. Write a C program to check whether a number is positive, negative or zero using switch case. */
#include<stdio.h>
int main()
{
    int a;
    printf("Enter any Number:");
    scanf("%d",&a);

     switch (a > 0)
    {
        case 1:
            printf("%d is positive.", a);
        break;

        case 0:
            switch (a < 0)
            {
                case 1:
                    printf("%d is negative.", a);
                    break;
                case 0:
                    printf("%d is zero.", a);
                    break;
            }
        break;
    }
}
