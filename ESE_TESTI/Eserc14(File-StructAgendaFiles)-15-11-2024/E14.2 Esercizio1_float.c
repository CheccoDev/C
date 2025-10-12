#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	float var = 12.1; 
	float var_letta;
	float var2_letta;
	FILE *f_txt;
	FILE *f_bin;
	// formato TESTO
	// scrittura valore singolo
	f_txt = fopen("esercizio1.txt", "w");
	if(f_txt==NULL){
		printf("Errore apertura file. Variabile w");
		return 1;
	}
	fprintf(f_txt, "%f", var);
	fclose(f_txt);
	// lettura valore singolo
	f_txt = fopen("esercizio1.txt", "r");
	if(f_txt==NULL){
		printf("Errore apertura file. Variabile r");
		return 1;
	}
	fscanf(f_txt, "%f", &var_letta);
	printf("valore letto: %f\n", var_letta);
	fclose(f_txt);
	
	var = 25.25;
	// formato BINARIO
	// scrittura valore singolo
	f_bin = fopen("esercizio1bin.txt", "wb");
	if(f_bin==NULL){
		printf("Errore apertura file. Variabile wb");
		return 1;
	}
	fwrite(&var, sizeof(var), 1, f_bin);
	//fwrite(&var, sizeof(float), 1, f_bin);
	fclose(f_bin);
	// lettura valore singolo
	f_bin = fopen("esercizio1bin.txt", "rb");
	if(f_bin==NULL){
		printf("Errore apertura file. Variabile rb");
		return 1;
	}
	fread(&var2_letta, sizeof(var), 1, f_bin);
	//fread(&var2_letta, sizeof(float), 1, f_bin);
	printf("valore letto binario: %f\n", var2_letta);
	fclose(f_bin);
		
  	return 0;
}







