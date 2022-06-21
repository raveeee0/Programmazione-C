#include<stdio.h>
#include<stdlib.h>


typedef struct lista_tag lista;
struct lista_tag{
    int numero;
    lista *next;
};


lista *crea_nodo(int numero);
void add_nodo(lista *head, lista *nodo);
lista *analisi(lista *head, int val, int limit);
lista *delete(lista *head, int val);
void display_list(lista *head);



int main(){

    lista *head = crea_nodo(6);
    add_nodo(head, crea_nodo(5));
    add_nodo(head, crea_nodo(6));
    add_nodo(head, crea_nodo(8));
    add_nodo(head, crea_nodo(9));
    add_nodo(head, crea_nodo(0));
    add_nodo(head, crea_nodo(6));
    add_nodo(head, crea_nodo(6));
    add_nodo(head, crea_nodo(8));

    display_list(head);

    head = analisi(head, 6, 2);
    head = analisi(head, 8, 3);

    display_list(head);

    return EXIT_SUCCESS;
}


lista* analisi(lista *head, int val, int limit){
    lista *ptr = head;
    int occ = 0;

    while(ptr){
        if(ptr->numero == val)
            occ++;
        ptr = ptr->next;
    }

    if(occ < limit)
        return delete(head, val);
    return head;
}


lista *delete(lista *head, int val){
    lista *ptr_prev = head;
    lista *ptr = head->next;

    while(ptr){
        if(ptr->numero == val){
            ptr_prev->next = ptr->next;
            free(ptr);
            ptr = ptr_prev->next;
        } else {
            ptr_prev = ptr_prev->next;
            ptr = ptr->next;
        }
    }


    if(head->numero == val){
        lista *new_head = head->next;
        free(head);
        return new_head;
    }

    return head;

}



lista *crea_nodo(int numero){
    lista *ptr = (lista *) malloc(sizeof(lista));
    ptr->next = NULL;
    ptr->numero = numero;

    return ptr;

}


void add_nodo(lista *head, lista *nodo){
    if(head == NULL || nodo == NULL)
        return;

    lista *ptr = head;

    while(ptr->next)
        ptr = ptr->next;

    ptr->next = nodo;

    return;
}


void display_list(lista *head){
    if(head == NULL)
        return;

    lista *ptr = head;

    while(ptr){
        fprintf(stdout, "%d\t", ptr->numero);
        ptr = ptr->next;
    }
    fprintf(stdout, "\n");

    return;
}