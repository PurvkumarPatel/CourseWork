/* Quation 2f */
#include <stdio.h>
void main(){
    int n,i,j;
    printf("Enter the numbers of rows : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            if(i==2 || i==1){
                printf("1");
            }
            else if(i==n)
                printf("1");
            else{
                if(j==1 || j==i){
                    printf("1");
                }
                else{
                    printf("0");
                }
            }
        }
        printf("\n");
    }
}
