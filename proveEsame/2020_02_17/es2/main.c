#include<stdio.h>
#include<stdlib.h>

int somma_ricorsiva_inclusi_estremi(int n1, int n2);

int main(){
    fprintf(stdout, "%d\n", somma_ricorsiva_inclusi_estremi(1, 3));

    return EXIT_SUCCESS;

}

int somma_ricorsiva_inclusi_estremi(int n1, int n2){
    if(n1 == n2)
        return n2;
    return n1 + somma_ricorsiva_inclusi_estremi(n1 + 1, n2);
}