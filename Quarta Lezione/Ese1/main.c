#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  
  int n;
  printf("Numero: ");
  scanf("%d",&n);
  switch (n)
  {
         case 0:
              {
                  printf("%d",n);
                  break;
              }
         case 1:
              {
                  printf("%d",n);
                  break;
              }
         case 2:
              {
                  printf("%d",n);
                  break;
              }
         default:
                 {
                                 printf("ERRORE!!\n");
                                 break;
                 }
  }	
  return 0;
}
