#include<stdlib.h>
#include<stdio.h>

#define N 5


int *partiziona(int mat[N]);



int main(){

    int arr[N] = {1, 2, 3, 4, 2};
    int *new_arr = NULL;
    if(new_arr = partiziona(arr)) {             // Bisognerebbe anche passare la dimensione dell'array per una stampa corretta
        fprintf(stdout, "Può essere partizionato\n");
        for(int i = 0; i < N; i++)
            fprintf(stdout, "%d\t", new_arr[i]);
        fprintf(stdout, "\n");
    } else
        fprintf(stdout, "Non può essere partizionato\n");

    return EXIT_SUCCESS;
}

int *partiziona(int mat[N]){
    int sum = 0;
    int i = 0;
    while(i < N)
        sum += mat[i++];

    if(sum % 2)
        return NULL;

    int mid_value = sum / 2;
    i = 0;
    int sum_sx = 0;
    while(sum_sx < mid_value && i < N)
        sum_sx += mat[i++];


    int initial_dx_index = i;
    int sum_dx = 0;
    while(i < N){
        sum_dx += mat[i++];
    }

    if(sum_sx != sum_dx)
        return NULL;

    int len = N - initial_dx_index;
    int *head = (int *) malloc(sizeof(int) * len);
    i = 0;
    while(initial_dx_index + i < N){
        head[i] = mat[initial_dx_index + i];
        i++;
    }

    return head;
}