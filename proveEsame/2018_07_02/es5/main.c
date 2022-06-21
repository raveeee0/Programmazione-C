#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int is_pangramma(char *string);


int main(){

    /* Try:
     * Pangrams:    - "pack my box with five dozen liquor jugs"
     *              - "the five boxing wizards jump quickly."
    */


    int bool = is_pangramma("Questo probabilmente non sarà un pangramma");
    if(bool)
        fprintf(stdout, "Risulta essere un pangramma\n");
    else
        fprintf(stdout, "Non è un pangramma\n");

    return EXIT_SUCCESS;
}


int is_pangramma(char *string){
    if(strlen(string) < 26)
        return 0;

    int check[26] = {0};

    int i = 0;
    while(string[i] != '\0'){
        char t = string[i];
        if(t >= 97 && t <= 122 && check[t - 'a'] == 0)
            check[t - 'a'] = 1;
        i++;
    }

    for(int j = 0; j < 26; j ++)
        if(check[j] == 0)
            return 0;

    return 1;
}
