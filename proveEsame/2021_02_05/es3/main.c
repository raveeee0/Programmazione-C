#include<stdio.h>
#include<stdlib.h>

typedef struct nodo_tag nodo;
struct nodo_tag{
    int numero;
    nodo *next;
};

void display_list(nodo *head);
void sotto_sequenze(nodo *head, int val);
void free_list(nodo *head);
void add_node(nodo *head, nodo *node);


int main(){


    nodo *head = (nodo *) malloc(sizeof (nodo));

    head->numero = 5;
    nodo *ptr = (nodo *) malloc(sizeof (nodo));
    add_node(head, ptr);
    ptr->numero = 3;
    ptr = (nodo *) malloc(sizeof (nodo));
    add_node(head, ptr);
    ptr->numero = 7;
    ptr = (nodo *) malloc(sizeof (nodo));
    add_node(head, ptr);
    ptr->numero = 7;
    ptr = (nodo *) malloc(sizeof (nodo));
    add_node(head, ptr);
    ptr->numero = 1;
    ptr->next = NULL;

    display_list(head);

    sotto_sequenze(head, 11);

    return EXIT_SUCCESS;
}


void sotto_sequenze(nodo *head, int val){

    if(head == NULL){
        fprintf(stderr, "\nPointer to linked list is null\n");
        exit(1);
    }

    nodo *ptr = head;
    while(ptr){
        nodo *ptr_ind = ptr->next;
        int sum = ptr->numero;

        while(ptr_ind){
            if(sum + ptr_ind->numero > val){
                while(ptr != ptr_ind) {
                    fprintf(stdout, "%d\t", ptr->numero);
                    ptr = ptr->next;
                }
                fprintf(stdout, "\n");
                break;
            } else if(ptr_ind->next == NULL){
                while(ptr != ptr_ind->next) {
                    fprintf(stdout, "%d\t", ptr->numero);
                    ptr = ptr->next;
                }
                break;
            } else {
                sum += ptr_ind->numero;
                ptr_ind = ptr_ind->next;
            }
        }
    }
    fprintf(stdout, "\n");
    return;
}


void display_list(nodo *head){
    if(head == NULL)
        exit(1);
    nodo *ptr = head;

    while(ptr){
        fprintf(stdout, "%d\t", ptr->numero);
        ptr = ptr->next;
    }

    fprintf(stdout, "\n");

    return;
}


void free_list(nodo *head){
    if(head == NULL){
        fprintf(stderr, "Pointer to linked list is null\n");
        exit(1);
    }

    nodo *ptr = head;
    while(ptr != NULL){
        nodo *temp = ptr->next;
        free(ptr);
        ptr = temp;
    }

}

void add_node(nodo *head, nodo *node){
    if(head == NULL || node == NULL)
        return;

    nodo *ptr = head;

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = node;
}
