#include<stdlib.h>
#include<stdio.h>

#define N 3
#define M 2

int funzione_ricorsiva(int mat[][M], int i, int j);

int main(){
	
	int mat[N][M] = {{2, 3}, {4, 6}, {1, 9}};
	
	fprintf(stdout, "The sum is %d\n", funzione_ricorsiva(mat, 0, 0));
	
	return EXIT_SUCCESS;

}


int funzione_ricorsiva(int mat[][M], int i/* starting_x_index: 0 */, int j/* starting_y_index: 0 */){

	if(j == N)
		return mat[i][j] + funzione_ricorsiva(mat, i+1, 0);
	
	if(i == M)
		return mat[i][j];
		
	return mat[i][j] + funzione_ricorsiva(mat, i, j+1);


}
