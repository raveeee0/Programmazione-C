#include<stdlib.h>
#include<stdio.h>

typedef struct nodo_tag nodo;
struct nodo_tag{
    char lettera;
    nodo *next;
};

// Verifica ricorsiva presenza di k volte per una lettera
int almeno_k(char lettera, int k, nodo *head);


nodo* crea_nodo(char lettera);
void add_node(nodo *head, nodo *node);


int main(){

    nodo *head = crea_nodo('a');
    add_node(head, crea_nodo('b'));
    add_node(head, crea_nodo('r'));
    add_node(head, crea_nodo('a'));
    add_node(head, crea_nodo('c'));
    add_node(head, crea_nodo('a'));
    add_node(head, crea_nodo('b'));

    int prova = almeno_k('a', 3, head);

    if(prova)
        fprintf(stdout, "Ci sono almeno 3 a\n");
    else
        fprintf(stdout, "Non ci sono 3 a\n");

    return EXIT_SUCCESS;
}

int almeno_k(char lettera, int k, nodo *head){
    if(k == 0)
        return 1;

    if(head == NULL)
        return 0;

    if(head->lettera == lettera)
        return almeno_k(lettera, k - 1, head->next);

    return almeno_k(lettera, k, head->next);
}


nodo* crea_nodo(char lettera){
    nodo* ptr = (nodo *) malloc(sizeof(nodo));
    ptr->next = NULL;
    ptr->lettera = lettera;

    return ptr;
}


void add_node(nodo *head, nodo *node){
    nodo *ptr = head;
    while(ptr->next){
        ptr = ptr->next;
    }

    ptr->next = node;
    return;
}