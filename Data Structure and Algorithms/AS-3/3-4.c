#include<stdio.h>
struct imperial_scale
{
float feet;
float inche;
}m1,m2,m3;
void data_entry (struct imperial_scale *ptr)
{
printf("\n\tEnter the feet part : ");
scanf("%f",&ptr->feet);
printf("\tEnter the inche part : ");
scanf("%f",&ptr->inche);
}
void check (struct imperial_scale *pt)
{
while (pt->inche>= 12)
{
pt->inche-=12;
pt->feet+=1;
}
}
void data_display (struct imperial_scale *p)
{
printf("\n\t%.2f feet %.2f inches",p->feet,p->inche);
}
int main()
{
printf("Enter the 1st Distances : ");
data_entry(&m1);
printf("\nEnter the 2nd Distances : ");
data_entry(&m2);
m3.feet=m1.feet+m2.feet;
m3.inche=m1.inche+m2.inche;
check(&m3);
printf("\n1st Distances :");
data_display(&m1);
printf("\n2nd Distances :");
data_display(&m2);
printf("\nTotal Distances :");
data_display(&m3);
}
