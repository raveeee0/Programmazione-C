#include<stdlib.h>
#include<stdio.h>


typedef struct nodo_tag nodo;
struct nodo_tag{
    int numero;
    nodo *next;
};


nodo *trasla(nodo *head, int dir);
void display_lista(nodo *head);
void free_lista(nodo *head);


int main(){

    nodo *head = (nodo *) malloc(sizeof(nodo));
    head->numero = 9;
    nodo *ptr;

    ptr = (nodo *) malloc(sizeof(nodo));
    ptr->numero = 23;
    head->next = ptr;

    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 7;

    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 83;

    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 20;

    display_lista(head);

    head = trasla(head, 0);

    display_lista(head);

    free_lista(head);


    return EXIT_SUCCESS;
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



nodo *trasla(nodo *head, int dir){
    if(head == NULL || head->next == NULL)
        return head;

    if(dir == 0){
        int val = head->numero;
        nodo *ptr = head;
        while(ptr->next){
            ptr->numero = ptr->next->numero;
            ptr = ptr->next;
        }
        ptr->numero = val;
    }

    if(dir == 1){
        int temp = head->numero;
        nodo *ptr = head->next;

        while(ptr){
            int t = temp;
            temp = ptr->numero;
            ptr->numero = t;

            ptr = ptr->next;
        }

        head->numero = temp;
    }

    return head;
}


void free_lista(nodo *head){
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