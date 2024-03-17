/*
    Disk Scheduling Alogorithms
*/
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

struct request
{
    int request_track_number;
    bool visited;
};


int fcfs()
{   
    printf("\n----------------- FCFS -----------------\n");
    int i, no_of_requests, initial_head;
    printf("Enter the number of requests: ");
    scanf("%d", &no_of_requests);
    int request[no_of_requests];
    printf("Enter the requests: ");
    for (i = 0; i < no_of_requests; ++i)
    {
        scanf("%d", &request[i]);
    }
    printf("Enter initial position of R/W head: ");
    scanf("%d", &initial_head);
    int seek_time = 0;
    printf("%d -> ", initial_head);
    for (i = 0; i < no_of_requests; i++)
    {
        if (i == no_of_requests - 1)
            printf("%d\n", request[i]);
        else
            printf("%d -> ", request[i]);
        seek_time += abs(request[i] - initial_head);
        initial_head = request[i];
    }
    printf("Seek Time of FCFS: %d\n", seek_time);
}

int sstf()
{
    printf("\n----------------- SSTF -----------------\n");
    int i, no_of_requests, initial_head, limit, j, choice, previous_head;
    printf("Enter the number of requests: ");
    scanf("%d", &no_of_requests);
    struct request req[no_of_requests];
    printf("Enter the requests: ");
    for (i = 0; i < no_of_requests; ++i)
    {
        scanf("%d", &req[i].request_track_number);
        req[i].visited = false;
    }
    printf("Enter initial position of R/W head: ");
    scanf("%d", &initial_head);

    int seek_time = 0;
    printf("%d -> ", initial_head);
    int n = no_of_requests;
    while (n)
    {
        int min = 1e9;
        int min_track_number, position;
        for (i = 0; i < no_of_requests; i++)
        {
            if (abs(initial_head - req[i].request_track_number) < min && req[i].visited == false)
            {
                min = abs(initial_head - req[i].request_track_number);
                min_track_number = req[i].request_track_number;
                position = i;
            }
        }
        initial_head = req[position].request_track_number;
        req[position].visited = true;
        printf("%d ->", min_track_number);
        seek_time += min;
        n--;
    }

    printf("\nSeek Time of SSTF: %d\n", seek_time);
}





int scan()
{
    printf("\n----------------- SCAN -----------------\n");
    int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move;
    printf("Enter the number of Requests: ");
    scanf("%d",&n);
    printf("Enter the Requests sequence: ");
    for(i=0;i<n;i++)
    scanf("%d",&RQ[i]);
    printf("Enter initial head position: ");
    scanf("%d",&initial);
    printf("Enter total disk size: ");
    scanf("%d",&size);
    printf("Enter the head movement direction for high 1 and for low 0 : ");
    scanf("%d",&move);
    
    // logic for Scan disk scheduling
    
        /*logic for sort the request array */
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(RQ[j]>RQ[j+1])
            {
                int temp;
                temp=RQ[j];
                RQ[j]=RQ[j+1];
                RQ[j+1]=temp;
            }

        }
    }

    int index;
    for(i=0;i<n;i++)
    {
        if(initial<RQ[i])
        {
            index=i;
            break;
        }
    }
   
    // if movement is towards high value
    if(move==1)
    {
        for(i=index;i<n;i++)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        //  last movement for max size 
        TotalHeadMoment=TotalHeadMoment+abs(size-RQ[i-1]-1);
        initial = size-1;
        for(i=index-1;i>=0;i--)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
            
        }
    }
    // if movement is towards low value
    else
    {
        for(i=index-1;i>=0;i--)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        //  last movement for min size 
        TotalHeadMoment=TotalHeadMoment+abs(RQ[i+1]-0);
        initial =0;
        for(i=index;i<n;i++)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
            
        }
    }
    
    printf("Seek time of SCAN: %d",TotalHeadMoment);
    printf("\n");
    return 0;
}

int cscan()

