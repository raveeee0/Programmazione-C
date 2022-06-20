#include<stdio.h>
#include<stdlib.h>

#define M 4
#define N 3

void filtro(double iniziale[][N], double risultato[][N]);
double media(double matrice[][N], int i, int j);

int main(int argc, char *argv[]){

    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL)
        exit(1);

    double iniziale[M][N];

    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            fscanf(fp, "%lf", &iniziale[i][j]);

    fclose(fp);

    double risultato[M][N];

    filtro(iniziale, risultato);

    fp = fopen(argv[2], "w");
    if(fp == NULL)
        exit(1);

    for(int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            fprintf(fp, "%lf\t", risultato[i][j]);
        fprintf(fp, "\n");
    }

    fclose(fp);

    return EXIT_SUCCESS;
}

void filtro(double iniziale[][N], double risultato[][N]){
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j ++)
            risultato[i][j] = media(iniziale, i, j);

    return;
}

double media(double matrice[][N], int i, int j){
    int sum = 0;
    for(int m = -1; m < 2; m++)
        for(int n = -1; n < 2; n++){
            if(i + m >= M || j + n >= N || i + m < 0 || j + n < 0)
                continue;
            sum += matrice[i + m][j + n];
        }

    return (double)sum/9;
}