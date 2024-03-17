/* 3. Write a program in C to store the obtained marks (may be float) of five subjects in an array.
Find the sum and average of obtained marks. */
#include<stdio.h>
void main()
{
  float Subject_Marks[5];
  float Average_Marks = 0;
  float Sum_Marks = 0;
  printf("Please Enter the marks scored by student in five subjects : ");
  for(int i = 0; i < 5; i++)
  scanf("%f",&Subject_Marks[i]);
  for(int i = 0; i < 5; i++)
  {
    Sum_Marks = Sum_Marks + Subject_Marks[i];
  }
  Average_Marks = Sum_Marks / 5;
  printf("Sum of Marks = %f\nAverage of Marks = %f",Sum_Marks,Average_Marks);
}
