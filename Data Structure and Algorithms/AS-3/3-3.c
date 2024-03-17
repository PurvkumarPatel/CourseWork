#include<stdio.h>
struct Marks
{
int roll_no;
char name[20];
float chem_marks;
float math_marks;
float phy_marks;
float total ;
float percent ;
}stud[5];
void data_entry(struct Marks *ptr)
{
printf("\nEnter the name of student : ");
scanf("%s",&(*ptr).name);
printf("Enter the roll no of student : ");
scanf("%d",&ptr->roll_no);
printf("Enter the marks obtained in Chemistry out of 100 : ");
scanf("%f",&ptr->chem_marks);
printf("Enter the marks obtained in Mathematics out of 100 : ");
scanf("%f",&ptr->math_marks);
printf("Enter the marks obtained in Physics out of 100 : ");
scanf("%f",&ptr->phy_marks);
ptr->total=ptr->phy_marks+ptr->chem_marks+ptr->math_marks;
ptr->percent=ptr->total/3;
}
void data_display(struct Marks *pt)
{
printf("\n\t\t----------");
printf("\n\t\t| RESULT |");
printf("\n\t\t----------");
printf("\n\tNAME : %s ",(*pt).name);
printf("\n\tROLL NO : %d ",pt->roll_no);
printf("\n\t--------------------------------");
printf("\n\tPHYSICS : %.2f ",pt->phy_marks);
printf("\n\tCHEMISTRY : %.2f ",pt->chem_marks);
printf("\n\tMATHEMATICS: %.2f ",pt->math_marks);
printf("\n\t--------------------------------");
printf("\n\tTOTAL : %.2f ",pt->total);
printf("\n\tPERCENTAGE : %.2f ",pt->percent);
}
void option(struct Marks *p , int n)
{
printf("\n\t%d. %s",n+1,(*p).name);
}
int main()
{
int choice ;
printf("\n\t---------------------------------------------------------");
printf("\n\t| NOTE : PLEASE ENTER DETAIL OF EACH STUDENT ONE BY ONE |");
printf("\n\t---------------------------------------------------------");
for (int i = 0; i < 5; i++)
{
data_entry(&stud[i]);
}
do
{
printf("\n\n\n\n\tSELCET FORM BELOW STUDENTS TO PRINT THE RESULT");
printf("\n\t----------------------------------------------");
for (int i = 0; i < 5; i++)
{
option(&stud[i],i);
}
printf("\n\t6. EXIT");
printf("\nEnter your choice : ");
scanf("%d",&choice);
if(choice >=1 && choice <=5)
{
data_display(&stud[choice-1]);
}
else if(choice<1 || choice>6)
{
printf("\nPLEASE ENTER THE VALID CHOICE ");
}
} while (choice!=6);
printf("\nEXITED");
}
