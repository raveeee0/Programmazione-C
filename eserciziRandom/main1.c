//Funzione ricorsiva che leva le vocali a una stringa
#include<stdlib.h>
#include<stdio.h>


int is_vowel(char letter);
char* sostituzione_ricorsiva(char *string, int index1 /* 0 */, int index2 /* 0 */, int index3 /* 0 */);



int main(){
    char string[9] = {'a', 'b', 's', 'o', 'e', 's', 't', 'a', '\0'};

    sostituzione_ricorsiva(string, 0, 0, 0);
    fprintf(stdout, "%s\n", string);

    return EXIT_SUCCESS;
}

char* sostituzione_ricorsiva(char *string, int index1 /* 0 */, int index2 /* 0 */, int index3 /* 0 */){

    if(index3 == -1){
        while(string[index1] != '\0')
            string[index1++] = '\0';
        return string;
    }

    if(index2 == -1){
        int cons_flag = index1;

        while(string[cons_flag] != '\0') {
            if (!is_vowel(string[cons_flag])) {
                string[index1] = string[cons_flag];
                string[cons_flag] = 'a';
                index2 = 0;
                return sostituzione_ricorsiva(string, index1 + 1, index2, index3);
            }
            cons_flag++;
        }

        index3 = -1;
        return sostituzione_ricorsiva(string, index1, index2, index3);
    }

    if(is_vowel(string[index1])){
        index2 = -1;
        return sostituzione_ricorsiva(string, index1, index2, index3);
    }

    if(string[index1] == '\0'){
        index3 = -1;
        return sostituzione_ricorsiva(string, index1, index2, index3);
    }

    return sostituzione_ricorsiva(string, index1 + 1, index2, index3);
}


int is_vowel(char letter){
    if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
        return 1;
    return 0;
}