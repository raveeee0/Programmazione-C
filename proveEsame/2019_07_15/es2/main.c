#include<stdio.h>
#include<stdlib.h>

#define N 14

typedef struct analisi_tag analisi;
struct analisi_tag{
    int minimo;
    int massimo;
    int medio;
};

analisi *analisi_sequenza(int mat[N]);
void display_analisi(analisi *head);

int main(){

    int mat[N] = {2, -4, 4, 2, 34, 4 ,3, 3, 6, 2, 3, 2, 3, 4};

    analisi *dati = analisi_sequenza(mat);
    display_analisi(dati);

    free(dati);

    return EXIT_SUCCESS;
}


analisi *analisi_sequenza(int mat[N]){
    int min = mat[0];
    int max = mat[0];
    int sum = 0;

    for(int i = 1; i < N; i++){
        sum += mat[i];

        if(min > mat[i])
            min = mat[i];

        if(max < mat[i])
            max = mat[i];
    }

    analisi *ptr = (analisi *) malloc(sizeof(analisi));
    ptr->massimo = max;
    ptr->minimo = min;
    ptr->medio = sum/N;

    return ptr;
}


void display_analisi(analisi *ptr){
    if(ptr == NULL)
        return;

    fprintf(stdout, "Minimo: %d\nMassimo: %d\nMedia: %d\n", ptr->minimo, ptr->massimo, ptr->medio);

    return;
}