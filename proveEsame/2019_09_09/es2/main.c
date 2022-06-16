#include<stdio.h>
#include<stdlib.h>

#define N 3

typedef struct values_tag values;
struct values_tag{
	int sum;
	int prod;
};

void calcolo_valori(int mat[][N], values *data);
void displayMatrice(int mat[][N]);

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
	
	values *data = (values *) malloc(sizeof(values));
	
	calcolo_valori(mat, data);
	displayMatrice(mat);
	fprintf(stdout, "\nSomma: %d\tProdotto: %d\n", data->sum, data->prod);
	
	
	free(data);
	
	return EXIT_SUCCESS;
}



void calcolo_valori(int mat[][N], values *data){
	int sum = 0;
	int prod = 1;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			sum += mat[i][j];
			prod *= mat[i][j];
		}
	}
	
	data->sum = sum;
	data->prod = prod;
	
	return;
	
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
