#include<bits/stdc++.h>
using namespace std;
void fcfs(int n, int bt[], int wt[], int tat[]);
void sjf(int n, int bt[], int wt[], int tat[]);
void srtf(int n, int bt[], int wt[], int tat[]);
void roundRobin(int n, int bt[], int wt[], int tat[], int quantum);
void priority(int n, int bt[], int wt[], int tat[], int p[]);
int main()
{
    int n, bt[100], wt[100], tat[100], p[100], quantum, choice;

    cout<<"Enter the number of processes : ) ";
    cin>>n;
    cout<<"Enter the burst time of the processes:)\n";
    for(int i = 0; i < n; i++)
    {
        cout<<"P["<<i+1<<"]: ";
        cin>>bt[i];
    }
    cout<<"Enter the priority of the processes:)\n";
    for(int i = 0; i < n; i++)
    {
        cout<<"P["<<i+1<<"]: ";
        cin>>p[i];
    }
    cout<<"Enter the time quantum:)";
    cin>>quantum;
    cout<<"Enter the scheduling algorithm to be used:\n";
    cout<<"1. FCFS\n";
    cout<<"2. SJF\n";
    cout<<"3. SRTF\n";
    cout<<"4. Round Robin\n";
    cout<<"5. Priority\n";
    int Algo;
    int arr[10];
    
    cout<<endl<<"How many Algoritham you want to Test:"<<endl;
    cin>>Algo;
    for (int i = 0; i < Algo; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < Algo; i++)
    {
        /* code */
    choice=arr[i];
    switch(choice)
    {
        case 1:
        cout<<endl<<endl<<"-------------FCFS algo-------------:) ";
            fcfs(n, bt, wt, tat);
            break;
        case 2:
        cout<<endl<<endl<<"--------------SJF algo-------------:) ";
            sjf(n, bt, wt, tat);
            break;
        case 3:
        cout<<endl<<endl<<"-------------SRTF algo-------------:) ";
            srtf(n, bt, wt, tat);
            break;
        case 4:
        cout<<endl<<endl<<"---------Round Robin algo----------:) ";
            roundRobin(n, bt, wt, tat, quantum);
            break;
        case 5:
        cout<<endl<<endl<<"-----------Priority algo-----------:) ";
            priority(n, bt, wt, tat, p);
            break;
        default:
            cout<<endl<<"?????? Wrong input see u later ????? :(";
    }
    }
    
    return 0;
}

// FCFS
void fcfs(int n, int bt[], int wt[], int tat[])
{
    wt[0] = 0;
    int total = 0;
    for(int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
    for(int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
    }
    float avg_wt = (float)total / n;
    float avg_tat = (float)total / n;
    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(int i = 0; i < n; i++)
    {
        cout<<"\nP["<<i+1<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
    }
    cout<<"\n\nAverage Waiting Time="<<avg_wt;
    cout<<"\nAverage Turnaround Time="<<avg_tat;
}
// ```
// This function takes three integer arrays as input arguments: `bt[]` which contains the burst time of each process, `wt[]` which contains the waiting time of each process, and `tat[]` which contains the turnaround time of each process. It also takes an integer `n` which is the number of processes. The function calculates the waiting time and turnaround time of each process and prints them along with the average waiting time and average turnaround time.
//SJF
void sjf(int n, int bt[], int wt[], int tat[])
{
    int rt[n];
    for(int i = 0; i < n; i++)
    {
        rt[i] = bt[i];
    }
    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;
    while(complete != n)
    {
        for(int j = 0; j < n; j++)
        {
            if((rt[j] <= minm) && (rt[j] > 0))
            {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }
        if(check == false)
        {
            t++;
            continue;
        }
        rt[shortest]--;
        minm = rt[shortest];
        if(minm == 0)
        {
            minm = INT_MAX;
        }
        if(rt[shortest] == 0)
        {
            complete++;
            check = false;
            finish_time = t + 1;
            wt[shortest] = finish_time - bt[shortest];
            if(wt[shortest] < 0)
            {
                wt[shortest] = 0;
            }
        }
        t++;
    }
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
    }
    float avg_wt = (float)total / n;
    float avg_tat = (float)total / n;
    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(int i = 0; i < n; i++)
    {
        cout<<"\nP["<<i+1<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
    }
    cout<<"\n\nAverage Waiting Time="<<avg_wt;
    cout<<"\nAverage Turnaround Time="<<avg_tat;
}

//SRJF
void srtf(int n, int bt[], int wt[], int tat[])
{
    int rt[n];
    for(int i = 0; i < n; i++)
    {
        rt[i] = bt[i];
    }
    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;
    while(complete != n)
    {
        for(int j = 0; j < n; j++)
        {
            if((rt[j] <= minm) && (rt[j] > 0))
            {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }
        if(check == false)
        {
            t++;
            continue;
        }
        rt[shortest]--;
        minm = rt[shortest];
        if(minm == 0)
        {
            minm = INT_MAX;
        }
        if(rt[shortest] == 0)
        {
            complete++;
            check = false;
            finish_time = t + 1;
            wt[shortest] = finish_time - bt[shortest];
            if(wt[shortest] < 0)
            {
                wt[shortest] = 0;
            }
        }
        t++;
    }
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
    }
    float avg_wt = (float)total / n;
    float avg_tat = (float)total / n;
    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(int i = 0; i < n; i++)
    {
        cout<<"\nP["<<i+1<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
    }
    cout<<"\n\nAverage Waiting Time="<<avg_wt;
    cout<<"\nAverage Turnaround Time="<<avg_tat;
}

//RR
void roundRobin(int n, int bt[], int wt[], int tat[], int quantum)
{
    int rem_bt[n];
    for(int i = 0; i < n; i++)
    {
        rem_bt[i] = bt[i];
    }
    int t = 0;
    while(1)
    {
        bool done = true;
        for(int i = 0; i < n; i++)
        {
            if(rem_bt[i] > 0)
            {
                done = false;
                if(rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if(done == true)
        {
            break;
        }
    }
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
    }
    float avg_wt = (float)total / n;
    float avg_tat = (float)total / n;
    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(int i = 0; i < n; i++)
    {
        cout<<"\nP["<<i+1<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
    }
    cout<<"\n\nAverage Waiting Time="<<avg_wt;
    cout<<"\nAverage Turnaround Time="<<avg_tat;
}

//PRIORITY
void priority(int n, int bt[], int wt[], int tat[], int p[])
{
    int pos, temp;
    for(int i = 0; i < n; i++)
    {
        pos = i;
        for(int j = i + 1; j < n; j++)
        {
            if(p[j] < p[pos])
            {
                pos = j;
            }
        }
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
    }
    wt[0] = 0;
    for(int i = 1; i < n; i++)
    {
        wt[i] = 0;
        for(int j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }
    }
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
    }
    float avg_wt = (float)total / n;
    float avg_tat = (float)total / n;
    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(int i = 0; i < n; i++)
    {
        cout<<"\nP["<<i+1<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
    }
    cout<<"\n\nAverage Waiting Time="<<avg_wt;
    cout<<"\nAverage Turnaround Time="<<avg_tat;
}
