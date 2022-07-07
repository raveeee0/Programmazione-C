#include<stdio.h>
#include<stdlib.h>

typedef struct nodo_tag nodo;
struct nodo_tag{
    int val;
    nodo *min;
    nodo *next;
};


void aggiungi_nodo(nodo **head, nodo *node);
void display_lista(nodo *head);
nodo *crea_nodo(int val);
void free_nodo(nodo *head);



int main(){

    nodo *head = crea_nodo(4);
    head->min = head;
    head->next = NULL;

    aggiungi_nodo(&head, crea_nodo(9));
    aggiungi_nodo(&head, crea_nodo(5));
    aggiungi_nodo(&head, crea_nodo(0));
    aggiungi_nodo(&head, crea_nodo(88));
    aggiungi_nodo(&head, crea_nodo(6));

    display_lista(head);

    fprintf(stdout, "Elemento minimo: %d\n", head->min->val);


    free_nodo(head);

    return EXIT_SUCCESS;
}


void aggiungi_nodo(nodo **head, nodo *node){
    if(head == NULL || node == NULL)
        return;

    nodo *ptr = *head;
    *head = node;
    node->next = ptr;


    if(node->val < ptr->min->val) {
        while(ptr){
            ptr->min = node;
            ptr = ptr->next;
        }
        node->min = node;
    } else {
        node->min = ptr->min;
    }

    return;
}



void display_lista(nodo *head){
    if(head == NULL)
        return;

    nodo *ptr = head;
    while(ptr){
        fprintf(stdout, "%d\t", ptr->val);
        ptr = ptr->next;
    }

    fprintf(stdout, "\n");

    return;
}


nodo *crea_nodo(int val){
    nodo *ptr = (nodo *) malloc(sizeof(nodo));
    ptr->next = NULL;
    ptr->min = NULL;
    ptr->val = val;

    return ptr;
}


void free_nodo(nodo *head){
    if(head == NULL)
        return;

    nodo *ptr = head;
    while(ptr){
        nodo *temp = ptr->next;
        free(ptr);
        ptr = ptr->next;
    }

    return;
}