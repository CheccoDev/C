#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int x,i;
  do
  {
             printf("Anno: ");
             scanf("%d",&x);
  }
  while (!(x>1950));
  for (i=1900;i<=x;i++)
  {
      if ((i%400 == 0) || ((i%4 == 0) && (i%100 != 0)))
      {
                 printf("%d ",i);
      }
  }
  return 0;
}
