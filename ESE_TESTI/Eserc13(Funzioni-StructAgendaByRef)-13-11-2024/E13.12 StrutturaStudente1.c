#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct Tstudente{
  int voto;
  char nome[20];
} Tstudente;

int casuale(int valmin, int valmax);
void stampa(Tstudente s);
void stampaTutto(const Tstudente s[], int dim);

int main(int argc, char *argv[]){
    Tstudente studenti[MAX];
    Tstudente studentiInBilico[MAX];
    int nsib =0;
    int i;
    srand(time(0));
    //inizializzazione
    for (i=0; i<MAX;i++) {
     do{   
      studenti[i].voto = casuale(1,40); 
     } while( (studenti[i].voto<16) || (studenti[i].voto>30)  ); 
     studenti[i].nome[0] = casuale('A', 'Z');
     studenti[i].nome[1] = casuale('a', 'z');
     studenti[i].nome[2] = casuale('a', 'z');
     studenti[i].nome[3] = casuale('a', 'z');
     studenti[i].nome[4] = '\0';
    }
    stampaTutto(studenti, MAX);
    //for (i=0;i<nsib;i++)
    //{ stampa(studenti[i]); }
    
    //elaborazione
    for (i=0;i<MAX;i++) {
      if ( (studenti[i].voto==16) || (studenti[i].voto==17) ) { 
         studentiInBilico[nsib]=studenti[i];
         nsib++;
       }
    }
    
    printf("\nIn bilico\n");
    // stampa
    stampaTutto(studentiInBilico,nsib);
    //for (i=0;i<nsib;i++)
    //{ stampa(studentiInBilico[i]); }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

void stampa(Tstudente s){
  printf("Studente=%s voto=%d\n",s.nome,s.voto);
}

void stampaTutto(const Tstudente s[],int dim){
  int i;
  for(i=0; i<dim; i++)
  { stampa(s[i]);}   
}

int casuale(int valmin, int valmax){
 return (rand()%(valmax-valmin+1)) + valmin;
}




