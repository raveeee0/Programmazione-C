#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *trasforma(char *email);

int main(){

    char *email = "nome.cognome@azienda.com";
    char *trasf = trasforma(email);

    fprintf(stdout, "%s     ---    %s\n", email, trasf);

    return EXIT_SUCCESS;

}


char *trasforma(char *email){
    int len_na = 0;
    int len_co = 0;
    int len_az = 0;

    int i = 0;
    while(email[i++] != '.')
        len_na++;

    while(email[i++] != '@')
        len_co++;

    while(email[i++] != '.')
        len_az++;


    char *trasf = (char *) malloc(sizeof(char) * 64);
    strncpy(trasf, email, len_na);
    strcpy(&trasf[len_na], "_DOT_");
    strncpy(&trasf[len_na + 5], &email[len_na + 1], len_co);
    strcpy(&trasf[len_na + 5 + len_co], "_AT_");
    strncpy(&trasf[len_na + 5 + len_co + 4], &email[len_na + 1 + len_co + 1], len_az);
    strcpy(&trasf[len_na + 5 + len_co + 4 + len_az], "_DOT_com");

    return trasf;



}