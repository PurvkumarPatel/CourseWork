#include<stdio.h>
#include<stdlib.h>

void SELECTION_SORT(){
    int n;
    printf("ENTER SIZE OF ARRAY --> ");
    scanf("%d",&n);

    int a[n];
    for(int i=0;i<n;i++)
    {printf("ENTER %d ELEMENT-->",i);
        scanf("%d",&a[i]);}

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int c=a[i];
                a[i]=a[j];
                a[j]=c;
            }
        }
    }

    printf("THE SORTED ARRAY IS --->>");
    for(int i=0;i<n;i++)
        {printf("%d ",a[i]);}
    printf("\n");        
}

void BUBBLE_SORT(){
    int n;
    printf("ENTER SIZE OF ARRAY --> ");
    scanf("%d",&n);

    int a[n];
    for(int i=0;i<n;i++)
        {printf("ENTER %d ELEMENT -->",i);
        scanf("%d",&a[i]);}

    int i=0;
    while(i<n-1){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int c=a[j];
                a[j]=a[j+1];
                a[j+1]=c;
            }
        }
        i++;
    }

    printf("THE SORTED ARRAY IS --->>");
    for(int i=0;i<n;i++)
        {printf("%d ",a[i]);}
    printf("\n");    
}

int main(){
    int c;
    
    while(1){
        printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
        printf("\n\t>>> 1-SELECTION SORT");
        printf("\n\t>>> 2-BUBBLE SORT");
        printf("\n\t>>> 3-EXIT");
        printf("\n\t\tENTER CHOICE -->");
        scanf("%d", &c);
        switch(c){
            case 1:
                SELECTION_SORT();
                break;
            case 2:
                BUBBLE_SORT();
                break;
            case 3:
                printf(":::::::::::::::EXITED:::::::::::::::");
                exit(0);          
            default:
                printf("\nWRONG CHOICE");
        }
    }
}