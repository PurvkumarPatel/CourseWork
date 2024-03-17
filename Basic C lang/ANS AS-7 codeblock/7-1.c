/* 1. Write a C program to do the following task:
a) Accept any 2 positive numbers, say n1 and n2. Assume n1 > n2.
b) Print all even numbers that lie between n1 and n2.
c) Print the sum of all even numbers between n1 and n2. */
#include <stdio.h>
void main()
{
    int n1,n2,sum=0;
    printf("ENTER N1:");
    scanf("%d",&n1);
    printf("ENTER N2:");
    scanf("%d",&n2);
    if (n1>n2)
    {
        for (n2;n2<=n1;n2++)
        {
            if (n2%2==0)
            {
                printf("%d\t",n2);
                sum+=n2;
            }
        }
        printf("\nTHE SUM OF THE NUMBERS IS:%d",sum);
        printf("\n");
    }
    else
    {
        printf("WRONG INPUT\n");
    }
}
