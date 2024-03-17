/* 6. Write a C program to demonstrate working of assignment operators. */
#include <stdio.h>
int main()
{
    printf("ASSIGNMENT OPERATORS\n");
    int a;
    printf("Enter value of a: ");
    scanf("%d", &a);
    int p=a;
    printf("value of a is %d.\n", a);
    a += 1;
    printf("a+=1 now value of a is %d\n", a);
    a=p;
    a-=1;
    printf("a-=1 now value of a is %d\n", a);
    a=p;
    a*=2;
    printf("a*=2 now value of a is %d\n", a);
    a=p;
    a /= 3;
    printf("a/=3 now value of a is %d\n", a);
    a=p;
    a%=4;
    printf("a%%=4 now value of a is %d\n", a);
    return 0;
}
