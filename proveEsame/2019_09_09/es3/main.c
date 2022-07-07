#include<stdio.h>
#include<stdlib.h>

#define N 3

typedef struct result_tag result;
struct result_tag{
    int sum;
    int prod;
};


void displayMatrice(int mat[][N]);
int somma_ricorsiva(int mat[][N], int row, int col);
result *somma_ricorsiva_res(int mat[][N], result *ptr /* 0  0 */, int row, int col);


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

    result *ptr = (result *) malloc(sizeof(result));
    ptr->sum = 0;
    ptr->prod = 1;

	fprintf(stdout, "\nLa somma è %d\n\n", somma_ricorsiva(mat, 0, 0));
	fprintf(stdout, "\nSomma\tProdotto");
    somma_ricorsiva_res(mat, ptr, 0, 0);
    fprintf(stdout, "\n%d\t%d\n", ptr->sum, ptr->prod);


	free(ptr);
	
	return EXIT_SUCCESS;
}


int somma_ricorsiva(int mat[][N], int row, int col){
	if(col == N-1 && row == N-1)
		return mat[row][col];

	if(col == N-1)
		return mat[row][col] + somma_ricorsiva(mat, row+1, 0); 

	return mat[row][col] + somma_ricorsiva(mat, row, col+1);
}


result *somma_ricorsiva_res(int mat[][N], result *ptr /* 0  0 */, int row, int col){
    if(row == N && col == 0)
        return ptr;
    if(col == N)
        return somma_ricorsiva_res(mat, ptr, row + 1, 0);

    ptr->sum += mat[row][col];
    ptr->prod *= mat[row][col];

    return somma_ricorsiva_res(mat, ptr, row, col + 1);
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
