
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
		//return sqrt(x*x + y*y);
		Tpunto p(0,0);
		return distanza2(&p);
	//	return distanza(Tpunto(0,0));
	}
	//float distanza(const Tpunto p)const{
	float distanza(const Tpunto &p)const{
		//return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
		return sqrt(pow(x-p.x,2) + pow(y-p.y,2));
	}
	float distanza2(const Tpunto *p)const{
		//return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
		return sqrt(pow(x-p->x,2) + pow(y-p->y,2));
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


int main(int argc, char *argv[]){
	Tpunto p(2.1, 6.5);
	p.stampa();
	
	Tfigura f1;
	f1 = Tfigura();
	cout << "f1" << endl;
	f1.stampa();
	cout << endl;
	
	Tfigura f2 = Tfigura();
	cout << "f2" << endl;
	f2.stampa();
	cout << endl;
	
	Tfigura f3 = Tfigura(3);
	//oppure Tfigura f3(3);
	cout << "punti di f3:";
	f3.stampa();
	cout << endl;
	
	Tfigura f4 = Tfigura(5);
	cout << "punti di f4:";
	f4.stampa();
	cout << endl;
	
	cout << "lunghezze:" << endl;
	cout << "f3:" << f3.lunghezza() << endl;
	cout << "f4:" << f4.lunghezza() << endl;
	
    cout << "punto piu' distante dall'origine di f3:";
	p = f3.puntoPiuLontanoDa0();
	p.stampa();
	cout << endl;
	
	cout << "punto piu' distante dall'origine di f4:";
	f4.puntoPiuLontanoDa0().stampa();
	cout << endl;

	system("pause"); 
	return 0;
}

int random(int min, int max){
	return rand()%(max-min+1)+min;
}

