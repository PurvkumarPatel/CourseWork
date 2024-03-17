#include<stdio.h>
#include<string.h>
union details
{
char name[30];
char home_add[60];
char hostel_add[30];
char city[10];
char state[10];
int pincode;
}a;
void main()
{
strcpy(a.name,"Purvkumar Maheshkumar Patel");
printf("\nNAME : %s",a.name);
strcpy(a.hostel_add,"Ichchnath SVNIT Campus IIIT SURAT");
printf("\nCOLLEGE : %s",a.hostel_add);
strcpy(a.home_add,"Nilkanth Heights \n\t Parvat Patiya ");
printf("\nADDRESS : %s",a.home_add);
strcpy(a.city,"Surat");
printf("\nCITY : %s",a.city);
strcpy(a.state,"Gujarat");
printf("\nSTATE : %s",a.state);
a.pincode=395010;
printf("\nPINCODE : %d",a.pincode);
}
