  /* 3. C program to find maximum between two numbers. */
#include <stdio.h>

int main()
{
    int num1, num2;
    printf("Enter two unequal numbers: ");
    scanf("%d%d", &num1, &num2);

    if(num1 > num2)
        printf("%d is maximum", num1);
    else
        printf("%d is maximum", num2);

    return 0;
}
