#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prototipi.h"

void caricaM(int matrice[][5], int righe, int colonne) {
	for (int i = 0; i < righe; i++) {
		for (int j = 0; j < colonne; j++) {
			matrice[i][j] = rand() % 10;
		}
	}
}

void visualizzaM(int matrice[][5], int righe, int colonne) {
	for (int i = 0; i < righe; i++) {
		for (int j = 0; j < colonne; j++) {
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
}

float mediaSommaR(int matrice[][5], int righe, int colonne) {
	float somma = 0;
	float media = 0;
	for (int i = 0; i < righe; i++) {
		for (int j = 0; j < colonne; j++) {
			somma += matrice[i][j];
		}
	}
	
	media = somma / righe;

	return media;

}

float mediaSommaC(int matrice[][5], int righe, int colonne) {
	float somma = 0;
	float media = 0;
	for (int j = 0; j < colonne; j++) {
		for (int i = 0; i < righe; i++) {
			somma += matrice[i][j];
		}
	}
	
	media = somma / colonne;
	
	return media;

}

float nMassimo(int matrice[][5], int righe, int colonne) {
	float max = 0;
	for (int i = 0; i < righe; i++) {
		for (int j = 0; j < colonne; j++) {
			if (matrice[i][j] > max) {
				max = matrice[i][j];
			}
		}
	}
	return max;
}
float nMinimo(int matrice[][5], int righe, int colonne) {
	float min = matrice[0][0];
	for (int i = 0; i < righe; i++) {
		for (int j = 0; j < colonne; j++) {
			if (matrice[i][j] < min) {
				min = matrice[i][j];
			}
		}
	}
	return min;
}

void caricaArray(float array[], int dim, float mediaR, float mediaC, float max, float min) {
	array[0] = mediaR;
	array[1] = mediaC;
	array[2] = max;
	array[3] = min;
}

void visualizzaV(float array[], int dim) {
	printf("media somma righe: %.2f\n", array[0]);//posso modificare, tramite la stringa di formattazione, quante cifre dopo la virgola verranno visualizzate in stampa, ma in realtà il numero effettivo non viene arrotondato;
	printf("media somma colonne: %.2f\n", array[1]);
	printf("numero massimo: %.0f\n", array[2]);//se voglio visualizzare il numero intero, mi basta azzerare le cifre dopo la virgola visualizzate in stampa;
	printf("numero minimo: %.0f\n", array[3]);
	
}

void scriviV(float array[], int dim) {
	FILE* fp;
	fp = fopen("testo.txt", "w");
	for (int i = 0; i < dim; i++) {
		fprintf(fp, "%.2f\n", array[i]);//fscanf()  legge senza problemi i numeri se separati da /n. se invece sono sulla stessa riga e separati da una virgola, legge solo il primo numero e poi si ferma.

	}
	fclose(fp);
}

void leggiV(float array[], int dim) {
	FILE* fp;
	fp = fopen("testo.txt", "r");
	for (int i = 0; i < dim; i++) {
		fscanf(fp, "%f", &array[i]);
	}
	fclose(fp);

}

int modaM(int matrice[][5], int righe, int colonne) {
	int const dim = 25;
	int valori[dim];//array che conterrà tutti i valori che compaiono nella matrice, in modo da poterli comparare;
	int x = 0;//indice dell'array che conterrà i valori contenuti nella matrice, in modo da poterli confrontare;
	int moda = 0;
	int max = 0;//variabile contenete il numero massimo in cui compare lo stesso valore;
	int cont = 0;//contatore per tenere traccia volta per volta di quante volte un valore compare nella matrice;
	for (int i = 0; i < righe; i++) {//inserisco nel vettore tutti i valori contenuti nella matrice;
		for (int j = 0; j < colonne; j++) {
			valori[x] = matrice[i][j];
			x++;
		}

	}
	
	for (x = 0; x < dim; x++) {//paragono tutti i valori contenuti nell'array a quelli contenuti nella matrice, per verificare qaunte volte un valore si ripete; 
		for (int i = 0; i < righe; i++) {
			for (int j = 0; j < colonne; j++) {
				if (matrice[i][j] == valori[x]) {//se un valore si ripete, incremento il contatore;
					cont++;
				}
			}

		}
		if (cont > max) {//ogni volta che il contatore supera il numero massimo di ripetizioni, la moda viene aggiornata;
			max = cont;//anche il numero massimo di ripetizioni da superare viene aggiornato;
			moda = valori[x];
		}
		cont = 0;//azzero il contatore ogni volta, per poter contare da zero le ripetizioni del prossimo valore;
	}

	return moda;
}


int medianaM(int matrice[][5], int righe, int colonne) {
	int const dim = 25;
	int valori[dim];//array contenente i valori che compaiono nella matrice;
	int x = 0;//indice del vettore contenente i valori della matrice;
	int temp = 0; //variabile d'appoggio necessaria per ordinare il vettore;
	int mediana = 0;

	for (int i = 0; i < righe; i++) {
		for (int j = 0; j < colonne; j++) {
			valori[x] = matrice[i][j];
			x++;
		}
	}

	for (x = 0; x < dim - 1; x++) {//riordino l'array tramite bubble sort;
		for (int j = 0; j < dim - 1; j++) {
			if (valori[j] > valori[j + 1]) {
				temp = valori[j];
				valori[j] = valori[j + 1];
				valori[j + 1] = temp;

			}
		}
	}

	mediana = valori[12];//12 invece di 13, perchè l'array parte da zero: essendo la matrice composta da 25 elementi, voglio individuare il tredicesimo, in modo da avere 12 numeri rimanenti a destra e 12 a sinistra;
	return mediana;



}