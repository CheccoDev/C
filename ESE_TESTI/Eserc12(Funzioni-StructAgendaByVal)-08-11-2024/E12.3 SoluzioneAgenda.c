#include <stdio.h>
#include <stdlib.h>
#define N_MAX_EVENTI 10

typedef enum {LEZIONE, PISCINA, APPUNTAMENTO, PALLAVOLO, STUDIO} Tattivita;

typedef struct Tdata{ 
     int mese;
     int anno;
     int giorno;
     int ora;
     int minuti;
} Tdata;

typedef struct Tevento{
   Tdata inizio;
   Tdata fine;
   Tattivita attivita;
} Tevento;

typedef struct Tagenda{
   Tevento eventi [N_MAX_EVENTI];
   int n_eventi;
} Tagenda;


Tdata inizializzaData(int anno, int mese, int giorno, int ora, int minuti);
void stampaData(Tdata d);
void stampaAttivita(Tattivita a);
void stampaEvento(Tevento e);
void stampaAgenda(Tagenda a);
Tagenda inizializzaAgenda();
Tagenda aggiungiEvento(Tagenda a, Tevento e);
Tevento inizializzaEvento(Tdata inizio, Tdata fine, Tattivita attivita);

int main(int argc, char *argv[]){
	Tdata d1, d2;
	Tevento e;
	Tagenda a;

	a = inizializzaAgenda();

	d1 = inizializzaData(2009,6,10,10,30);
	d2 = inizializzaData(2009,6,10,11,30);
	e = inizializzaEvento(d1,d2,PISCINA);
	a = aggiungiEvento(a, e);

	d1 = inizializzaData(2009,6,11,14,30);
	d2 = inizializzaData(2009,6,11,16,0);
	e = inizializzaEvento(d1,d2,STUDIO);
	a = aggiungiEvento(a, e);

	d1 = inizializzaData(2009,7,11,16,0);
	d2 = inizializzaData(2009,6,11,16,30);
	e = inizializzaEvento(d1,d2,APPUNTAMENTO);
	a = aggiungiEvento(a, e);

	stampaAgenda(a);

  system("PAUSE");	
  return 0;
}


Tdata inizializzaData(int anno, int mese, int giorno, int ora, int minuti){
    Tdata daRitornare;
    daRitornare.anno = anno;
    daRitornare.mese = mese;
    daRitornare.giorno = giorno;
    daRitornare.ora = ora;
    daRitornare.minuti = minuti;
    return daRitornare;
}

void stampaData(Tdata d){
	printf("%2d/%2d/%4d %02d:%02d",d.giorno,d.mese,d.anno,d.ora,d.minuti);
}

void stampaAttivita(Tattivita a){
    switch(a){
        case LEZIONE: printf("Lezione"); break;
        case PISCINA: printf("Piscina"); break; 
		case APPUNTAMENTO: printf("Appuntamento"); break;
        case PALLAVOLO: printf("Pallavolo"); break;
        case STUDIO: printf("Studio"); break;
    }
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

void stampaAgenda(Tagenda a){
	int i;
	for (i = 0; i < a.n_eventi; i++){
		printf("Evento in posizione %d:\n", i);
		stampaEvento(a.eventi[i]);
		printf("\n\n");
	}
}

Tagenda inizializzaAgenda(){
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

Tevento inizializzaEvento(Tdata inizio, Tdata fine, Tattivita attivita){
   Tevento daRitornare;
   daRitornare.inizio = inizio;
   daRitornare.fine = fine;
   daRitornare.attivita = attivita;
   return daRitornare;
}


