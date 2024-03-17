/* 6. Write a C program to find HCF (Highest Common Factor) (GCD) of two numbers. */
#include<stdio.h>
int main()
{
    int a,b,c,d,f,hcf;
    printf("Enter two number:");
    scanf("%d%d",&a,&c);
    f=a>c?c:a;
    for(b=2;b<=f;b++)
    {
        if(a%b==0 && c%b==0)
        {
            hcf=b;
        }
    }
    printf("HCF=%d",hcf);
}
