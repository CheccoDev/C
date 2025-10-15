#include <stdio.h>
#include <stdlib.h>
#define MAX 19
int main(int argc, char *argv[])
{
  char ncar[MAX+1];
  int k;
  unsigned int i;
  signed int j;
  unsigned int len = 0;
  int a = 1;
  printf("Parola: ");
  fflush(stdin);
  scanf("%s",ncar);
  while (ncar[len] != '\0')
  {
        len += 1;
  }
  for (i=0,j=(len-1);i<len&&j>0;++i,--j)
  {
      if ((ncar[i] == ncar[j]) && (a==1))
      {
                  a = 1;
      }
      else
      {
          a = 0;
          break;
      }
  }
  if (a==1)
  {
           printf("Palindroma!\n");
  }
  else
  {
      printf("Non palindroma!\n");
  }
  system("PAUSE");	
  return 0;
}
