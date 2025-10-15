#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char a,b,c,d;
  printf("Carattere 1: ");
  fflush(stdin);
  scanf("%c",&a);
  printf("Carattere 2: ");
  fflush(stdin);
  scanf("%c",&b);
  printf("Carattere 3: ");
  fflush(stdin);
  scanf("%c",&c);
  printf("Carattere 4: ");
  fflush(stdin);
  scanf("%c",&d);
  //Uno per riga
  printf("\n%c\n%c\n%c\n%c\n",a,b,c,d);
  //Tutti su una sola riga senza spazi
  printf("%c%c%c%c\n",a,b,c,d);
  //Tutti su una sola riga con spazi
  printf("%c %c %c %c\n",a,b,c,d);
  system("PAUSE");	
  return 0;
}
