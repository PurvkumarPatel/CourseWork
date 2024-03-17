#include <stdio.h>
/* 1. C program to check whether student is passed or failed. The minimum marks required to pass the exam is 35. */
int main(void) {
int Per;
	printf("Enter Per : ");
	scanf("%d",&Per);
	if(Per >= 35)
		printf("\nResult is pass");
	else
		printf("\nResult is fail");
	return 0;
}
