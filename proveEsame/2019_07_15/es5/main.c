#include<stdio.h>
#include<stdlib.h>

#define CIFRE 10

void analisi_parole_file(FILE *ptr);


int main(int argc, char *argv[]){

    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL)
        exit(EXIT_FAILURE);

    analisi_parole_file(fp);

    fclose(fp);

    return EXIT_SUCCESS;
}


void analisi_parole_file(FILE *fp){

    int num;
    while(fscanf(fp, "%d", &num) != EOF){
        int temp = num;
        int conteggio[CIFRE]  = { 0 };
        while(temp/10){
            conteggio[temp % 10]++;
            temp /= 10;
        }

        int index_max = 0;
        int max = 0;
        int i = 0;
        while(i < CIFRE){
            if(conteggio[i] > max ){
                index_max = i;
                max = conteggio[i];
            } else if (conteggio[i] == max && i > index_max){
                index_max = i;
                max = conteggio[i];
            }
            i++;
        }

        fprintf(stdout, "Numero: %d, Più ricorrente: %d, Occorrenze: %d\n", num, index_max, conteggio[index_max]);
    }

    return;


}