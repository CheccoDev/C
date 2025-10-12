#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
  /*
  Calcolare la somma di tutti gli elementi compresi tra li e ls (inclusi)
  */
  int li, ls, p, i;
  //controllo input li>0
  printf("li="); scanf("%d",&li);
  while (li<=0){
  	printf("ERR li="); scanf("%d",&li);	
  }
  //controllo input ls>li
  printf("ls="); scanf("%d",&ls);
  while ( !(ls > li) ){	//oppure ls>=li
  	printf("ERR ls="); scanf("%d",&ls);	
  }
  //init p, invariante prodotto
  p = 1;
  //init variabile indice (contatore)
  i = li;
  while(i<=ls){
  	p *= i;	//update produttoria i
  	//p *= pow(i,3); //update produttoria i^3
  	i++;	//incremento variabile indice
  }
  printf("prodotto=%d\n",p);              
  
  system("PAUSE");  return 0;
}
