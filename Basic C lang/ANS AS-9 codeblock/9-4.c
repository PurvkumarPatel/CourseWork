/* 4. A function g is defined as follows  g = ax3 – bx2 + cx – d if x > k
= 0 if x = k    = - ax3 + bx2 – cx + d if x < k
Display the value of g. Accept a, b, c, d, k and x from user. */
#include <stdio.h>
int polynomial1(int a,int b,int c,int d,int k,int x);
void main()
{
   int a,b,c,d,k,x;
   printf("Enter the coefficient of x^3 :");
   scanf("%d",&a);
   printf("Enter the coefficient of x^2 :");
   scanf("%d",&b);
   printf("Enter the coefficient of x :");
   scanf("%d",&c);
   printf("Enter the constant term of the equation :");
   scanf("%d",&d);
   printf("Enter the value of k constrain for the equation :");
   scanf("%d",&k);
   printf("Enter the value of x to be substituted in the equation :");
   scanf("%d",&x);
   printf("THE VALUE OF g FOR THE GIVEN VALUES OF a,b,c,d,k AND x IS : %d",polynomial1(a,b,c,d,k,x));
}
int polynomial1(int a,int b,int c,int d,int k,int x)
{
    int g=0;
    if (x > k)
    {
        g=((a*(x*x*x))-(b*(x*x))+(c*x)-d);
    }
    else if (x < k)
    {
        g=(-(a*(x*x*x))+(b*(x*x))-(c*x)+d);
    }
    else
    {
        g=0;
    }
    return g;
}
