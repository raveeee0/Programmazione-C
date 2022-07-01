#include<stdlib.h>
#include<stdio.h>

typedef struct nodo_tag nodo;
struct nodo_tag{
    int numero;
    nodo *next;
};


nodo *elimina_ripetizioni(nodo *head, int num);
void display_list(nodo *head);
void free_list(nodo *head);


int main(){

    nodo *head = (nodo *) malloc(sizeof(nodo));
    head->numero = 5;

    nodo *ptr = head;
    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 5;

    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 3;

    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 5;

    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 4;

    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 4;

    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 4;

    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 4;

    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 4;

    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 4;

    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 4;

    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 3;

    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 5;

    display_list(head);
    head = elimina_ripetizioni(head, 3);
    display_list(head);

    free_list(head);


    return EXIT_SUCCESS;
}


nodo *elimina_ripetizioni(nodo *head, int num){
    if(head == NULL)
        return NULL;

    nodo *ptr = head;

    while(ptr){
        int numero = ptr->numero;
        int counter = 1;
        nodo *temp = ptr->next;
        while(temp){
            if(temp->numero == numero)
                counter++;
            temp = temp->next;
        }
        if(counter >= num){ // Vanno rimossi elementi
            while(head){    // Rimozione delle teste
                if(head->numero == numero){
                    temp = head->next;
                    free(head);
                    head = temp;
                }
                else
                    break;
            }

            temp = head;
            if(temp == NULL)
                return NULL;

            nodo *next_ptr = temp->next;
            while(next_ptr->next){  // Rimozione in-lista
                if(next_ptr->numero == numero){
                    temp->next = next_ptr->next;
                    free(next_ptr);
                    next_ptr = temp->next;
                } else {
                    next_ptr = next_ptr->next;
                    temp = temp->next;
                }
            }

            if(next_ptr->numero == numero) {   // Eventuale fine lista
                temp->next = NULL;
                free(next_ptr);
            }

            ptr = head;
        } else
            ptr = ptr->next;
    }

    return head;
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
