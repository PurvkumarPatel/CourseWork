/* 12. C program to read user’s choice between 1 to 5 and print the color selected by user.
The choices for color given to user is given below: 1-Yellow, 2-Red, 3-Green, 4-Blue, 5-White */
#include<stdio.h>
int main()
{
 int N;
 printf("Enter number (1-5): ");
 scanf("%d",&N);

 if(N==1)
     {
     printf("Your Colour is Yellow");
     }
 else if(N==2)
     {
     printf("Your Colour is Red");
     }
 else if(N==3)
     {
     printf("Your Colour is Green");
     }
 else if(N==4)
     {
     printf("Your Colour is Blue");
     }
 else if(N==5)
     {
     printf("Your Colour is white");
     }
 else
     {
     printf("Invalid Input ");
     }

 return 0;
}
