void caricaM(int matrice[][5], int righe, int colonne);
void visualizzaM(int matrice[][5], int righe, int colonne);
//funzione che restituisce la media tra le somme per righe di una matrice;
float mediaSommaR(int matrice[][5], int righe, int colonne);
//funzione che restituisce la media tra le somme per colonne di una matrice
float mediaSommaC(int matrice[][5], int righe, int colonne);
//funzione che trova il numero massimo all'interno di una matrice;
float nMassimo(int matrice[][5], int righe, int colonne);
//funzione che trova il numero minimo all'interno di una matrice;
float nMinimo(int matrice[][5], int righe, int colonne);
//funzione che inserisce tutti i valori calcolati in una array;
void caricaArray(float array[], int dim, float mediaR, float mediaC, float max, float min);
//funzione che visualizza i valori contenuti nell'array;
void visualizzaV(float array[], int dim);
//funzione che scrive il contenuto di un vettore su file;
void scriviV(float array[], int dim);
//funzione che legge i valori dal file e li inserisce in un array;
void leggiV(float array[], int dim);