#include<stdlib.h>
#include<stdio.h>

#define N 10


void traccia_mosse(int row, int col, int mat[N][N], FILE *write);
int next_move(int *x_ptr, int *y_ptr, int row, int col, int mat[N][N], int q);


int main(int argc, char *argv[]){
    FILE *read = fopen(argv[1], "r");
    FILE *write = fopen(argv[2], "w");

    if(write == NULL || read == NULL)
        exit(1);

    int mat[N][N] = {0};
    int row; int col;
    fscanf(read, "%d %d", &row, &col);

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            fscanf(read, "%d", &mat[i][j]);

    for(int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            fprintf(stdout, "%d\t", mat[i][j]);
        fprintf(stdout, "\n");
    }

    traccia_mosse(row, col, mat, write);

    return EXIT_SUCCESS;
}



void traccia_mosse(int row, int col, int mat[N][N], FILE *write){
    int x; int y; int m; int q;
    fprintf(stdout, "Immetti la posizione iniziale (x y): ");
    fscanf(stdin, "%d %d", &x, &y);
    fprintf(stdout, "\nInserisci le mosse massime m e la quota massima q: ");
    fscanf(stdin, "%d %d", &m, &q);

    fprintf(write, "Posizione iniziale: %d %d\n", x, y);


    int *x_ptr = &x;
    int *y_ptr = &y;

    while(m-- && next_move(x_ptr, y_ptr, row, col, mat, q))
        fprintf(write, "Move: %d %d\n", *x_ptr, *y_ptr);

    return;
}


int next_move(int *x_ptr, int *y_ptr, int row, int col, int mat[N][N], int q){
    int q_min = 1000;
    int origin_x = *x_ptr;
    int origin_y = *y_ptr;

    for(int i = -1; i != 2; i++)
        for(int j = -1; j != 2; j++) {
            if(i == 0 && j == 0)
                continue;
            if (origin_x + i >= 0 && origin_x + i < row && origin_y + j >= 0 && origin_y + j < col) {
                printf("Check: %d %d\t", origin_x + i, origin_y + j);
                if (mat[origin_x + i][origin_y + j] <= q_min) {
                    q_min = mat[origin_x + i][origin_y + i];
                    *x_ptr = origin_x + i;
                    *y_ptr = origin_y + j;
                }
            }
        }

    if(q_min >= q)
        return 0;

    return 1;
}