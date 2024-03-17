/* 8. Write a C program to illustrate various mathematical functions. (Include 5 math functions). */
#include <stdio.h>
#include <math.h>
int main()
{
    printf("1. pow function\n\n");
    int base, power;
    printf("Enter value of base\n");
    scanf("%d", &base);
    printf("Enter value of power\n");
    scanf("%d", &power);
    printf("%f", pow(base, power));

    printf("\n2. Square root (sqrt) function\n");
    float a;
    printf("Enter a positive number\n");
    scanf("%f", &a);
    printf("Square root is %f\n", sqrt(a));

    printf("Enter a negative value of a\n");
    scanf("%f", &a);

    printf("\n3. fabs function\n");
    printf("fabs(a) = %f", fabs(a));

    printf("\n4. ceil function\n");
    printf("ceil(a) = %f", ceil(a));

    printf("\n5. floor function\n");
    printf("floor(a) = %f", floor(a));
    scanf("%f", &a);

    return 0;
}
