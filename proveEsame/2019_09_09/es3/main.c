#include<stdio.h>
#include<stdlib.h>

#define N 3


void displayMatrice(int mat[][N]);
int somma_ricorsiva(int mat[][N], int row, int col);

int main(){

	int mat[N][N];
	
	fprintf(stdout, "Inserisci i valori della matrice %d x %d: ", N, N);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int temp;
			if (fscanf(stdin, "%d", &temp) == 0){
				perror("Error in the input");
				exit(1);
			}
			mat[i][j] = temp; 
		}
	}
	
	fprintf(stdout, "\nLa somma è %d\n", somma_ricorsiva(mat, 0, 0));
	
	
	return EXIT_SUCCESS;
}

int somma_ricorsiva(int mat[][N], int row, int col){
	if(col == N-1 && row == N-1)
		return mat[row][col];

	if(col == N-1)
		return mat[row][col] + somma_ricorsiva(mat, row+1, 0); 

	return mat[row][col] + somma_ricorsiva(mat, row, col+1);
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
