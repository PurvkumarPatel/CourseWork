/* 3. Write a C program to read alphabet and check whether an alphabet is vowel or consonant using switch case. */
#include<stdio.h>
void main()
{
    char alpha;
    printf("Enter the any alphabet:");
    scanf("%c",&alpha);

    switch(alpha)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        printf("Alphabet is vowel");
        break;
        default :
        printf("Alphabet is consonant");
    }
}
