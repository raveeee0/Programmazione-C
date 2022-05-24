#include<stdio.h>
#include<stdlib.h>

#define N 3

int media(int mat[][N], int riga, int colonna);
void displayMatrice(int mat[][N]);

int main(){

	int mat1[N][N];
	
	fprintf(stdout, "Inserisci i valori della matrice 3 x 3: ");
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int temp;
			if (fscanf(stdin, "%d", &temp) == 0){
				fprintf(stdin, "Error in the input");
				exit(1);
			}
			mat1[i][j] = temp; 
		}
	}
	
	int mat2[N][N];
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			mat2[i][j] = media(mat1, i, j);
		}
	}
	
	displayMatrice(mat1);
	fprintf(stdout, "\n");
	displayMatrice(mat2);
	

	return EXIT_SUCCESS;
}

int media(int mat[][N], int riga, int colonna){

	int sommaR = 0;
	int sommaC = 0;
	
	for(int i = 0; i < N; i++){
		sommaR += mat[riga][i];
		sommaC += mat[i][colonna];
	}
	
	return (sommaR + sommaC - mat[riga][colonna])/(2*N - 1);
}

void displayMatrice(int mat[][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			fprintf(stdout, "%d ", mat[i][j]);
		}
		fprintf(stdout, "\n");	
	}

	return;
}
