#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char sex;
  int age;
  printf("Età? ");
  scanf("%d",&age);
  if (age>=21)
  {
          printf("M/F? ");
          fflush(stdin);
          scanf("%c",&sex);
          if ((sex == 'm') || (sex == 'M'))
          {
                  printf("Il costo del biglietto è di 30 euro.\n");
          }
          else
          {
              if ((sex == 'f') || (sex == 'F'))
              {
                      printf("Entra pure!\n");
              }
          }
  }
  else
  {
      printf("Devi avere almeno 21 anni per entrare.\n");
  }
  system("PAUSE");	
  return 0;
}
