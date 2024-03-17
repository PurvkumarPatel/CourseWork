/* 5. Write a C program to find the sum of the series 1!/1+2!/2+3!/3+4!/4+5!/5 using the function. */
#include <stdio.h>
int fact1(int n);
void series1(int n);
void main()
{
   int n1;
   printf("Enter the number till which pattern is to be calculated :");
   scanf("%d",&n1);
   series1(n1);

}
int fact1(int n)
{
    int factorial1=1,i;
    for (i=1;i<=n;i+=1)
    {
        factorial1*=i;
    }
    return factorial1;
}
void series1(int n)
{
   int a=2,sum=1;
   printf("1!/1 ");
   while (a<=n)
   {
      printf("+ %d!/%d ",a,a);
      sum+=(fact1(a)/a);
      a+=1;
   }
   printf("= %d. \n",sum);
}
