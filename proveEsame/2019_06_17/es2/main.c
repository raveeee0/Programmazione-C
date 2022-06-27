#include<stdio.h>
#include<stdlib.h>

typedef struct occ_nodo_tag occ_nodo;
struct occ_nodo_tag{
    int numero;
    int occ;
    occ_nodo *next;
};

typedef struct nodo_tag nodo;
struct nodo_tag{
    int numero;
    nodo *next;
};


occ_nodo *analisi(nodo *head);
void add_node(occ_nodo *head, occ_nodo *ptr);
void free_list(nodo *head);
void free_list_occ(occ_nodo *head);
void display_list_occ(occ_nodo *head);
void display_list(nodo *head);




int main(){
    nodo *head = (nodo *) malloc(sizeof(nodo));
    head->numero = 10;

    nodo *ptr = (nodo *) malloc(sizeof(nodo));
    ptr->numero = 11;
    head->next = ptr;


    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 12;

    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 12;

    ptr->next = (nodo *) malloc(sizeof(nodo));
    ptr = ptr->next;
    ptr->numero = 12;

    display_list(head);

    occ_nodo *testa = analisi(head);
    display_list_occ(testa);


    free_list(head);

    return EXIT_SUCCESS;

}


void add_node(occ_nodo *head, occ_nodo *ptr){
    if(head == NULL || ptr == NULL)
        return;

    occ_nodo *temp = head;

    while(temp->next)
        temp = temp->next;

    temp->next = ptr;

    return;
}


occ_nodo *is_present(occ_nodo *head, int numero){
    if(head == NULL)
        return NULL;

    occ_nodo *ptr = head;
    while(ptr){
        if(ptr->numero == numero)
            return ptr;
        ptr = ptr->next;
    }

    return NULL;
}


occ_nodo *analisi(nodo *head){
    if(head == NULL)
        exit(EXIT_FAILURE);

    occ_nodo *head_occ = NULL;
    nodo *ptr = head;
    while(ptr){
        occ_nodo *occ_ptr = NULL;
        if(occ_ptr = is_present(head_occ, ptr->numero))
            occ_ptr->occ++;
        else{
            occ_ptr = (occ_nodo *) malloc(sizeof(occ_nodo));
            occ_ptr->numero = ptr->numero;
            occ_ptr->next = NULL;
            occ_ptr->occ = 1;
            if(head_occ == NULL)
                head_occ = occ_ptr;
            else
                add_node(head_occ, occ_ptr);
        }
        ptr = ptr->next;
    }

    return head_occ;

}


void free_list_occ(occ_nodo *head){
    if(head == NULL)
        return;

    occ_nodo *ptr = head;
    while(ptr){
        occ_nodo *temp = ptr->next;
        free(ptr);
        ptr = temp;
    }

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


void display_list_occ(occ_nodo *head){
    if(head == NULL)
        return;

    occ_nodo *ptr = head;
    while(ptr){
        fprintf(stdout, "Num: %d\tFreq: %d\n", ptr->numero, ptr->occ);
        ptr = ptr->next;
    }
    return;
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