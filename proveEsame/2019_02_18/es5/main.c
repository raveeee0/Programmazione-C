#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define SIZE 64


void correzione(FILE *read, FILE* write);
char *lettura_parola(FILE *read);
char *correzione_parola(char *str);
int is_vowel(char letter);
char convert_to_accent(char lett);


int main(int argc, char *argv[]){
    FILE *read = fopen(argv[1], "r");
    FILE *write = fopen(argv[2], "w");

    if(read == NULL || write == NULL)
        exit(EXIT_FAILURE);

    correzione(read, write);

    fclose(read);
    fclose(write);


    return EXIT_SUCCESS;
}


void correzione(FILE *read, FILE* write){

    char *string = NULL;
    while((string = lettura_parola(read)) != NULL){
        string = correzione_parola(string);
        fprintf(write, "%s ", string);
        free(string);
    }

    return;
}


char *lettura_parola(FILE *read){
    char *s = (char *) calloc((size_t) SIZE, sizeof(char));
    char temp;
    int counter = 0;
    int increment = 1;
    while(fscanf(read, "%c", &temp) != EOF && temp != ' '){
        if(counter > increment * SIZE - 2){
            increment++;
            s = realloc(s, increment * SIZE * sizeof(char));
        }
        s[counter] = temp;
        counter++;
    }

    s[counter] = '\0';

    if(counter == 0)
        return NULL;

    return s;
}


char *correzione_parola(char *str){
    int len = strlen(str);

    if(str[len - 1] == '\'' && is_vowel(str[len - 2])){
        str = realloc(str, len * sizeof(char));
        str[len] = '\0';
        str[len - 1] = convert_to_accent(str[len - 1]);
    }

    return str;
}


char convert_to_accent(char lett){
    if(lett == 'a')
        return 'à';
    if(lett == 'e')
        return 'è';
    if(lett == 'i')
        return 'ì';
    if(lett == 'o')
        return 'o';
    if(lett == 'u')
        return 'ù';
    return 0;
}


int is_vowel(char letter){
    if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
        return 1;
    return 0;
}