{
    printf("\n----------------- C-SCAN -----------------\n");
    int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move;
    printf("Enter the number of Requests: ");
    scanf("%d",&n);
    printf("Enter the Requests sequence: ");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter initial head position: ");
    scanf("%d",&initial);
    printf("Enter total disk size: ");
    scanf("%d",&size);
    printf("Enter the head movement direction for high 1 and for low 0: ");
    scanf("%d",&move);
    
    // logic for C-Scan disk scheduling
    
        /*logic for sort the request array */
    for(i=0;i<n;i++)
    {
        for( j=0;j<n-i-1;j++)
        {
            if(RQ[j]>RQ[j+1])
            {
                int temp;
                temp=RQ[j];
                RQ[j]=RQ[j+1];
                RQ[j+1]=temp;
            }

        }
    }

    int index;
    for(i=0;i<n;i++)
    {
        if(initial<RQ[i])
        {
            index=i;
            break;
        }
    }
   
    // if movement is towards high value
    if(move==1)
    {
        for(i=index;i<n;i++)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        //  last movement for max size 
        TotalHeadMoment=TotalHeadMoment+abs(size-RQ[i-1]-1);
        /*movement max to min disk */
        TotalHeadMoment=TotalHeadMoment+abs(size-1-0);
        initial=0;
        for( i=0;i<index;i++)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
            
        }
    }
    // if movement is towards low value
    else
    {
        for(i=index-1;i>=0;i--)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        //  last movement for min size 
        TotalHeadMoment=TotalHeadMoment+abs(RQ[i+1]-0);
        /*movement min to max disk */
        TotalHeadMoment=TotalHeadMoment+abs(size-1-0);
        initial =size-1;
        for(i=n-1;i>=index;i--)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
            
        }
    }
    
    printf("Seek time of C-SCAN: %d",TotalHeadMoment);
    printf("\n");
    return 0;
}



int lookscan()
{
    printf("\n----------------- Look SCAN -----------------\n");
    int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move;
    printf("Enter the number of Requests: ");
    scanf("%d",&n);
    printf("Enter the Requests sequence: ");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter initial head position: ");
    scanf("%d",&initial);
    printf("Enter total disk size: ");
    scanf("%d",&size);
    printf("Enter the head movement direction for high 1 and for low 0: ");
    scanf("%d",&move);
    
    // logic for look disk scheduling
    
        /*logic for sort the request array */
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(RQ[j]>RQ[j+1])
            {
                int temp;
                temp=RQ[j];
                RQ[j]=RQ[j+1];
                RQ[j+1]=temp;
            }

        }
    }

    int index;
    for(i=0;i<n;i++)
    {
        if(initial<RQ[i])
        {
            index=i;
            break;
        }
    }
   
    // if movement is towards high value
    if(move==1)
    {
        for(i=index;i<n;i++)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        
        for(i=index-1;i>=0;i--)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
            
        }
    }
    // if movement is towards low value
    else
    {
        for(i=index-1;i>=0;i--)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        
        for(i=index;i<n;i++)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
            
        }
    }
    
    printf("Seek time of Look SCAN: %d",TotalHeadMoment);
    printf("\n");
    return 0;
}


int clook()
{
    printf("\n----------------- C - LOOK -----------------\n");
    int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move;
    printf("Enter the number of Requests: ");
    scanf("%d",&n);
    printf("Enter the Requests sequence: ");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter initial head position: ");
    scanf("%d",&initial);
    printf("Enter total disk size: ");
    scanf("%d",&size);
    printf("Enter the head movement direction for high 1 and for low 0: ");
    scanf("%d",&move);
    
    // logic for C-look disk scheduling
    
        /*logic for sort the request array */
    for(i=0;i<n;i++)
    {
        for( j=0;j<n-i-1;j++)
        {
            if(RQ[j]>RQ[j+1])
            {
                int temp;
                temp=RQ[j];
                RQ[j]=RQ[j+1];
                RQ[j+1]=temp;
            }

        }
    }

    int index;
    for(i=0;i<n;i++)
    {
        if(initial<RQ[i])
        {
            index=i;
            break;
        }
    }
   
    // if movement is towards high value
    if(move==1)
    {
        for(i=index;i<n;i++)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        
        for( i=0;i<index;i++)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
            
        }
    }
    // if movement is towards low value
    else
    {
        for(i=index-1;i>=0;i--)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        
        for(i=n-1;i>=index;i--)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
            
        }
    }
    
    printf("Seek time of C-LOOK: %d",TotalHeadMoment);
    printf("\n");
    return 0;
}


int main()
{
    while (true)
    {
        /* code */
        int n;
        printf("\n");
        printf("----------------------------------------------");
        printf("\n1 -> FCFS \n2 -> SSTF \n3 -> SCAN \n4 -> C-SCAN \n5 -> LOOK \n6 -> C-LOOK \n");
        printf("SELECT DISK SCHEDULING ALGORITHM -------> ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
        {
            fcfs();
        }
        break;

        case 2:
        {
            sstf();
        }
        break;
        case 3:
        {
            scan();
        }
        break;
        case 4:
        {
            cscan();
        }
        break;
        case 5:
        {
            lookscan();
        }
        break;

        case 6:
        {
            clook();
        }
        break;

        default:
            break;
        }
    }
}