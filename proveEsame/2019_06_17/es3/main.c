#include<stdio.h>
#include<stdlib.h>


#define N 3


int is_simmetrica(int mat[][N], int row, int col);


int main(){
    int mat[N][N] = {
            {1, 2, 3},
            {2, 1, 5},
            {3, 5, 1}
    };

    if(is_simmetrica(mat, 0, 0))
        fprintf(stdout, "La matrice è simmetrica\n");
    else
        fprintf(stdout, "La matrice non è simmetrica\n");

    return EXIT_SUCCESS;
}


int is_simmetrica(int mat[][N], int row, int col){
    if(col == N-1 && row == N -1)
        return mat[row][col] == 1;

    if(col == row){
        if(mat[col][row] == 1)
            return is_simmetrica(mat, row, col + 1);
        return 0;
    }

    if(col == N-1){
        if(mat[row][col] == mat[col][row])
            return is_simmetrica(mat, row + 1, 0);
        return 0;
    }

    if(mat[row][col] == mat[col][row])
            return is_simmetrica(mat, row, col + 1);
        return 0;

}