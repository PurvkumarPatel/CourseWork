/* 10. Write a program to perform 3*3 matrix addition and matrix subtraction. */
#include<stdio.h>
void main()
{
  int Matrix1[3][3];
  int Matrix2[3][3];
  int Matrix_Addition[3][3];
  int Matrix_Subtraction[3][3];
  int Count = 0;
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      printf("Please Input the Row %d and Columb %d Element of Matrix1 : ",i + 1, j + 1);
      scanf("%d",&Matrix1[i][j]);
      printf("Please Input the Row %d and Columb %dElement of Matrix2 : ",i + 1, j + 1);
      scanf("%d",&Matrix2[i][j]);
      Matrix_Addition[i][j] = Matrix1[i][j] + Matrix2[i][j];
      Matrix_Subtraction[i][j] = Matrix1[i][j] - Matrix2[i][j];
    }
    printf("\n");
  }
  for(int i = 0; i < 3; i++)
  {
    int Count = 0;
    Up :
    printf("|");
    for(int j = 0; j < 3; j++)
    {
      if(Count == 0)
      printf(" %d ",Matrix1[i][j]);
      if(Count == 1)
      printf(" %d ",Matrix2[i][j]);
      if(Count == 2)
      printf(" %d ",Matrix_Addition[i][j]);
    }
    printf("|");
    if(i == 1 && Count == 0)
    printf(" + ");
    if(i == 0 || i == 2)
    printf("   ");
    if(i == 1 && Count == 1)
    printf(" = ");
    Count ++;
    if(Count == 3)
    {
      printf("\n");
      continue;
    }
    else
    goto Up;
  }
  printf("\n\n\n");
  for(int i = 0; i < 3; i++)
  {
    int Count = 0;
    Up1 :
    printf("|");
    for(int j = 0; j < 3; j++)
    {
      if(Count == 0)
      printf(" %d ",Matrix1[i][j]);
      if(Count == 1)
      printf(" %d ",Matrix2[i][j]);
      if(Count == 2)
      printf(" %d ",Matrix_Subtraction[i][j]);
    }
    printf("|");
    if(i == 1 && Count == 0)
    printf(" - ");
    if(i == 0 || i == 2)
    printf("   ");
    if(i == 1 && Count == 1)
    printf(" = ");
    Count ++;
    if(Count == 3)
    {
      printf("\n");
      continue;
    }
    else
    goto Up1;
  }
}
