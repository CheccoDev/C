#include <stdio.h>
#include <stdlib.h>
#define N 20
typedef struct Tvoti{
 int voti[N];
 int dim;       
} Tvoti;
void initvoti(int v[],int dim);
void stampa(int v[], int dim);
void p_stampa(const Tvoti *v);
Tvoti selezioneVoti(int v[], int dim);

int main(int argc, char *argv[]){
  int voti[N];
  Tvoti orali;
  initvoti(voti, N);
  stampa(voti, N);
  orali=selezioneVoti(voti, N);
  //stampa(orali.voti, orali.dim);
  p_stampa(&orali);
  printf("\n");
  system("PAUSE");	return 0;
}

Tvoti selezioneVoti(int v[], int dim){
  Tvoti sel;
  int i;
  sel.dim=0;
  for (i=0; i<dim;i++)
  {
     if ((v[i]>=18) && (v[i]<=22))
     {
       sel.voti[sel.dim]=v[i];
       sel.dim++;
     } 
  }     
  return sel;       
}

void initvoti(int v[],int dim){
  int i;
  for(i=0;i<dim;i++)
  { v[i]=rand()%(30-18+1)+18; }
}
void stampa(int v[], int dim){
  int i;
  for (i=0; i<dim; i++)
  {  printf("%4d",v[i]);   }
  printf("\n");
}
void p_stampa(const Tvoti *v){
  int i;
  for (i=0; i<v->dim; i++)
  {  printf("%4d",v->voti[i]);   }
  printf("\n");
}

