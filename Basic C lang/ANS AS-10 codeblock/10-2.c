/* 2. Write a Program to Search an element in array. */
#include<stdio.h>
void main()
{
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int b = 0;
  printf("Please Input an number we will make you know that is it in array or not : ");
  scanf("%d",&b);
  for(int i = 0; i < 10; i++)
  {
    if(a[i] == b)
    {
      printf("\nNumber is Present in array");
      break;
    }
   else
    {

     }continue;
  }
  if(b>10)
printf("number is not present in array");
}
