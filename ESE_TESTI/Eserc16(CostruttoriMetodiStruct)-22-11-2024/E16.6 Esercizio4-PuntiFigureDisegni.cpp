
#include <iostream>
#include <cmath>
#include <cstdlib>
#define MAXP 10

using namespace std;

int random(int min, int max);

struct Tpunto{
	float x, y;
	Tpunto(){
		x = y = 1.0;
	}
	Tpunto(float _x, float _y){
		x = _x;
		y = _y;
	}
	float distanzaDa0()const{
		return sqrt(x*x + y*y);
	}
	float distanza(Tpunto p)const{
		return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
	}
	float distanza2(const Tpunto* p)const{
		return sqrt((x - p->x)*(x - p->x) + (y - p->y)*(y - p->y));
	}	
	void stampa()const{
		cout << x << " " << y;
	}
};
struct Tfigura{
	Tpunto punti[MAXP];
	int n;
	Tfigura(){
		n=0;
	}
	Tfigura(int _n){
		n = _n;
		int i;
		for(i=0 ; i<_n ; i++){
			punti[i] = Tpunto( random(0, 100)/10.0, random(0, 100)/10.0);
		}
	}
	void stampa()const{
		int i;
		for(i=0 ; i<n ; i++){
			cout << "[";
			punti[i].stampa();
			cout << "]";
		}
			
	}
	float lunghezza()const{
		int i; float len=0;
		for(i=0 ; i<n-1 ; i++)
			len += punti[i].distanza(punti[i+1]);
		return len;
	}
	Tpunto puntoPiuLontanoDa0()const{
		// Ipotesi: c'e' almeno un punto presente nell'array
		int i; 
		int imax=0;
		float lenmax = punti[0].distanzaDa0();
		for(i=0 ; i<n ; i++)
			if( lenmax < punti[i].distanzaDa0() ){
				lenmax = punti[i].distanzaDa0();
				imax = i;
			}
		return punti[imax];
	}
};

struct Tdisegno{
	Tfigura *figure;
	int nf;
	
	Tdisegno(){
		// lecito anche avere disegno vuoto:
		// nf = 0; figure = NULL;
		// Possibiliemnte da evitre: 
		// crea alcuni problemi di controllo in fase
		// di utilizzo dei dati e de-allocazione
		// MEGLIO allocare con dimensione scelta a priori
		nf = 3;
		figure = new Tfigura[3];
	}
	Tdisegno(int _nf){
		figure = new Tfigura[_nf];
		nf = _nf;
		int i;
		for(i=0 ; i<_nf ; i++){
			figure[i] = Tfigura( random(0, MAXP) );
		}
	}
	~Tdisegno(){
		delete[] figure;
		cout << "distrutture disegno" << endl;
	}
	Tfigura figuraConLunghezzaMaggiore()const{
		int i; 
		int imax = 0;
		float lmax = figure[0].lunghezza();
		for(i=0 ; i<nf ; i++){
			if( figure[i].lunghezza() > lmax ){
				lmax = figure[i].lunghezza();
				imax = i;
			}
		}
		return figure[imax];
	} 
	Tfigura figuraConPuntoPiuDistanteDa0()const{
		int i; 
		int imax = 0;
		float lmax = figure[0].puntoPiuLontanoDa0().distanzaDa0();
		for(i=0 ; i<nf ; i++){
			if( figure[i].puntoPiuLontanoDa0().distanzaDa0() > lmax ){
				lmax = figure[i].puntoPiuLontanoDa0().distanzaDa0();
				imax = i;
			}
		}
		return figure[imax];
	}
	void stampa()const{
		int i;
		for(i=0 ; i<nf ; i++){
			cout << "figura " << i << endl;
			figure[i].stampa();
			cout << endl;
		}
	}

};

void salvaDisegno(const Tdisegno* d);
void salvaDisegnoBin(const Tdisegno *d);
void leggiDisegno(Tdisegno *d);
void leggiDisegnoBin(Tdisegno *d);

typedef Tfigura* figuraptr;

