#include<stdlib.h>
#include<stdio.h>

void stampa_ricorsiva(int numero);

int main(){
    stampa_ricorsiva(1234);

    return EXIT_SUCCESS;
}

void stampa_ricorsiva(int numero){

    if(numero < 10){
        fprintf(stdout, "%d\n", numero);
        return;
    }

    stampa_ricorsiva(numero/10);
    fprintf(stdout, "%d\n", numero % 10);
    return;
}