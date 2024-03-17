#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
void firstFit(int blockSize[], int m, int processSize[], int n)
{
	int i, j;
	// Stores block id of the block allocated to a process
	int allocation[n];

	// Initially no block is assigned to any process
	for(i = 0; i < n; i++)
	{
		allocation[i] = -1;
	}

	// pick each process and find suitable blocks
	// according to its size ad assign to it
	for (i = 0; i < n; i++)	 //here, n -> number of processes
	{
		for (j = 0; j < m; j++)	 //here, m -> number of blocks
		{
			if (blockSize[j] >= processSize[i])
			{
				// allocating block j to the ith process
				allocation[i] = j;

				// Reduce available memory in this block.
				blockSize[j] -= processSize[i];

				break; //go to the next process in the queue
			}
		}
	}

	printf("\nProcess No.\tProcess Size\tBlock no.\n");
	for (int i = 0; i < n; i++)
	{
		printf(" %i\t\t", i+1);
		printf("%i\t\t", processSize[i]);
		if (allocation[i] != -1)
			printf("%i", allocation[i] + 1);
		else
			printf("Not Allocated");
		printf("\n");
	}
}
void worstFit(int blockSize[], int m, int processSize[],
                                                 int n)
{

    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
 
    for (int i=0; i<n; i++)
    {
        int wstIdx = -1;
        for (int j=0; j<m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (wstIdx == -1)
                    wstIdx = j;
                else if (blockSize[wstIdx] < blockSize[j])
                    wstIdx = j;
            }
        }
 
        if (wstIdx != -1)
        {
            allocation[i] = wstIdx;
 
            blockSize[wstIdx] -= processSize[i];
        }
    }
 
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i+1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout <<endl ;
    }
}
void bestFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;
    for (int i = 0; i < n; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
 
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}
 
int main()
{
	
	int m; //number of blocks in the memory
	cout<<"Enter number of blocks in memory: "<<endl;
	cin>>m;
	
	int n; //number of processes in the input queue
	cout<<"Enter number of blocks in process: "<<endl;
	cin>>n;

	int blockSize[m];
	int processSize[n];
	
	
	cout<<"Enter block sizes: "<<endl;
	for(int i=0;i<m;i++){
	    cin>>blockSize[i];
	}
	
	cout<<"Enter process sizes: "<<endl;
	for(int i=0;i<n;i++){
	    cin>>processSize[i];
	}


int a;
cout<<"1.first fit\n2.bestfit\n3.worstFit "<<endl;
cin>>a;
switch(a){
    case 1:
    cout<<"---------------------<<First Fit>>---------------------"<<endl;
    firstFit(blockSize, m, processSize, n);
    break;
    case 2:
    cout<<"---------------------<<Best Fit>>---------------------"<<endl;
    bestFit(blockSize, m, processSize, n);   
    break;
    case 3:
    cout<<"---------------------<<Wrost Fit>>---------------------"<<endl;
    worstFit(blockSize, m, processSize, n);
    break;
    default:
    cout << "invalid";
}
	return 0 ;
}
