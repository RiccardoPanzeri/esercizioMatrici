#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prototipi.h"

int main() {
	srand(time(0));
	int const righe = 5;
	int const colonne = 5;
	int const dim = 4;
	float array1[dim];
	float array2[dim];
	int m1[righe][colonne];
	float mediaR = 0;
	float mediaC = 0;
	float massimo = 0;
	float minimo = 0;

	//carico la matrice;
	caricaM(m1, righe, colonne);
	//visualizzo la matrice;
	visualizzaM(m1, righe, colonne);
	//calcolo la somma per righe e effettuo la media;
	mediaR = mediaSommaR(m1, righe, colonne);
	printf("\n\nla media della somma per righe è: %.2f\n", mediaR);
	//calcolo la somma per colonne e effettuo la media;
	mediaC = mediaSommaC(m1, righe, colonne);
	printf("la media della somma per colonne è: %.2f\n", mediaC);
	//trovo il numero minimo e massimo nella matrice:
	massimo = nMassimo(m1, righe, colonne);
	printf("il numero massimo è: %.0f\n", massimo);
	minimo = nMinimo(m1, righe, colonne);
	printf("il numero minimo è: %.0f\n\n\n", minimo);
	//carico e visualizzo il contenuto del vettore;
	printf("Visualizzo il primo array:\n");
	caricaArray(array1, dim, mediaR, mediaC, massimo, minimo);
	visualizzaV(array1, dim);
	//scrivo il conenuto dell'array su file;
	printf("\nSto salvando su file il contenuto del primo array...\n");
	scriviV(array1, dim);
	//leggo il contenuto del file e lo posizione nel secondo array;
	printf("\n\nVisualizzo il secondo array (caricato leggendo dal file): \n\n");
	leggiV(array2, dim);
	visualizzaV(array2, dim);





	return 0;
}