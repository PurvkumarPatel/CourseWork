/* 2. Write a C program to print all Armstrong numbers between given interval using functions. */
#include<stdio.h>
#include<math.h>
int check(long long int n)
{
    long long int x,n1,r=0,sum,i,dig;
    printf("Enter from the number:");
    scanf("%lld",&x);

    for(i=n;i>=x;i--)
    {
        dig = log10(i) +1 ;
        sum = 0;
        for(n1=i; n1>0; n1 /=10)
          {
            r=n1%10;
            sum=sum+(pow(r,dig));
          }
          if(i==sum)
          {
           printf("Number %lld is Armstrong Number \n",i);
          }
    }
}
void main()
{
    long long int n;
    printf("Enter the number:");
    scanf("%lld",&n);
    check(n);
}
