/* 12. Write a C program to print the table of a number using goto statement. */
#include<stdio.h>

int main()
{
	int count,t,r;
	printf("Enter number: ");
	scanf("%d",&t);

	count=1;

	start:
	if(count<=10)
	{
		r=t*count;
		printf("%d*%d=%d\n",t,count,r);
		count++;
		goto start;
	}

	return 0;
}

