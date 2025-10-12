#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int main(int argc, char *argv[])
{
    int c,i;
    char ndigit[MAX];
    int nwhite,nother;
  printf("Scrivi: ");
  nwhite = 0;
  nother = 0;
  for (i=0;i<MAX;++i)
  {
      ndigit[i] = 0;
  }
  while ((c=getchar()) != 'q')
  {
        if (c == ' ')
        {
              nwhite += 1;
              continue;
        }
        else if (c == '\t')
        {
              nother += 1;
              continue;
        }
        else if (c >= '0' && c <= '9')
        {
             ndigit[c-'0']++;
        }
  }
  for (i=0;i<MAX;++i)
  {
      printf("%d: %d\n",i,ndigit[i]);
  }
  printf("Spazi: %d\n",nwhite);
  printf("Tabulazioni: %d\n",nother);
  system("PAUSE");
  return 0;
}
