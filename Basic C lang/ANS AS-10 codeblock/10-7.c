/* 7. Write a program to add and subtraction corresponding elements of two 1-D array and store in third array. */
#include<stdio.h>
void main()
{
  int n;
  printf("Please Input the number of elements in any one array : ");
  scanf("%d",&n);
  int array1[n];
  int array2[n];
  int Add_array[n];
  int Subtract_array[n];
  printf("\nPlease Input all the %d elements of array 1 continuously : ",n);
  for(int i = 0; i < n; i++)
  scanf("%d",&array1[i]);
  printf("\nPlease Input all the %d elements of array 2 continuously : ",n);
  for(int i = 0; i < n; i++)
  scanf("%d",&array2[i]);
  for(int i = 0; i < n; i++)
  {
    Add_array[i] = array1[i] + array2[i];
    Subtract_array[i] = array1[i] - array2[i];
  }
  for(int i = 0; i < n; i++)
  {
    printf("Add_array[%d] = %d Subtract_array[%d] = %d\n",i,Add_array[i],i,Subtract_array[i]);
  }
}
