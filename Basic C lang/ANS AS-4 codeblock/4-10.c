/* 10. C program to input month number and print number of days in that month. */
#include <stdio.h>
int main()
{
    int N;
    printf("Enter number of month(1-12):");
    scanf("%d",&N);
    if (N == 1 || N == 3 || N == 5
        || N == 7 || N == 8 || N == 10 || N == 12)
        {
        printf("31 Days.");
        }

    else if (N == 4 || N == 6
             || N == 9 || N == 11)
        {
        printf("30 Days.");
        }

    else if (N == 2)
        {
        printf("28/29 Days.");
        }

    else
        {
        printf("Invalid Month.");
        }

    return 0;
}
