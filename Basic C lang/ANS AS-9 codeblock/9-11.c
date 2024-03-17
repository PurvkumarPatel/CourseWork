/* 11. For the flip function in Q-10, verify that flip(flip(N,k), k)= N. */
#include <stdio.h>
#include<math.h>
int flip(int num,int flipnum);
void main()
{
   int n1,flipnum;
   printf("Enter the number :");
   scanf("%d",&n1);
   printf("Enter the number of last digits to be flipped :");
   scanf("%d",&flipnum);
   if (flip(flip(n1,flipnum),flipnum) == n1)
   {
       printf("Therefore VERIFIED:-");
       printf("flip(flip(%d,%d),%d) = %d. \n",n1,flipnum,flipnum,n1);
   }
}
int flip(int num,int flipnum)
{
   int revnum=0,dig=0,finalnum=0,rnum=0;
   int ndig=log10(num);
   int a= pow(10,flipnum);
   rnum=num % a;
   while (rnum>0)
   {
       dig=rnum%10;
       revnum=revnum*10+dig;
       rnum=rnum/10;
   }
   finalnum=(num-(num % a))+revnum;
   return finalnum;
}
