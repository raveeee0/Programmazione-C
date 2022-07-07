#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5



typedef struct stringa_tag stringa;
struct stringa_tag {
    char parola[N];
    stringa *next;
};


stringa *ritaglia(char *str, char lettera);
stringa *nuovo_nodo(char *string);
void aggiungi_nodo(stringa *head, stringa *nodo);
void display_lista(stringa *head);
void free_list(stringa *head);



int main(int argc, char *argv[]){
    stringa *lista = ritaglia(argv[1], argv[2][0]);
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

stringa *ritaglia(char *str, char lettera) {
    stringa *head = (stringa *) malloc(sizeof(stringa));
    char parola[20] = {0};
    stringa *ptr = head;

    strcpy(parola, str);

    int i = 0;
    while (parola[i]) {
        if (parola[i] == lettera) {
            int j = 0;
            if (!parola[i + 1])
                break;

            while (parola[++i] && parola[i] != 'a')
                ptr->parola[j++] = parola[i];

            ptr->next = (stringa *) malloc(sizeof(stringa));
            ptr = ptr->next;
        } else {
            int j = 0;
            while (parola[i] && parola[i] != lettera)
                ptr->parola[j++] = parola[i++];

            ptr->next = (stringa *) malloc(sizeof(stringa));
            ptr = ptr->next;
        }
    }

    free(ptr);

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