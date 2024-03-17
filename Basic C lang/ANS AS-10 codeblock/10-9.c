/* 9. Write c program to generate 10 elements in Fibonacci series and store them in 1-D array. */
#include<stdio.h>
void main()
{
  int array[10];
   array[0] = 0;
   array[1] = 1;
   for(int i = 2; i < 10; i++)
   {
     array[i] = array[i - 1] + array[i - 2];
   }
   for(int i = 0; i< 10; i++)
   printf("array[%d] = %d\n",i,array[i]);
}
