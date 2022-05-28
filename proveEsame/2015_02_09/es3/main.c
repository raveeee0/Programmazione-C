#include <stdbool.h>
 
const int N = 4;
 
bool consecutiveRows(int mat[][N], int i, int j) {
    if(i == N) return false;
 
    if(mat[i][j] == mat[i + 1][j]) {
        if(j == N - 1) return true;
        else return consecutiveRows(mat, i, j + 1);
    }
    else {
        return consecutiveRows(mat, i + 1, 0);
    }
 
    return false;
}
