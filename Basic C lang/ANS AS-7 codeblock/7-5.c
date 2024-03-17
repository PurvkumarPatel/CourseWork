/* 5. Write a C program to print all ASCII character with their values. */
#include <stdio.h>

void main(){

    char ch;
    int i;

    for(i=0 ; i<256 ; i++)
    {
        ch = (char)i;
        printf("%c chracter with value :- %d\n" , ch , i);
    }
}
