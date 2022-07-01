#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 3

typedef struct point_tag point_t;
struct point_tag{
    int x;
    int y;
};


int is_regular(point_t mat[N][N]);
int euclide(point_t p1, point_t p2);


int main(){

    point_t mat[N][N] = {
            {1, 1, 1, 1, 1, 1},
            {2, 2, 2, 2, 2, 2},
            {3, 3, 3, 3, 7, 80}
    };

    if(is_regular(mat))
        fprintf(stdout, "La matrice è regolare\n");
    else
        fprintf(stdout, "La matrice non è regolare\n");

    return EXIT_SUCCESS;
}


int is_regular(point_t mat[N][N]){
    int diag_len = 0;
    int i = 0;

    while(i < N - 1){
        diag_len += euclide(mat[i][i], mat[i + 1][i + 1]);
        i++;
    }

    for(int i = 0; i < N; i++){
        int row_len = 0; int col_len = 0;
        for(int j = 0; j < N - 1; j++){
            row_len += euclide(mat[i][j], mat[i][j + 1]);
            col_len += euclide(mat[j][i], mat[j + 1][i]);
        }

        if(row_len > diag_len || col_len > diag_len)
            return 0;
    }

    return 1;
}


int euclide(point_t p1, point_t p2){
    int x = p1.x - p2.x;
    int y = p1.y - p2.y;

    int distance = (int) sqrt((double)(x*x + y*y));

    return distance;
}