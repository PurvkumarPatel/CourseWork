/* 7. C program to check whether a person is eligible to vote or not. */
#include<stdio.h>
int main()
{
	int a ;
	printf("Enter the age of the person: ");
	scanf("%d",&a);

	if (a>=18)
	{
		printf("Eligible for voting");
	}
	else
	{
		printf("Not eligible for voting");
	}

	return 0;
}
