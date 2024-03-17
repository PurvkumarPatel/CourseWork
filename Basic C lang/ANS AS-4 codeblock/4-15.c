/* 15. C program to make a simple calculator. */
#include <stdio.h>
float main()
{
   char opt;
    float n1, n2;
    float res;
    printf (" Choose an operator(+, -, *, /) to perform the operation in C Calculator \n ");
    scanf ("%c", &opt);

    printf (" \n Enter the first number: ");
    scanf(" %f", &n1);
    printf (" Enter the second number: ");
    scanf (" %f", &n2);

   if (opt == '/' )
      {
        res=(n1/n2);
        printf (" You have selected: Division\n Your answer is: %f",res);
      }
   else if (opt == '*')
      {
        res=(n1*n2);
        printf (" You have selected: Multiplication\n Your answer is: %f",res);
      }

   else if (opt == '-')
      {
        res=(n1-n2);
        printf (" You have selected: Subtraction\n Your answer is: %f",res);
      }
   else if (opt == '+')
      {
        res=(n1+n2);
        printf (" You have selected: Addition\n Your answer is: %f",res);
      }
   else
      {
        printf (" Something is wrong!! Please check the options ");
      }
    return 0;
}
