/* Quation 1b */
#include <stdio.h>
void main()
{
   int num1=2,n,sum=1;
   printf("Enter the NUMBER till which SUM of SQUARE is to be calculated :");
   scanf("%d",&n);
   printf("1^2 ");
   while(num1<=n)
   {

      printf("+ %d^2 ",num1);
      sum+=(num1*num1);
      num1+=1;
   }
   printf("= %d.\n",sum);
   printf("This is the SUM of SQUARE all number upto %d.\n",n);
}
