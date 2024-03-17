/* Quation 1a */
#include <stdio.h>
void main()
{
    int num,sum=0;
    printf("ENTER THE NUMBER:");
    scanf("%d",&num);
    printf("THE SERIES IS:");
    for (int i=1,j=1;i<=num,j<=num;i++,j++)
    {
        if (j%2!=0 && j!=1)
        {
            printf("-%d",i*i);
            sum-=i*i;
        }
        else
        {
            printf("+%d",i*i);
            sum+=i*i;
        }
    }
    printf("\nTHE SUM OF THE SERIES IS: %d\n",sum);
}
