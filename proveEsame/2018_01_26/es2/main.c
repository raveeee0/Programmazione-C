#include<stdio.h>
#include<stdlib.h>

#define SIZE 64

void lettura_stampa_inv_ric();
void lettura_stampa_inv_iter();


int main(){
    lettura_stampa_inv_ric();
    fprintf(stdout, "\n");
    lettura_stampa_inv_iter();
    fprintf(stdout, "\n");

    return EXIT_SUCCESS;
}


void lettura_stampa_inv_ric(){
    char ch;
    fscanf(stdin, "%c", &ch);
    if(ch == '.')
        return;
    lettura_stampa_inv_ric();
    fprintf(stdout, "%c", ch);
    return;
}


void lettura_stampa_inv_iter(){
    char ch;
    int incr = 1;
    int counter = 0;
    char *str = (char *) malloc(sizeof(char) * SIZE * incr);

    while(fscanf(stdin, "%c", &ch) != EOF && ch != '.'){
        if(counter > SIZE * incr -2)
            str = (char *) realloc(str, sizeof(char) * ++incr * SIZE);
        str[counter] = ch;
        counter++;
    }
    str[counter] = '\0';

    for(int i = counter - 1; i >= 0; i--)
        fprintf(stdout, "%c", str[i]);

    return;
}

