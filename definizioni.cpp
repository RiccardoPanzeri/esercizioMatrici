#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prototipi.h"

void caricaM(int matrice[][5], int righe, int colonne) {
	for (int i = 0; i < righe; i++) {
		for (int j = 0; j < colonne; j++) {
			matrice[i][j] = (rand() % 90) + 10;
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