
/* 4. Write a Program to find the largest and smallest element in Array */
#include<stdio.h>
void main()
{
  printf("How big array do you want : ");
  int n;
  scanf("%d",&n);
  int array[n];
  printf("Please input the values in array : ");
  for(int i = 0; i<n; i++)
  {
  printf("Please Enter the value of %d element of array : ",i + 1);
  scanf("%d",&array[i]);
  }
  int a = 0;
  for(int i = 1; i < n - 1; i++)
  {
    if(array[0] > array[i])
    {
      a = array[0];
      array[0] = array[i];
      array[i] = a;
    }
  }
  for(int i = 2; i < n - 1; i++)
  {
    if(array[i] > array[1])
    {
      a = array[1];
      array[1] = array[i];
      array[i] = a;
    }
  }
  printf("\nLargest number in array = %d\n",array[1]);
  printf("Smallest number in array = %d",array[0]);
}
