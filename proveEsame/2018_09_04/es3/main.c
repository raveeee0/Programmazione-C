#include<stdlib.h>
#include<stdio.h>

#define N 3

int mat[N][N];


void lettura_matrice(char *path);
void display_matrice();
int quadrato_magico();


int main(){
	char *path = "input.txt";
	lettura_matrice(path);
	display_matrice();
	
	if(!quadrato_magico())
		fprintf(stdout, "La matrice è un quadrato magico.\n");
	else
		fprintf(stdout, "La matrice non è un quadrato magico.\n");
	
	return EXIT_SUCCESS;

}


int quadrato_magico(){
	int element_exceed_limit = 0;
	int pattern_not_correct = 0;
	
	int row_sums[N] = {0};
	int col_sums[N] = {0};
	int diag_sums[2] = {0};
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(mat[i][j] > N*N)
				element_exceed_limit = 1;
			
			row_sums[i] += mat[i][j];
			col_sums[j] += mat[i][j];
		}
		
		diag_sums[0] += mat[i][i];
		diag_sums[1] += mat[i][N - 1 - i];
	}
	
		
	if(element_exceed_limit)
		return element_exceed_limit;
		
	
	for(int i = 0; i < N; i++)
		for(int j = N - 1; j >= 0; j--)
			if(row_sums[i] != row_sums[j] || col_sums[i] != col_sums[j])
				pattern_not_correct = 1;
	
	if(col_sums[0] != row_sums[0] || diag_sums[0] != diag_sums[1] || diag_sums[0] != row_sums[0])
		pattern_not_correct = 1;
		
	return pattern_not_correct;

}


void lettura_matrice(char *path){
	FILE *ptr = fopen(path, "r");
	
	if(ptr == NULL)
		exit(1);
		
	char temp;
	while(temp != '\n')
		temp = fgetc(ptr);
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			fscanf(ptr, "%d", &(mat[i][j]));

	fclose(ptr);
	
	return;
}

void display_matrice(){

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)
			fprintf(stdout, "%d\t", mat[i][j]);
		fprintf(stdout, "\n");
	}

}


