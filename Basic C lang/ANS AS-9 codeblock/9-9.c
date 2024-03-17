/* 9. Write a C program to find LCM of two numbers using recursion. */
#include <stdio.h>
int lcm(int a, int b);
int main()
{
    int a,b,LCM;
    printf("Enter any TWO number for LCM :");
    scanf("%d %d",&a,&b);

    if(a>b)
        LCM=lcm(b,a);
    else
        LCM=lcm(a,b);
    printf("LCM of %d and %d is = %d ",a,b,LCM);
    return 0;
}
int lcm(int a,int b)
{
    static int f=0;
    f+=b;
    if((f%a==0) && (f%b==0))
    {
        return f;
    }
    else
        {
            return lcm(a,b);
        }
}
