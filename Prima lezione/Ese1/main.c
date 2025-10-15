#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  /*Scrivere un programma che esegue il prodotto di 2 numeri interi x e y e ne stampa il valore z a video
Inizialmente, scrivere il programma in modo che i valori x e y siano assegnati all¡¦interno del programma stesso
Provate a non assegnare un valore a x e y. Cosa succede?
Modificare il programma in modo da leggere i valori di x e y da tastiera*/

//Prima richiesta
    int x,y,z;
    x = 3;
    y = 4;
    z = x*y;
    printf("Il prodotto tra i numeri %d e %d e' %d",x,y,z);
    
    //Seconda richiesta
    int a,b,c;
    a = b = c=0;
    printf("Si inserisca il primo numero: ");
    scanf("%d",&a);
    printf("\nSi inserisca il secondo numero: ");
    scanf("%d",&b);
    c = a * b;
    printf("Il prodotto tra il numero %d e il numero %d e' %d\n",a,b,c);
  system("PAUSE");
  return 0;
}
