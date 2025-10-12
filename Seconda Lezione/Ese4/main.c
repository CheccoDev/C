#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n1,n2,n3;
    printf("Lato 1: ");
    scanf("%d",&n1);
    printf("Lato 2: ");
    scanf("%d",&n2);
    printf("Lato 3: ");
    scanf("%d",&n3);
    if (n1>0 && n2>0 && n3>0)
    {
             if ((n1+n2)>n3 && (n1+n3)>n2 && (n2+n3)>n1)
             {
                        if ((n1 == n2) && (n2 == n3))
                        {
                               printf("Triangolo Equilatero.\n");
                        }
                        else
                        {
                            if ((n1 != n2) && (n2 != n3))
                            {
                                    printf("Triangolo Scaleno.\n");
                            }
                            else
                            {
                                printf("Triangolo Isoscele.\n");
                            }
                        } 
             }
             else
             {
                 printf("Triangolo Impossibile.\n");
             }
    }
    else
    {
        printf("Triangolo Impossibile.\n");
    }
  system("PAUSE");	
  return 0;
}
