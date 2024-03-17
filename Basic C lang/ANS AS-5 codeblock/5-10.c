/* 10. Write a C program to check whether character is an alphabet or not using ternary operator. */
#include <stdio.h>
int main()
{
    char ch;

    printf("Enter any character: ");
    scanf("%c",&ch);

    if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
        printf("The entered character %c is an Alphabet",ch);
    else
        printf("The entered character %c is not an Alphabet",ch);

    return 0;
}
