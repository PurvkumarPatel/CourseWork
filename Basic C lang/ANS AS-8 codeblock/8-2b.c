/* Quation 2b */
#include <stdio.h>
int main() {
   int i, j, rows,r,space,x;
   printf("Enter the number of rows: ");//6
   scanf("%d", &rows);
   x=rows;
  for (i = 1; i <= rows;i++,x--) {
        for(space=1;x>=space;space++){
            printf(" ");
        }

         r=(2*i)-1;//3
      for (j = 1; j <= r; ++j) {
          printf("*");
      }
    printf("\n");}
return 0;

   }
