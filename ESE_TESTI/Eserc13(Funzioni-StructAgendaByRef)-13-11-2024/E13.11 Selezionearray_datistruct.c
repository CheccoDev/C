#include <stdio.h>
#include <stdlib.h>
#define N 3
typedef struct Tpersona{
  char nome[21];   
  int anno;   
} Tpersona;
typedef struct Tcollezione{
  Tpersona p[N];
  int dim;     
} Tcollezione;

void initpers(Tpersona p[],int dim);
void initpers_casuale(Tpersona p[],int dim);
Tcollezione selezionePers(const Tpersona p[], int dim, int a);
int casuale(int min, int max);
void stampa(const Tpersona p[], int dim);
void p_stampa(const Tcollezione *c);

int main(){
  Tpersona persone[N];
  Tcollezione magg;
  int i;  
  //initpers(persone, N); 
  initpers_casuale(persone, N);
  stampa(persone, N);
  
  magg=selezionePers(persone, N, 2017);
  stampa(magg.p, magg.dim);
  //p_stampa(&mapp);
 system("PAUSE");	return 0;   
}

Tcollezione selezionePers(const Tpersona p[], int dim, int a){
  Tcollezione mioElenco;
  int i;
  mioElenco.dim=0;
  for(i=0; i<dim; i++)  {
     if (a-p[i].anno>=18)     {
      // mioElenco.p[mioElenco.dim].anno=p[i].anno;
      // mioElenco.p[mioElenco.dim].nome=p[i].nome; --> no --> strcpy
      mioElenco.p[mioElenco.dim]=p[i];
       mioElenco.dim++;
     }       
  }
  return mioElenco;
}
void initpers(Tpersona p[],int dim){
  int i;
  for (i=0; i<dim; i++)  {
    printf("nome=");scanf("%s",p[i].nome); 
    printf("anno=");scanf("%d",&p[i].anno); 
  }   
}
int casuale(int min, int max){
  return rand()%(max-min+1)+min;
}
void initpers_casuale(Tpersona p[],int dim){
  int i;
  for (i=0; i<dim; i++)  {
    p[i].anno = casuale(1970, 2010);
    p[i].nome[0] = casuale('A', 'Z');
    p[i].nome[1] = casuale('a', 'z');
    p[i].nome[2] = casuale('a', 'z');
    p[i].nome[3] = casuale('a', 'z');
    p[i].nome[4] = '\0';
  }   
}
void stampa(const Tpersona p[], int dim){
	int i;
	for(i=0; i<dim; i++)  {
	 	printf("nome=%s anno=%d \n",p[i].nome, p[i].anno); 
  	}
	printf("\n");	
}
void p_stampa(const Tcollezione *c){
	int i;
	for(i=0; i<c->dim; i++)  {
	 	printf("nome=%s anno=%d \n",c->p[i].nome, c->p[i].anno); 
  	}
  	printf("\n");
  	/* 
	//oppure
  	stampa(c->p, c->dim);
  	*/
}

