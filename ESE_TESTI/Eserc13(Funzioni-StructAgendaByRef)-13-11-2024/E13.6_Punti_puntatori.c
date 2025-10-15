#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Tpunto{ 
    float x, y, z;
} Tpunto;

typedef struct Tgrafico{
   Tpunto punti[MAX];
   int dim;
} Tgrafico;

int casuale(int min, int max);
Tgrafico init();
Tpunto init_punto();
void stampa(Tgrafico a);
Tgrafico filtra(Tgrafico a, float limite);
int minore(Tpunto p, float limit);

void p_init(Tgrafico *a);
void p_init_punto(Tpunto *p);
void p_stampa(const Tgrafico *a);
Tgrafico p_filtra(const Tgrafico *a, float limite);


int main(int argc, char *argv[]) {
	Tgrafico g;
/*	g = init();
	printf("\nPunti grafico\n");
	stampa(g);
	
	Tgrafico w;
	w = filtra(g, 12.25);
	printf("\nPunti filtrati\n");
	stampa(w);
*/
	p_init(&g);
	printf("\nPunti grafico\n");
	p_stampa(&g);
	
	Tgrafico w;
	w = p_filtra(&g, 12.25);
	printf("\nPunti filtrati\n");
	p_stampa(&w);
		
  	system("PAUSE");	
  	return 0;
}

int casuale(int min, int max){
	return rand()%(max-min+1)+min;
}
Tgrafico init(){
	int i;
	Tgrafico daRit;
	printf("dimensione: "); scanf("%d", &(daRit.dim));
	for(i=0 ; i<daRit.dim ; i++){
		daRit.punti[i] = init_punto();
	}
	return daRit;
}
Tpunto init_punto(){
	Tpunto daRit;
	daRit.x = casuale(-1000, 1000)/100.0;
	daRit.y = casuale(-1000, 1000)/100.0;
	daRit.z = casuale(-1000, 1000)/100.0;
	return daRit;
}
void stampa(Tgrafico a){
	int i;
	for(i=0 ; i<a.dim ; i++){
		printf("%.2f %.2f %.2f\n", a.punti[i].x, a.punti[i].y, a.punti[i].z );
	}
}
int minore(Tpunto p, float limit){
	return p.x*p.x + p.y*p.y + p.z*p.z < limit*limit;
}
Tgrafico filtra(Tgrafico a, float limite){
	Tgrafico daRit;
	daRit.dim=0;
	int i;
	for(i=0 ; i<a.dim ; i++){
		if( minore(a.punti[i], limite ) ){
			daRit.punti[ daRit.dim ] = a.punti[i];
			daRit.dim++;
		}
	}
	return daRit;
}


void p_init(Tgrafico *a){
	int i;
	printf("dimensione: "); scanf("%d", &(a->dim));
	for(i=0 ; i<a->dim ; i++){
		//a->punti[i] = init_punto();
		p_init_punto( &a->punti[i] );
	}
}
void p_init_punto(Tpunto *p){
	p->x = casuale(-1000, 1000)/100.0;
	p->y = casuale(-1000, 1000)/100.0;
	p->z = casuale(-1000, 1000)/100.0;
}
void p_stampa(const Tgrafico *a){
	int i;
	//a->dim == (*a).dim
	for(i=0 ; i<a->dim ; i++){
		printf("%.2f %.2f %.2f\n", a->punti[i].x, a->punti[i].y, a->punti[i].z );
	}
}
Tgrafico p_filtra(const Tgrafico *a, float limite){
	Tgrafico daRit;
	daRit.dim=0;
	int i;
	for(i=0 ; i<a->dim ; i++){
		if( minore(a->punti[i], limite ) ){
			daRit.punti[ daRit.dim ] = a->punti[i];
			daRit.dim++;
		}
	}
	return daRit;
}


