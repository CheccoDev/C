#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int li,ls,somma,i;
  somma = 0;
  printf("LI: ");
  scanf("%d",&li);
  printf("LS: ");
  scanf("%d",&ls);
  for (i=li;i<=ls;i++)
  {
      if (i%2 == 0)
      {
              somma += i;
      }
      else if (i%2 != 0)
      {
           somma -= i;
      }
  }
  printf("Somma: %d",somma);
  return 0;
}
