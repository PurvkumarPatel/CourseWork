#include<stdio.h>
struct student_record
{
int roll_no;
char name[20];
char adderss[20];
float marks;
int age;
}stud[5];
void data_entry(struct student_record *ptr)
{
printf("\nEnter the name of student : ");
scanf("%s",&(*ptr).name);
printf("Enter the address of student : ");
scanf("%s",&(*ptr).adderss);
printf("Enter the roll no of student : ");
scanf("%d",&ptr->roll_no);
printf("Enter the age of student : ");
scanf("%d",&ptr->age);
printf("Enter the marks of student : ");
scanf("%f",&ptr->marks);
}
void data_display(struct student_record *pt)
{
printf("\n\t------------------");
printf("\n\t| STUDENT DETAIL |");
printf("\n\t------------------");
printf("\n\tNAME : %s ",(*pt).name);
printf("\n\tADDRESS : %s ",(*pt).adderss);
printf("\n\tROLL NO : %d ",pt->roll_no);
printf("\n\tAGE : %d ",pt->age);
printf("\n\tMARKS : %.2f ",pt->marks);
}
void option(struct student_record *p , int n)
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
printf("\n\n\tSELCET FORM BELOW STUDENTS TO PRINT THE DETAIL");
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
