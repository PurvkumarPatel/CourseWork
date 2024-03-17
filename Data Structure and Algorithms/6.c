#include<stdio.h>
#include<stdlib.h>

#define MAX 3
int choice,top=-1,x;
int queue[MAX];
void enqueue(void);
void dequeue(void);
void display(void);

void main()
{
    loop:
    printf("\n//////////////////////////////////////////////////////////////////");
    printf("\n----------------------------------------------------------------\n");
    printf("1 > Add Element at Last in Queue\n");
    printf("2 > Remove Element From First Position in Queue\n");
    printf("3 > Display Queue\n");
    printf("4 > Exit the Program\n");
    printf("\n\t Enter the Choice:");
    scanf("%d",&choice);
    printf("\n-------------------------------------------------------------------");
    

    switch(choice)
    {
        case 1:
        {
            printf("\n\t--->Add Element\n");
            enqueue();
            goto loop;
        }
        case 2:
        {
            printf("\n\t--->Remove Element :\n");
            dequeue();
            goto loop;
        }
        case 3:
        {
            printf("\n\t--->Display :\n\n");
            display();
            goto loop;
        }
        case 4:
        {
            printf("\n \\\\ Exit the Program //\n\n");
            exit(1);
        }
        default :
        {
            printf("\n\t :Invalid Choice: \n\n");
            goto loop;
        }
    }
}

void enqueue()
{
    if(top>MAX-2)
    {
        printf("\n\t :Queue is Overflow: ");

    }
    else
    {
        top++;
        printf("\t--->Enter a value to be pushed:");
        scanf("%d",&x);
        queue[top]=x;
    }
    display();
}

void display()
{
    if(top>=0)
    {
        printf("\t The elements in Queue: ");
        for(int i=0; i<=top; i++)
        printf("%d ",queue[i]);
    }
    else
    {
        printf("\n :The Queue is empty or underflow:");
    }
}

void dequeue()
{
    if(top<0)
    {

    }
    else
    {
        for(int i=1,j=0;i<=top;i++,j++)
        {
            queue[j] = queue[i];
        }
        top--;
    }
    display();
}