#include <stdio.h>
int size=0;
void insert(int arr[],int num,int pos)
{
  if(pos<=size)
  {
  for(int i=size-1;i>=pos;i--)
  {
    arr[i+1]=arr[i];
  }
  arr[pos]=num;
  size++;
  printf("ARRAY :- \n");
  for(int i=0;i<size;i++)
  {
     printf("%d ",arr[i]);
  }
  printf("\n\n");
 }
 else{
     printf("NOT POSSIBLE \n\n");
 }
}

int search(int arr[],int key)
{
    for(int i=0;i<size;i++)
    {
        if(key==arr[i])
        {
           return i;
           break;
        }
        if(i==size-1)
        {
            return -1;
        }
    }
}

void delete(int arr[],int num)
{
  int pos = search(arr,num);
  if(pos<=size && size!=0 && pos!=-1)
  {
  for(int i=pos;i<size;i++)
  {
    arr[i]=arr[i+1];
  }
  size--;
  printf("ARRAY :- \n");
  for(int i=0;i<size;i++)
  {
     printf("%d ",arr[i]);
  }
  printf("\n\n");
 }
 else{
     printf("NOT POSSIBLE\n\n");
 }
}

void update(int arr[],int num,int pos)
{
   if(pos<size && size!=0)
   {
       arr[pos]=num;
   }
   else{
       printf("NOT POSSIBLE\n\n");
   }
   printf("ARRAY :- \n");
  for(int i=0;i<size;i++)
  {
     printf("%d ",arr[i]);
  }
  printf("\n\n");
}

void printarray(int arr[])
{
   printf("ARRAY :- \n");
  for(int i=0;i<size;i++)
  {
     printf("%d ",arr[i]);
  } 
  printf("\n\n");
}

int main()
{
    int a,num,pos,key;
    printf("WELCOME TO THE PROGRAM \n");
    printf("ENTER SIZE OF YOUR ARRAY ");
    scanf("%d",&size);
    int arr[1000];
    printf("ENTER YOUR ARRAY ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    while(a)
    {
        printf("ENTER 1 FOR INSERTING \n");
        printf("ENTER 2 FOR DELETION \n");
        printf("ENTER 3 FOR SEARCHING \n");
        printf("ENTER 4 FOR UPDATING \n");
        printf("ENTER 5 FOR PRINTING \n");
        printf("ENTER 6 FOR QUITTING THE PROGRAM \n");
  
        scanf("%d",&a);
        switch(a)
        {
            case 1:
            printf("Enter the number you want to insert ");
            scanf("%d",&num);
            printf("Enter the position ");
            scanf("%d",&pos);
            insert(arr,num,pos);
            continue;

            case 2:
            printf("Enter the number you want to delete ");
            scanf("%d",&num);
            delete(arr,num);
            continue;

            case 3:
            printf("Enter the number you want to search ");
            scanf("%d",&num);
            pos = search(arr,num);
            if(pos!=-1)
            {
                printf("ELEMENT FOUND AT POSITION %d\n\n",pos);
            }
            else{
                printf("ELEMENT NOT FOUND\n\n");
            }
            continue;

            case 4:
            printf("Enter the number you want to insert ");
            scanf("%d",&num);
            printf("Enter the position you want to update ");
            scanf("%d",&pos);
            update(arr,num,pos);
            continue;

            case 5:
            printarray(arr);
            continue;

            case 6:
            a=0;
            continue;
        }
    }

    printf("THANK YOU FOR USING THE PROGRAM");
}