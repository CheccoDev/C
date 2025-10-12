#include <cstdlib>
#include <iostream>
#define N 3
typedef struct Tstudente{
 char nome[20];
 int voto;
}Tstudente;
typedef Tstudente studenti[N];
typedef struct S_respinti{
  Tstudente studenti[N];
  int dim;       
} S_respinti;

void init(studenti mieis,int dim);
void stampaLista(const studenti mieis, int dim);
void stampaStudente(Tstudente mios);
S_respinti DaInterrogare(studenti mieis, int dim);

int main(){ 
 studenti s;
 init (s,N);
 stampaLista(s, N);
 
 S_respinti sr;
 sr=DaInterrogare(s,N);
 printf("\nDa interrogare\n");
 stampaLista(sr.studenti, sr.dim);
   
system("PAUSE");
return EXIT_SUCCESS;
}

S_respinti DaInterrogare(studenti mieis, int dim){
  S_respinti R;
  R.dim=0;
  int i, j=0;
  for (i=0; i<dim; i++)  {
    if (mieis[i].voto<18)    {
       R.studenti[j] = mieis[i];
       j++;
       R.dim++;                
    }    
  }
  return R;         
}
void stampaStudente(Tstudente mios){
  printf("[%s]",mios.nome);
  printf(" voto=%3d",mios.voto);
  printf("\n");    
}
void stampaLista(const studenti mieis, int dim){
 int i;
 for(i=0; i<dim; i++) { 
   stampaStudente(mieis[i]);       
   //printf("[%s] ",mieis[i].nome);
   //printf(" voto=%3d \n",mieis[i].voto);
 }    
}
void init(studenti mieis,int dim){
  int i;
  for (i=0; i<dim; i++)  {
  	printf("nome: ");
    scanf("%s",mieis[i].nome);
	printf("voto: ");  
    scanf("%d",&mieis[i].voto);
  }   
}




