/* Quation 2c*/
#include <stdio.h>
int main() {
   int i, j, rows;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   for (i = rows; i >0; i--) {
      for (j = 1; j <= i; ++j) {
         printf("%d",j);
      }
      printf("\n");
   }
   return 0;
}