int main(int argc, char *argv[]){
	Tdisegno d1;
	cout << "disegno 1" << endl;
	d1.stampa();
	cout << endl;
	
	Tdisegno d2(3);
	cout << "disegno 2" << endl;
	d2.stampa();
	cout << endl;
	
	Tdisegno d3 = Tdisegno(4);
	cout << "disegno 3" << endl;
	d3.stampa();
	cout << endl;
	
	Tfigura f;
	f = d2.figuraConLunghezzaMaggiore();
	cout << " disegno 2: lunghezza figura maggiore" << endl;
	cout << f.lunghezza();
	cout << endl;
	
	cout << " disegno 3: lunghezza figura maggiore" << endl;
	cout << d3.figuraConLunghezzaMaggiore().lunghezza();
	cout << endl;
	
	Tpunto p;
	f = d2.figuraConPuntoPiuDistanteDa0();
	p = f.puntoPiuLontanoDa0();
	cout << " disegno 2: punto piu lontano da origine" << endl;
	p.stampa();
	cout << endl;
	
	cout << " disegno 3: punto piu lontano da origine" << endl;
	d3.figuraConPuntoPiuDistanteDa0().puntoPiuLontanoDa0().stampa();
	cout << endl;
	
	salvaDisegno(&d2);
	salvaDisegnoBin(&d3);
	leggiDisegno(&d1);
	cout << "disegno letto 1" << endl;
	d1.stampa();
	cout << endl;
	leggiDisegnoBin(&d1);
	cout << "disegno letto 2" << endl;
	d1.stampa();
	cout << endl;
	
	cout << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(int*) << endl;
	cout << sizeof(char) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(Tdisegno) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(figuraptr) << endl;
	cout << sizeof(d1) << endl;
	
	cout << sizeof(d1.nf) << endl;
	cout << sizeof(Tfigura) << endl;
	system("pause"); 
	return 0;
}

int random(int min, int max){
	return rand()%(max-min+1)+min;
}
void salvaDisegno(const Tdisegno *d){
	FILE* f;
	int i, j;
	f = fopen("disegno.txt", "w");
	if(f==NULL) return;
	fprintf(f, "%d\n", d->nf);
	for(i=0 ; i<d->nf ; i++){
		fprintf(f, "%d\n", d->figure[i].n);
		for(j=0 ; j<d->figure[i].n ; j++){
			fprintf(f, "[%f %f]\n", d->figure[i].punti[j].x, d->figure[i].punti[j].y);
		}
	}
	fclose(f);
}
void salvaDisegnoBin(const Tdisegno *d){
	FILE* f;
	f = fopen("disegno_dim_bin.txt", "wb");
	if(f==NULL) return;
	fwrite(&d->nf, sizeof(int), 1, f);
	fclose(f);
	
	f = fopen("disegno_bin.txt", "wb");
	if(f==NULL) return;
	fwrite(d->figure, sizeof(Tfigura), d->nf, f);
	fclose(f);
}
void leggiDisegno(Tdisegno *d){
	FILE* f;
	int i, j;
	f = fopen("disegno.txt", "r");
	if(f==NULL) return;
	fscanf(f, "%d\n", &d->nf);
	d->figure = new Tfigura[d->nf];
	for(i=0 ; i<d->nf && !feof(f) ; i++){
		fscanf(f, "%d\n", &d->figure[i].n);
		for(j=0 ; j<d->figure[i].n && !feof(f) ; j++){
			fscanf(f, "[%f %f]\n", &d->figure[i].punti[j].x, &d->figure[i].punti[j].y);
		}
	}
	fclose(f);
}
void leggiDisegnoBin(Tdisegno *d){
	FILE* f;
	f = fopen("disegno_dim_bin.txt", "rb");
	if(f==NULL) return;
	fread(&d->nf, sizeof(int), 1, f);
	fclose(f);

	f = fopen("disegno_bin.txt", "rb");
	if(f==NULL) return;
	d->figure = new Tfigura[d->nf];
	fread(d->figure, sizeof(Tfigura), d->nf, f);
	fclose(f);
}
