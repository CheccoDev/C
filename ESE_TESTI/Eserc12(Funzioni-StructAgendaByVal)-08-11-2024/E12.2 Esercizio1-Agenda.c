#include <stdio.h>
#include <stdlib.h>
#define N_MAX_EVENTI 10

typedef enum {LEZIONE, PISCINA, APPUNTAMENTO, PALLAVOLO, STUDIO} Tattivita;

typedef struct Tdata{ 
     int mese;
     int anno;
     int giorno;
} Tdata;

typedef struct Tevento{

/*da implementare per esercizio 2*/

} Tevento;

typedef struct Tagenda{

/*da implementare per esercizio 3*/

} Tagenda;

Tdata inizializzaData(int anno, int mese, int giorno);
void stampaData(Tdata d);

/*da implementare per esercizio 1*/
int confrontaDate(Tdata d1, Tdata d2);

/*da implementare per esercizio 2*/
void stampaAttivita(Tattivita a);
void stampaEvento(Tevento e);
Tevento inizializzaEvento(Tdata inizio, Tdata fine, Attivita attivita);

/*da implementare per esercizio 3*/
Tagenda inizializzaAgenda();
void stampaAgenda(Tagenda a);
Tagenda aggiungiEvento(Tagenda a, Tevento e);


int main(int argc, char *argv[])
{
  Tdata d1;
  d1 = inizializzaData(2009,6,10);
  stampaData(d1);

  system("PAUSE");	
  return 0;

}



void stampaData(Tdata d){
	printf("%2d/%2d/%4d",d.giorno,d.mese,d.anno);
}

Data inizializzaData(int anno, int mese, int giorno){
    Tdata daRitornare;
    daRitornare.anno = anno;
    daRitornare.mese = mese;
    daRitornare.giorno = giorno;
    return daRitornare;
}

int confrontaDate(Tdata d1, Tdata d2){
  if (d1.anno<d2.anno) { return -1; }
  if (d1.anno>d2.anno) { return +1; } 
  if (d1.mese<d2.mese) { return -1; }
  if (d1.mese>d2.mese) { return +1; }
  if (d1.giorno<d2.giorno) { return -1; }
  if (d1.giorno>d2.giorno) { return +1; } 
  if (d1.ora<d2.ora) { return -1; }
  if (d1.ora>d2.ora) { return +1; }    
  if (d1.minuti<d2.minuti) { return -1; }
  if (d1.minuti>d2.minuti) { return +1; } 
  return 0;   
}




