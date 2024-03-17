/* 12. Write a program to print the transpose of a 3*3 matrix. */
#include<stdio.h>
void main()
{
  int num1, num2;
  printf("Please Input the order of the Matrix : ");
  scanf("%d %d",&num1,&num2);
  int Matrix[num1][num2];
  int Matrix_Transpose[num2][num1];
  for(int i = 0; i < num1; i++)
  {
    for(int j = 0; j < num2; j++)
    {
      printf("Please Input the element of %d Row and %d Columb of Matrix : ",i + 1,j + 1);
      scanf("%d",&Matrix[i][j]);
      Matrix_Transpose[j][i] = Matrix[i][j];
    }
  }
  printf("\nMatrix : \n");
  for(int i = 0; i < num1; i++)
  {
    printf("|");
    for(int j =0; j < num2; j++)
    {
      printf("%d ",Matrix[i][j]);
    }
    printf("|");
    printf("\n");
  }
  printf("\nMatrix Transpose : \n");
  for(int i = 0; i < num2; i++)
  {
    printf("|");
    for(int j = 0; j < num1; j++)
    {
      printf("%d ",Matrix_Transpose[i][j]);
    }
    printf("|");
    printf("\n");
  }
}
