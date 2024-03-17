/* 3. Write a C function that takes a positive integer as input and returns the leading digit in its decimal representation.
 For example, the leading digit of 234567 is 2. */
#include <stdio.h>
int leaddig1(int a);
void main()
{
   int a;
   while (1)
   {
       printf("Enter a POSITIVE INTEGER :");
       scanf("%d",&a);
       if (a>0)
       {
           break;
       }
       else
       {
           printf("INVALID INPUT!Enter again:-\n");
       }
   }
   printf("THE LEADING DIGIT OF %d IS : ",a);

   printf("%d ",leaddig1(a));
}
int leaddig1(int a)
{
    int b=0;
    while (a>0)
    {
        b=a%10;
        a=a/10;
    }
    return b;
}
