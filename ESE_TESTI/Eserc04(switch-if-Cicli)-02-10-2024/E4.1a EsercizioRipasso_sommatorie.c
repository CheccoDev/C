#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
  /*
  Calcolare la somma di tutti gli elementi compresi tra li e ls (inclusi)
  */
  int li, ls, s, i;
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
  //init s, invariante somma
  s = 0;
  //init variabile indice (contatore)
  i = li;
  while(i<=ls){
  	//s += i;	//update sommatoria i
  	//s += pow(i,3); //update sommatoria i^3
  	i++;	//incremento variabile indice
  }
  printf("somma=%d\n",s);              
  
  system("PAUSE");  return 0;
}
