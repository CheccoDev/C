#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  
  int mese;
  printf("Numero: ");
  scanf("%d",&mese);
  switch (mese)
  {
         case 1:
              {
                    printf("Gennaio");
                    break;
              }
         case 2:
              {
                    printf("Febbraio");
                    break;
              }
         case 3:
              {
                    printf("Marzo");
                    break;
              }
         case 4:
              {
                    printf("Aprile");
                    break;
              }
         case 5:
              {
                    printf("Maggio");
                    break;
              }
         case 6:
              {
                    printf("Giugno");
                    break;
              }
         case 7:
              {
                    printf("Luglio");
                    break;
              }
         case 8:
              {
                    printf("Agosto");
                    break;
              }
         case 9:
              {
                    printf("Settembre");
                    break;
              }
         case 10:
              {
                    printf("Ottobre");
                    break;
              }
         case 11:
              {
                    printf("Novembre");
                    break;
              }
         case 12:
              {
                    printf("Dicembre");
                    break;
              }
         default:
                 {
                                       printf("ERRORE\n");
                 }
  }	
  return 0;
}
