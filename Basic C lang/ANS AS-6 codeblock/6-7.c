/* 7. Write a C program to demonstrate working of increment and decrement operators. */
#include <stdio.h>
int main()
{
    int a;
    printf("Enter value of a\n");
    scanf("%d", &a);
    printf("a = %d\n", a);
    printf("when a++ -> %d\n", a++);
    printf("now value of a is %d\n", a);
    printf("a = %d\n", a);
    printf("when a-- -> %d\n", a--);
    printf("now value of a is %d\n", a);
    printf("a = %d\n", a);
    printf("when ++a -> %d\n", ++a);
    printf("now value of a is %d\n", a);
    printf("a = %d\n", a);
    printf("when --a -> %d\n", --a);
    printf("now value of a is %d\n", a);
    return 0;
}
