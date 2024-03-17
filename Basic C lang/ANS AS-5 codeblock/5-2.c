/* 2. Write a C program to accept id from employee and display his/her designation using switch case. */
#include<stdio.h>
int main()
{
    int n;
    printf("Enter your Employee ID:");
    scanf("%d",&n);

    switch(n)
    {
    case 101 :
        printf("Your department is Business Analyst");
        break;
    case 102:
        printf("Your department is QA Engineer");
        break;
    case 102:
        printf("Your department is QA Engineer");
        break;
    case 103:
        printf("Your department is Front-end Developer");
        break;
    case 104:
        printf("Your department is Back-end Developer");
        break;
    case 105:
        printf("Your department is Tester");
        break;
    case 106:
        printf("Your department is Full-stack Developer");
        break;
    case 107:
        printf("Your department is QA Engineer");
        break;
    case 108:
        printf("Your department is QA Engineer");
        break;
    case 109:
        printf("Your department is Front-end Developer");
        break;
    case 110:
        printf("Your department is Full-stack Developer");
        break;
    case 111:
        printf("Your department is Back-end Developer");
        break;
    case 112:
        printf("Your department is Back-end Developer");
        break;
    case 113:
        printf("Your department is Business Analyst");
        break;
    case 114:
        printf("Your department is Tester");
        break;
    case 115:
        printf("Your department is Tester");
        break;
    case 116:
        printf("Your department is Full-stack Developer");
        break;
    default :
        printf("Invalid ID");
    }
    return 0;
}
