#include<stdio.h>
struct DOB
{
char name[30];
struct date
{
int day ;
int month;
int year;
}time_detail;
}person1;
int main()
{
printf("ENTER YOUR NAME : ");
scanf("%[^\n]s",&person1.name);
printf("ENTER THE DATE :");
scanf("%d",&person1.time_detail.day);
printf("ENTER THE MONTH :");
scanf("%d",&person1.time_detail.month);
printf("ENTER THE YEAR :");
scanf("%d",&person1.time_detail.year);
printf("\n\t-------------------");
printf("\n\t| PERSONAL DETAIL |");
printf("\n\t-------------------");
printf("\n\tNAME : %s",person1.name);
printf("\n\tDATE OF BIRTH :%d/%d/%d",person1.time_detail.day,person1.time_detail.month,person1.time_detail.year);
}
