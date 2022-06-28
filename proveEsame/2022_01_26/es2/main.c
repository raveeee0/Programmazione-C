#include<stdlib.h>
#include<stdio.h>

#define N 6


int positivi_vs_negativi(int mat[N], int count, int pos);



int main(){

    int mat[N] = {1, 2, -3, 4, 5, -6};

    if(positivi_vs_negativi(mat, 0, 0) == 1)
        fprintf(stdout, "Ci sono più numeri positivi\n");
    else
        fprintf(stdout, "Ci sono più numeri negativi o sono in egual numero\n");

    return EXIT_SUCCESS;
}

int positivi_vs_negativi(int mat[N], int count, int pos){
    if(pos == N) {
        if (count > 0)
            return 1;
        else
            return -1;
    }

    if(mat[pos] > 0)
        count++;
    else
        count--;
    return positivi_vs_negativi(mat, count, pos + 1);
}
