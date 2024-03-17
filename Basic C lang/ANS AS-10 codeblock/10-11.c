/* 11. Write a program to perform matrix multiplication by checking the compatibility. */
#include<stdio.h>
void main()
{
  int num1, num2, num3, num4;
  printf("Please give the order of two matrix : ");
  scanf("%d %d %d %d",&num1,&num2,&num3,&num4);
  printf("Matrix1 order is %d X %d and Matrix2 order is %d X %d\n",num1,num2,num3,num4);
  if(num2 == num3)
  {
    int Matrix1[num1][num2];
    int Matrix2[num3][num4];
    int Mul[num1][num4];
    for(int i = 0; i < num1; i++)
    {
      for(int j = 0; j < num2; j++)
      {
      printf("Input the element which is %d Row and %d Columb of Matrix1: ",i + 1,j + 1);
      scanf("%d",&Matrix1[i][j]);
      }
    }
    for(int i = 0; i < num3; i++)
    {
      for(int j = 0; j < num4; j++)
      {
      printf("Input the element which is %d Row and %d Columb of Matrix2 : ",(i + 1),(j + 1));
      scanf("%d",&Matrix2[i][j]);
      }
    }
    for(int i = 0; i < num1; i++)
    {
      for(int j = 0; j < num4; j++)
      {
        Mul[i][j] = 0;
        for(int k = 0; k < num2 ; k++)
        Mul[i][j] = Matrix1[i][k]*Matrix2[k][j] + Mul[i][j] ;
      }
    }
    printf("Matrix1 : \n");
    for(int i = 0; i < num1; i++)
    {
      printf("|");
      for(int j = 0; j < num2; j++)
      {
       printf(" %d ",Matrix1[i][j]);
      }
      printf("|");
      printf("\n");
    }
    printf("\n");
    printf("Matrix2 : \n");
    for(int i = 0; i < num3; i++)
    {
      printf("|");
      for(int j = 0; j < num4; j++)
      {
      printf(" %d ",Matrix2[i][j]);
      }
      printf("|");
      printf("\n");
    }
    printf("\n");
    printf("Multiplication of Two Matrix : \n");
    for(int i = 0; i < num1; i++)
    {
      printf("|");
      for(int j = 0; j < num4; j++)
      {
        printf(" %d ",Mul[i][j]);
      }
      printf("|");
      printf("\n");
    }
  }
  else
  printf("multiplication is not possible");
}
