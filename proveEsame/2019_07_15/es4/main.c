#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5



typedef struct stringa_tag stringa;
struct stringa_tag {
    char parola[N];
    stringa *next;
};


stringa *stringhe_comprese(char *str, char lettera);
stringa *nuovo_nodo(char *string);
void aggiungi_nodo(stringa *head, stringa *nodo);
void display_lista(stringa *head);
void free_list(stringa *head);



int main(int argc, char *argv[]){

    stringa *lista = stringhe_comprese(argv[1], argv[2][0]);
    display_lista(lista);

    free_list(lista);

    return EXIT_SUCCESS;
}


stringa *nuovo_nodo(char *string) {
    stringa *ptr = (stringa *) malloc(sizeof(stringa));
    ptr->next = NULL;
    strcpy(ptr->parola, string);

    return ptr;
}


void aggiungi_nodo(stringa *head, stringa *nodo) {
    if(head == NULL || nodo == NULL)
        return;

    stringa *ptr = head;
    while(ptr->next)
        ptr = ptr->next;

    ptr->next = nodo;

    return;
}


void display_lista(stringa *head) {
    if(head == NULL)
        return;

    stringa *ptr = head;
    while(ptr){
        fprintf(stdout, "%s\t", ptr->parola);
        ptr = ptr->next;
    }
    fprintf(stdout, "\n");

    return;
}

stringa *stringhe_comprese(char *str, char lettera) {
    if(str == NULL)
        return NULL;

    char *temp;
    int index = 0;
    stringa *head = NULL;
    while(str[index] != '\0'){
        if(str[index++] == lettera){
            char copia[N] = {0};
            int temp = 0;


            while(str[index] != lettera && str[index] != '\0')
                copia[temp++] = str[index++];

            if(str[index] == '\0')
                return head;

            stringa *ptr = nuovo_nodo(copia);
            if(head == NULL)
                head = ptr;
            else
                aggiungi_nodo(head, ptr);
        }
    }
    return head;
}

void free_list(stringa *head){
    if(head == NULL)
        return;

    stringa *ptr = head;
    while(ptr){
        stringa *temp = ptr->next;
        free(ptr);
        ptr = temp;
    }

    return;
}