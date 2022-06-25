#include<stdlib.h>
#include<stdio.h>

#define N 4


int is_quadrato_latino(int mat[][N], int size);
void display_matrice(int mat[][N], int size);
int is_in_riga_colonna(int mat[][N], int i, int j, int size);



int main(int argc, char *argv[]){

    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL)
        exit(EXIT_FAILURE);

    int mat[N][N] = { 0 };
    int size = 0;
    fscanf(fp, "%d", &size);

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            fscanf(fp, "%d", &mat[i][j]);
        }
    }

    display_matrice(mat, size);

    if(is_quadrato_latino(mat, size))
        fprintf(stdout, "Risulta essere un quadrato latino\n");
    else
        fprintf(stdout, "Non è un quadrato latino\n");

    return EXIT_SUCCESS;


}


int is_quadrato_latino(int mat[][N], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(mat[i][j] > size)
                return 0;

            if(!is_in_riga_colonna(mat, i, j, size))    // Unico
                return 0;
        }
    }

    return 1;
}


void display_matrice(int mat[][N], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            fprintf(stdout, "%d\t", mat[i][j]);
        }
        fprintf(stdout, "\n");
    }
    return;
}


int is_in_riga_colonna(int mat[][N], int i, int j, int size){
    for(int m = 0; m < size; m++){
        if(mat[i][m] == mat[i][j] && m != j)
            return 0;
        if(mat[m][j] == mat[i][j] && m != i)
            return 0;
    }

    return 1;
}