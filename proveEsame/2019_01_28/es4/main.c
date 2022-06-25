#include<stdlib.h>
#include<stdio.h>


typedef struct nodo_tag nodo;
struct nodo_tag {
    int numero;
    nodo *next;
};



void add_nodo(nodo *head, nodo *node);
nodo *crea_nodo(int numero);
double media_lista(nodo *head);
int is_present_next(nodo *head, int numero);
void display_lista(nodo *head);



int main(){

    nodo *head = crea_nodo(3);
    add_nodo(head, crea_nodo(6));
    add_nodo(head, crea_nodo(33));
    add_nodo(head, crea_nodo(3));
    add_nodo(head, crea_nodo(3));
    display_lista(head);

    fprintf(stdout, "La media è %lf\n", media_lista(head));

    return EXIT_SUCCESS;

}


nodo *crea_nodo(int numero){
    nodo *ptr = (nodo *) malloc(sizeof(nodo));
    ptr->next = NULL;
    ptr->numero = numero;

    return ptr;
}


void add_nodo(nodo *head, nodo *node){
    if(node == NULL)
        return;
    if(head == NULL){
        head = node;
        return;
    }

    nodo *ptr = head;
    while(ptr->next)
        ptr = ptr->next;

    ptr->next = node;

    return;
}

double media_lista(nodo *head){
    int sum = 0;
    nodo *ptr = head;
    int len = 0;
    while(ptr){
        if(!is_present_next(ptr->next, ptr->numero)){
            sum += ptr->numero;
            len++;
        }
        ptr = ptr->next;
    }

    return (double) sum/len;
}

int is_present_next(nodo *head, int numero){
    if(head == NULL)
        return 0;

    nodo *ptr = head;
    while(ptr){
        if(ptr->numero == numero)
            return 1;
        ptr = ptr->next;
    }
}


void display_lista(nodo *head){
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