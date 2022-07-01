#include<stdio.h>
#include<stdlib.h>

typedef struct nodo_tag nodo;
struct nodo_tag{
    int numero;
    nodo *next;
};


int somma_ricorsiva(nodo *head);
void display_list(nodo *head);
void free_list(nodo *head);


int main(){

    nodo *head = (nodo *) malloc(sizeof(nodo));
    head->numero = 1;

    nodo *ptr = head;
    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 2;

    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 3;

    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 4;


    display_list(head);
    fprintf(stdout, "La somma è: %d\n", somma_ricorsiva(head));
    display_list(head);

    free_list(head);

    return EXIT_SUCCESS;
}


int somma_ricorsiva(nodo *head){
    if(head->next == NULL)
        return head->numero;
    head->numero += somma_ricorsiva(head->next);
    return head->numero;
}


void display_list(nodo *head){
    if(head == NULL)
        return;
    nodo *ptr = head;
    while(ptr){
        fprintf(stdout, "%d\t", ptr->numero);
        ptr = ptr->next;
    }
    fprintf(stdout, "\n");

    return;
}


void free_list(nodo *head){
    if(head == NULL)
        return;

    nodo *ptr = head;
    while(ptr){
        nodo *temp = ptr->next;
        free(ptr);
        ptr = temp;
    }

    return;
}
