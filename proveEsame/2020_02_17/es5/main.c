#include<stdio.h>
#include<stdlib.h>


void occorrenze(FILE *fp, char *seq);
int is_present(char let, char *seq);

int main(int argc, char *argv[]){
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL)
        exit(EXIT_FAILURE);

    char seq[26] = {0};

    fprintf(stdout, "Immetti i caratteri da tracciare: ");
    fscanf(stdin, "%s", seq);
    occorrenze(fp, seq);

    fclose(fp);

    return EXIT_SUCCESS;
}


void occorrenze(FILE *fp, char *seq){
    char alf[26] = {0};
    char temp;
    while(fscanf(fp, "%c", &temp) != EOF)
        if(is_present(temp, seq))
            alf[temp - 'a']++;
    for(int i = 0; i < 26; i++)
        if(is_present('a' + i, seq))
            fprintf(stdout, "%c: %d\n", 'a' + i, alf[i]);

    return;
}


int is_present(char let, char *seq){
    int i = 0;
    while(seq[i])
        if(let == seq[i++])
            return 1;
    return 0;
}