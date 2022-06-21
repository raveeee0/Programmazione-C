#include<stdio.h>
#include<stdlib.h>

void funzione_ricorsiva(char *string, int i /* starting from 0 */);

int main(){
    char * string =  "ANOIZNUF";
    funzione_ricorsiva(string, 0);
    fprintf(stdout, "\n");

    return EXIT_SUCCESS;
}

void funzione_ricorsiva(char *string, int i){

    if(string[i] == '\0'){
        return;
    }

    funzione_ricorsiva(string, i + 1);
    fprintf(stdout, "%c", string[i]);
    return;

}