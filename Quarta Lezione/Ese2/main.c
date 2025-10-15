#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  
  char op;
  printf("Operatore: ");
  scanf("%c",&op);
  switch (op)
  {
         case '+':
         {
              printf("Somma\n");
              break;
         }
         case '-':
         {
              printf("Sottrazione\n");
              break;
         }
         case '*':
         {
              printf("Moltiplicazione\n");
              break;
         }
         case '/':
         {
              printf("Divisione\n");
              break;
         }
         default:
                 {
                                    printf("ERRORE\n");
                 }
  }
  return 0;
}
