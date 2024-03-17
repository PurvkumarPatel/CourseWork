#include<stdio.h>
union union_part
{
char name[30];
int roll_no;
float marks;
int percent;
}union_1;
struct struct_part
{
char name[30];
int roll_no;
float marks;
int percent;
}struct_1;
int main()
{
printf("\n\t UNION AND STRUCTURE BOTH HAVE SAME \n\tCOMPONENTS STILL SIZE OF BOTH DIFFERS");
printf("\n\t Union size = %d",sizeof(union_1));
printf("\n\t Structure size = %d",sizeof(struct_1));
}
