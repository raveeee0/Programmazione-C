#include<stdio.h>
#include<stdlib.h>

#define N 3

int ricorsiva(int n, int mat[n][n], int x /* 0 */, int y /* 0 */, int min);


int main(){
    int mat[N][N] = {
            {2, 4, 5},
            {555, 7, 1},
            {90, 0, 3}
    };

    fprintf(stdout, "La differenza minima è: %d\n", ricorsiva(N, mat, 0, 0, 0));

    return EXIT_SUCCESS;
}

int ricorsiva(int n, int mat[n][n], int x /* 0 */, int y /* 0 */, int min){
    if(x == 0 && y == 0)
        min = mat[x][y] - mat[x + 1][y + 1];

    if(x == n - 1 && y == n - 1)
        return min;
    if(y == n - 1) {
        if (mat[x][y] - mat[x + 1][0] < min)
            min = mat[x][y] - mat[x + 1][0];
        x++;
        y = 0;
    }
    else if(mat[x][y] - mat[x + 1][y + 1] < min)
            min = mat[x][y] - mat[x + 1][y + 1];

    y++;

    return ricorsiva(n, mat, x, y, min);

}