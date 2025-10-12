#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int anno;
  printf("Anno: ");
  scanf("%d",&anno);
  if (((anno%400) == 0) || (((anno%4) == 0) && ((anno%100) != 0)))
  {
                  printf("L'anno %d è bisestile.\n",anno);
  }
  else
  {
      printf("L'anno %d NON è bisestile.\n",anno);
  }
  system("PAUSE");
  return 0;
}
