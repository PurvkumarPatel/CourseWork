/* 8. Write c program to sort 1-D array in ascending and descending order. */
#include<stdio.h>
void main()
{
  int n = 0;
  printf("Please Input the number of elements in 1D array : ");
  scanf("%d",&n);
  int array[n];
  printf("Please Input all the %d elements of 1D array Continuously : ",n);
  for(int i = 0; i < n; i++)
  scanf("%d",&array[i]);
  for(int i = 0; i < n - 1; i++)
  {
    for(int j = i + 1; j < n; j++)
    {
    int Exchange = 0;
    if(array[j] > array[i])
    {
      Exchange = array[j];
      array[j] = array[i];
      array[i] = Exchange;
    }
    else
    continue;
    }
  }
  for(int i = 0; i < n ; i++)
  printf("a[%d] = %d\n",i,array[i]);
}
