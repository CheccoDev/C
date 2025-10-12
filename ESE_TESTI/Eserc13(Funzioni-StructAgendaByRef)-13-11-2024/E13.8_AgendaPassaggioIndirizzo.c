#include <stdio.h>
#include <stdlib.h>
#define N_MAX_EVENTI 100

typedef struct TdataOra{ 
     int giorno;
     int mese;
     int anno;
     int ora;
     int minuti;
} TdataOra;

typedef enum {LEZIONE, PISCINA, APPUNTAMENTO, PALLAVOLO, STUDIO} Tattivita;

typedef struct Tevento{
   TdataOra inizio;
   TdataOra fine;
   Tattivita attivita;
} Tevento;

typedef struct Tagenda{
   Tevento eventi [N_MAX_EVENTI];
   int n_eventi;
} Tagenda;

TdataOra inizializzaData(int anno, int mese, int giorno, int ora, int minuti);
void stampaData(TdataOra d);
void stampaAttivita(Tattivita a);
void stampaEvento(Tevento e);
void stampaAgenda(Tagenda a);
Tagenda inizializzaAgenda();
Tagenda aggiungiEvento(Tagenda a, Tevento e);
Tevento inizializzaEvento(TdataOra inizio, TdataOra fine, Tattivita attivita);

void p_aggiungiEvento(Tagenda* pa, Tevento e);
void p_stampaAgenda(Tagenda *a);
void p_inizializzaAgenda(Tagenda *a);

void cancellaUltimoEvento(Tagenda * pa);
void cancellaEvento(Tagenda * pa, int pos);
void inserisciEvento(Tagenda * pa, int pos, Tevento e);

int main(int argc, char *argv[])
{
	TdataOra d1, d2;
	Tevento e;
	Tagenda a;

	//a = inizializzaAgenda();
	p_inizializzaAgenda(&a);
	
	d1 = inizializzaData(2010,6,10,10,30);
	d2 = inizializzaData(2010,6,10,11,30);
	e = inizializzaEvento(d1,d2,PISCINA);
	//a = aggiungiEvento(a, e);
	p_aggiungiEvento(&a, e);
	
	d1 = inizializzaData(2010,6,11,14,30);
	d2 = inizializzaData(2010,6,11,16,0);
	e = inizializzaEvento(d1,d2,STUDIO);
	//a = aggiungiEvento(a, e);
	p_aggiungiEvento(&a, e);

	d1 = inizializzaData(2010,7,11,16,0);
	d2 = inizializzaData(2010,6,11,16,30);
	e = inizializzaEvento(d1,d2,APPUNTAMENTO);
	//a = aggiungiEvento(a, e);
	p_aggiungiEvento(&a, e);

	//stampaAgenda(a);
	p_stampaAgenda(&a);
	
	//cancellaUltimoEvento(&a);
	//cancellaEvento(&a,2); //provare con posizioni 1 e 2
	inserisciEvento(&a,0,e);
	p_stampaAgenda(&a);                           //

  system("PAUSE");	
  return 0;
}


TdataOra inizializzaData(int anno, int mese, int giorno, int ora, int minuti){
    TdataOra daRitornare;
    daRitornare.anno = anno;
    daRitornare.mese = mese;
    daRitornare.giorno = giorno;
    daRitornare.ora = ora;
    daRitornare.minuti = minuti;
    return daRitornare;
}
void stampaData(TdataOra d){
	printf("%2d/%02d/%4d %02d:%02d",
		d.giorno,d.mese,d.anno,d.ora,d.minuti);
}

void stampaAttivita(Tattivita a){
  switch(a){
    case LEZIONE:
      printf("Lezione");
    break;
    case PISCINA:
      printf("Piscina");
    break;
    case APPUNTAMENTO:
      printf("Appuntamento");
    break;
    case PALLAVOLO: 
      printf("Pallavolo");
    break;
    case STUDIO:
      printf("Studio");
    break;
  }
}

Tevento inizializzaEvento(TdataOra inizio, TdataOra fine, Tattivita attivita){
   Tevento daRitornare;
   daRitornare.inizio = inizio;
   daRitornare.fine = fine;
   daRitornare.attivita = attivita;
   return daRitornare;
}

void stampaEvento(Tevento e){
   printf("Inizio: ");
   stampaData(e.inizio);
   printf("\n");
   printf("Fine: ");
   stampaData(e.fine);
   printf("\n");
   stampaAttivita(e.attivita);
}

Tagenda inizializzaAgenda(void){
   Tagenda daRitornare;
   daRitornare.n_eventi = 0;
   return daRitornare;
}
Tagenda aggiungiEvento(Tagenda a, Tevento e){
    if (a.n_eventi >= N_MAX_EVENTI){
      printf("Errore, l'agennda e' piena\n");
	} else {
      a.eventi[a.n_eventi] = e;
      a.n_eventi++;
    }
    return a;
}
void stampaAgenda(Tagenda a){
	int i;
	for (i = 0; i < a.n_eventi; i++){
		printf("Evento in posizione %d:\n", i);
		stampaEvento(a.eventi[i]);
		printf("\n\n");
	}
}

void p_aggiungiEvento(Tagenda* pa, Tevento e){
   	if (pa->n_eventi >= N_MAX_EVENTI){
      printf("Errore, l'agenda e' piena\n");
   	} else {
      pa->eventi[pa->n_eventi] = e;
      pa->n_eventi++;
    }
}
void p_inizializzaAgenda(Tagenda *a){
	a->n_eventi=0;	
}
void p_stampaAgenda(Tagenda *a){
	int i;
	for (i = 0; i < a->n_eventi; i++){
		printf("Evento in posizione %d:\n", i);
		stampaEvento(a->eventi[i]);
		printf("\n\n");
	}
}

void cancellaUltimoEvento(Tagenda* pa)
{ 	pa->n_eventi--; }

void cancellaEvento(Tagenda* pa, int pos)
{	if (pos>pa->n_eventi-1)
   	{ return;}
  	int i;
  	for (i=pos; i<pa->n_eventi-1; i++)
   	{ pa->eventi[i]=pa->eventi[i+1];  } 
  	pa->n_eventi--;  
}
void inserisciEvento(Tagenda * pa, int pos, Tevento e)
{
  if (pos>pa->n_eventi+1)
   { return;} 
  int i;
  for (i=pa->n_eventi; i>pos; i--)
   { pa->eventi[i]=pa->eventi[i-1];  }
   pa->n_eventi++;    
   pa->eventi[pos]=e; 
}
