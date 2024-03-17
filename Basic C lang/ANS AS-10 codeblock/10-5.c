/* 5. Write a program in C to store the age of six students (19, 21, 20, 19, 20, 20)
 in an array and display the total number of duplicate ages in it. */
#include <stdio.h>
void main()
{
    int n,mm=1,ctr=0;
    int i,j;
       printf("Enter the size of array :");
       scanf("%d",&n);
    int arr1[n ];
	int arr2[n];
	int arr3[n];

       printf("Input %d ages in the array :\n",n);
       for(i=0;i<n;i++)
        {
	      printf("Age %d - : ",i);
	      scanf("%d",&arr1[i]);
	    }

		for(i=0;i<n; i++)
        {
		arr2[i]=arr1[i];
		arr3[i]=0;
        }

	for(i=0;i<n; i++)
        {
		for(j=0;j<n;j++)
			{
				if(arr1[i]==arr2[j])
				{
				arr3[j]=mm;
				mm++;
				}
			}
			mm=1;
        }
   for(i=0; i<n; i++)
    {
      if(arr3[i]==2)
      ctr++;
    }
      printf("The total number of duplicate ages found in the array is: %d \n", ctr);
}
