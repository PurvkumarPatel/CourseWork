/* 16. Write a C program that accepts 2 four-digit positive integers then calculates and displays the sum of the product of each pair of digits occupying the same position in the two numbers.
[Example: if the first number is 3445 and the second number is 4534 then the output will be 64. 3 * 4 + 4 * 5 + 4 * 3 + 5 * 4 = 64]*/
#include <stdio.h>

int main()
{
    int n1, n2, rem1, rem2, sum = 0;
    printf("Enter Two Four digit Positive Numbers : \n");
    scanf("%d %d", &n1, &n2);

    while (n1 > 0 && n2 > 0)
    {
        rem1 = n1 % 10;
        rem2 = n2 % 10;
        sum += rem1 * rem2;

        n1 /= 10;
        n2 /= 10;
    }
    printf("The sum of the product of each pair of digits occupying the same position in the two numbers: %d ", sum);

    return 0;
}
