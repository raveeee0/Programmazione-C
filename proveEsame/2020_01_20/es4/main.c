#include<stdio.h>
#include<stdlib.h>

#define N 4
#define M 4

typedef struct coordinate_tag coordinate;
struct coordinate_tag{
	int row;
	int col;
};


coordinate *contiene_sottomatrice(int mat[][M], int row, int col);
void displayMatrice(int mat[][M]);


int main(){
	
	int mat[N][M];
	
	fprintf(stdout, "Inserisci sequenzialmente i valori della matrice %d x %d (%d valori):\n", N, M, N*M);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			fscanf(stdin, "%d", &mat[i][j]);

	fprintf(stdout, "\n");			
	displayMatrice(mat);
	
	fprintf(stdout, "Matrice inserita correttamente!\n\n");
	fprintf(stdout, "Inserisci il numero di righe e colonne della sottomatrice da ricercare:\n");
	int row, col;
	fscanf(stdin, "%d", &row);
	fscanf(stdin, "%d", &col);
	fprintf(stdout, "Matrice inserita correttamente!\n\n");
	
	coordinate *ptr = NULL;
	
	if(ptr = contiene_sottomatrice(mat, row, col))
		fprintf(stdout, "\nIl primo elemento della matrice è: (%d, %d)\n", ptr->row, ptr->col);
	else
		fprintf(stdout, "\nNon è stata trovata alcuna corrispondenza\n");
	 
	 
	free(ptr);

	return EXIT_SUCCESS;
}

coordinate *contiene_sottomatrice(int mat[][M], int row, int col){

	for(int offset_row = 0; offset_row <= N - row; offset_row++){
		for(int offset_col = 0; offset_col <= M - col; offset_col++){
			int sum = 0;
			for(int i = 0; i < row; i++){
				for(int j = 0; j < col; j++){
					sum += mat[i + offset_row][j + offset_col];
				}
			}
			
			fprintf(stdout, "sum: %d\n", sum);
			if(sum == 0){
				coordinate *ptr = (coordinate *) malloc(sizeof(coordinate));
				ptr->row = offset_row + 1;
				ptr->col = offset_col + 1;
				
				return ptr;
			}
			
				printf("\n");
		}
	}
	return NULL;
}


void displayMatrice(int mat[][M]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			fprintf(stdout, "%d ", mat[i][j]);
		}
		fprintf(stdout, "\n");	
	}

	return;
}






