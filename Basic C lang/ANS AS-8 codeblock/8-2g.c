/* Quation 8-2g */
#include <stdio.h>
int main() {
   int i, j, rows,n;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   for (i = 1; i <=rows; ++i) {
      for (j = 1,n=i; j <= i;j++) {
         printf("%d\t",n*n);
         --n;
      }
      printf("\n");
   }
   return 0;
}
