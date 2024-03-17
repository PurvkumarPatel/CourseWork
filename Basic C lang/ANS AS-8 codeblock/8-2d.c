/* Qution 2d  */
#include <stdio.h>
int main() {
   int i, j, rows,n=1,x=1;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   for (i = rows; i >0;i--,x++) {
        n=x;
      for (j =rows ; j>0 ;j--) {
         printf("%d",n);
         n++;
      }

      printf("\n");
   }
   return 0;
}
