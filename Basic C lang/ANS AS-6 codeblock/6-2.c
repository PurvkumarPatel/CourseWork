/* 2. Write a C program considering below information:
   when the color of traffic is green, print go,
   in the case of the traffic is yellow print ready, and if the traffic color is red, prints stop. */
#include <stdio.h>
int main()
{
    printf("1.Green\n2.Yellow\n3.Red\n");
    int n;
    printf("Enter your color trafic color choice\n");
    scanf("%d", &n);
    if (n == 1)
    {
        printf("go\n");
    }
    else if (n == 2)
    {
        printf("ready\n");
    }
    else if (n == 3)
    {
        printf("stop\n");
    }
    else
    {
        printf("Invalid Input\n");
    }
    return 0;
}
