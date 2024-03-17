 /* 5. C program to find maximum between three numbers */
#include <stdio.h>
int main()
{
    int num1, num2, num3, max;
    printf("Enter three unequal numbers: ");
    scanf("%d%d%d", &num1, &num2, &num3);

    if(num1 > num2)
    {
        if(num1 > num3)
        {
            max = num1;
        }
        else
        {
            max = num3;
        }
    }
    else
    {
        if(num2 > num3)
        {
            max = num2;
        }
        else
        {
            max = num3;
        }
    }
    printf("Maximum among all three numbers = %d", max);

    return 0;
}
