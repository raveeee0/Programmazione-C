#include<stdio.h>
#include<stdlib.h>

#define N 4

int simmetria_ricorsiva(int mat[][N], int i, int j);    // i = 0, j = 0

int main(){
    int mat_simm[N][N] = {
            {1, 2, 3, 4},
            {2, 4, 5, 6},
            {3, 5, 8, 9},
            {4, 6, 9, 3},
    };

    /*
     int mat_not_sim[N][N] = {
            {1, 2, 3, 4},
            {2, 4, 5, 6},
            {3, 55, 8, 9},
            {4, 6, 9, 3},
    };
     */

    int bool = simmetria_ricorsiva(mat_simm, 0, 0);

    if(bool)
        fprintf(stdout, "La matrice è simmetrica\n");
    else
        fprintf(stdout, "La matrice non è simmetrica\n");


    return EXIT_SUCCESS;

}

int simmetria_ricorsiva(int mat[][N], int i, int j){
    if(i == 0 && j == 0) {    // Inizio
        return simmetria_ricorsiva(mat, i, j + 1);
    }

    if(mat[i][j] == mat[j][i]) {
        if(j == N - 1 && i == j - 1)    //  Fine dei controlli
            return 1;
        if(j == N - 1)  //  Fine delle colonne, serve avanzare le righe
            return simmetria_ricorsiva(mat, i + 1, i + 2);
        return simmetria_ricorsiva(mat, i, j + 1);
    }

    return 0;
}

