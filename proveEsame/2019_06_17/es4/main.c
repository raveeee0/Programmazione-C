#include<stdlib.h>
#include<stdio.h>
#include<string.h>


char *nuova_string(char *str, char *seq);


int main(){

    char *string = nuova_string("gahahahagsavaretgagagadhdhga", "ga");

    fprintf(stdout, "%s\n", string);

    free(string);

    return EXIT_SUCCESS;
}


char *nuova_string(char *str, char *seq){
    int seq_len = strlen(seq);
    int str_len = strlen(str);

    char *s3 = (char *) malloc(sizeof(char) * (str_len + 1));
    strcpy(s3, str);
    char temp;
    int i = 0;

    while(str[i]){
        temp = str[i];
        char *occ = strstr(&s3[i], seq);

        if(occ)
            for(int j = 0; j < seq_len; j++) {
                occ[j] = '+';
                i++;
            }
        else
            break;
    }

    return s3;
}