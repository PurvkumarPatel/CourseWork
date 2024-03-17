/* 10. Implement a function named as flip; which will take a number as input and flip its last N digits.
For example flip(123, 2)= 132 ; (here N=2) flip(12345,3)= 12543 (here N=3). */
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
   printf("flip(%d,%d)= %d",n1,flipnum,flip(n1,flipnum));
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
