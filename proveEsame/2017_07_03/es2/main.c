#include<stdio.h>
#include<stdlib.h>

#define N 3

int somma_diagonali(int mat[N][N], int n, int sum_1, int sum_2);


int main(){

  int mat[N][N] = {
  {2, 4, 6},
  {3, 5, 9},
  {1, 0, 5}
  };

  
  if(somma_diagonali(mat, 0, 0, 0))
    fprintf(stdout, "Le diagonali hanno pari somma\n");
  else 
    fprintf(stdout, "Le diagonali non hanno pari somma\n");

  return EXIT_SUCCESS;
}


int somma_diagonali(int mat[N][N], int n, int sum_1, int sum_2){
  if(n == N)
    return sum_1 == sum_2;

  return somma_diagonali(mat, n + 1, sum_1 += mat[n][n], sum_2 += mat[N - 1 - n][n]);
}