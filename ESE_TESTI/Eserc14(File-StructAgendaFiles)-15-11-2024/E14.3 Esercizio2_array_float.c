#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *f_txt;
	FILE *f_bin;	
	float vet[5] = {0.0,1.0,4.0,9.0,16.0};
	float vet_letto[5];
	float vet_letto2[5];
	int i; int dim;
	// formato TESTO
	// scrittura array
	// prima riga: numero elementi
	// righe successive: elementi
	f_txt = fopen("esercizio2array.txt", "w");
	if(f_txt==NULL){
		printf("Errore apertura file. Array w");
		return 1;
	}
	fprintf(f_txt, "%d\n", 5);
	for(i=0 ; i<5 ; i++){
		fprintf(f_txt, "%f\n", vet[i]);	
	}
	fclose(f_txt);
	// lettura array - opzione 1
	f_txt = fopen("esercizio2array.txt", "r");
	if(f_txt==NULL){
		printf("Errore apertura file. Array r");
		return 1;
	}
	fscanf(f_txt, "%d", &dim);
	/*
	// con dimensione nota
	i=0;
	while( i<dim ){
		fscanf(f_txt, "%f", &vet_letto[i]);
		i++;	
	}
	*/
	// ipotizzando di non avere dimensione nota
	// --> non presente il primo dato
	i=0;
	// opzione 1 -- utilizzo feof
	while( !feof(f_txt) ){
		fscanf(f_txt, "%f", &vet_letto[i]);
		i++;	
	}
	printf("valori letti: ");
	for(i=0 ; i<dim ; i++){
		printf("%f ", vet[i]);	
	}
	printf("\n");
	fclose(f_txt);
	
	// lettura array - opzione 2
	f_txt = fopen("esercizio2array.txt", "r");
	if(f_txt==NULL){
		printf("Errore apertura file. Array r (2)");
		return 1;
	}
	fscanf(f_txt, "%d", &dim);
	// se la dimensione dim non fosse nota... 
	i=0;
	// opzione 2 -- utilizzo valore return scanf
	while( fscanf(f_txt, "%f", &vet_letto2[i])==1 ){
		i++;	
	}
	printf("valori letti (2): ");
	for(i=0 ; i<dim ; i++){
		printf("%f ", vet_letto2[i]);	
	}
	printf("\n");
	fclose(f_txt);
	
	float vet2[5] = {10.0,20.0,30.0,40.0,50.0};
	float vet2_letto[5];
	float vet3_letto[5]; 
	int n;
	// formato BINARIO
	// scrittura array
	f_bin = fopen("esercizio2arraybin.txt", "wb");
	if(f_bin==NULL){
		printf("Errore apertura file. Array wb");
		return 1;
	}
	fwrite(vet2, sizeof(float), 5, f_bin);
	fclose(f_bin);
	// lettura arrray
	f_bin = fopen("esercizio2arraybin.txt", "rb");
	if(f_bin==NULL){
		printf("Errore apertura file. Array rb 1");
		return 1;
	}
	// numero elementi noto a priori
	fread(&vet2_letto, sizeof(float), 5, f_bin);
	printf("valori letti binari (1): ");
	for(i=0 ; i<5 ; i++){
		printf("%f ", vet2_letto[i]);	
	}
	printf("\n");
	fclose(f_bin);
	
	
	// lettura array
	f_bin = fopen("esercizio2arraybin.txt", "rb");
	if(f_bin==NULL){
		printf("Errore apertura file. Array rb 2");
		return 1;
	}
	// numero elementi non noto
	dim=0;
	while( !feof(f_bin) ){
		fread(&vet3_letto[dim], sizeof(float), 1, f_bin);
		if( !feof(f_bin) )
			dim++;
	}
	
	printf("valori letti binari (2): ");
	for(i=0 ; i<dim ; i++){
		printf("%f ", vet3_letto[i]);	
	}
	printf("\n");
	fclose(f_bin);
	
  	system("PAUSE");	
  	return 0;
}







