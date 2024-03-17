/* 6. Write a program in C to count the frequency of ages (19, 21, 20, 19, 20, 20) stored in an array.
 (Expected output: frequency of age 19= 2, 21=1, 20=3) */
#include<stdio.h>
void main()
{
  int Student_Number = 0;
  printf("Please Input the Number of Students in Class : ");
  scanf("%d",&Student_Number);
  int Student_Age[Student_Number];
  printf("Please Enter the age of all the %d Students Continuously : ",Student_Number);
  for(int i = 0; i < Student_Number; i++)
  {
    printf("\nAge = ");
    scanf("%d ",&Student_Age[i]);
  }
  for(int i = 0; i < Student_Number ; i++)
  {
    for(int j = i - 1; j >= 0; j --)
    {
      if(Student_Age[i] == Student_Age[j])
      goto Continue;
    }
    if(i == Student_Number)
    {
      Continue :
      continue;
    }
    int Count = 1;
    for(int j = i + 1; j < Student_Number; j++)
    {
      if(Student_Age[i] == Student_Age[j])
      {
        Count++;
      }
    }
    printf("\nFrequency of Age %d = %d",Student_Age[i],Count);
  }
}
