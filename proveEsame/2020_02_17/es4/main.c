#include<stdio.h>
#include<stdlib.h>


#define N 3
#define M 3

typedef struct index_tag index;
struct index_tag{
    int row;
    int col;
};

index *submat_exist(int mat[N][M], int r, int c, int submat[r][c]);

int main(){

    int mat[N][M] = {
            {1, 2, 8},
            {3, 4, 5},
            {2, 3, 9}
    };
    int submat[2][2] = {
            {4, 5},
            {3, 9},
    };

    index *res = submat_exist(mat, 2, 2, submat);
    fprintf(stdout, "%d - %d\n", res->row, res->col);

    free(res);

    return EXIT_SUCCESS;
}


index *submat_exist(int mat[N][M], int r, int c, int submat[r][c]){

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(mat[i][j] == submat[0][0]){
                int exist = 1;
                for(int m = 0; m < r; m++){
                    for(int n = 0; n < c; n++){
                        if(mat[i + m][j + n] != submat[m][n])
                            exist = 0;
                    }
                }
                if(exist){
                    index *res = (index *) malloc(sizeof(index));
                    res->row = i + 1;
                    res->col = j + 1;

                    return res;
                }
            }
        }
    }

    index *res = (index *) malloc(sizeof(index));
    res->row = -1;
    res->col = -1;

    return res;
}