#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int convert(char *string);



int main(int argc, char *argv[]){
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL)
        exit(1);

    char string[10] = {0};
    FILE *ptr = fopen(argv[2], "w");

    if(ptr == NULL)
        exit(1);

    while(fscanf(fp, "%s", string) != EOF){
        if(!strcmp(string, "***"))
            fprintf(ptr, "\n");
        else
            fprintf(ptr, "%d", convert(string));
    }

    fclose(fp);
    fclose(ptr);

    return EXIT_SUCCESS;

}


int convert(char *string){ // uno due tre quattro cinque sei sette otto nove zero

    switch (string[0]) {
        case 'z': return 0;
        case 'u': return 1;
        case 'd': return 2;
        case 't': return 3;
        case 'q': return 4;
        case 'c': return 5;
        case 'o': return 8;
        case 'n': return 9;
        default:
            if(string[2] == 'i')
                return 6;
            else
                return 7;
    }


}