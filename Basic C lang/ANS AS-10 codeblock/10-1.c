/* 1. Write a program to insert 5 elements into an array and print the elements of the array. */
#include<stdio.h>
void main()
{
  int array[5];
  printf("Please Print five elements continuously : ");
  for(int i = 0; i < 5; i++)
  scanf("%d",&array[i]);
  printf("\n");
  for(int i = 0; i < 5; i++)
  printf("%d ",array[i]);
}
