#include<stdio.h>
#include<stdlib.h>

#define N 10


typedef struct codifica_tag codifica;
struct codifica_tag{
    int len;
    codifica *next;
};


codifica *codifica_RCL(int mat[]);
void display_list(codifica *head);
void add_node(codifica *head, codifica *nodo);
codifica *crea_nodo(int len);


int main(){

    fprintf(stdout, "Inserisci un codice binario di lunghezza %d: ", N);
    int mat[N];
    for(int i = 0; i < N; i++){
        fscanf(stdin, "%d", &mat[i]);
    }

    for(int i = 0; i < N; i++){
        fprintf(stdout, "%d\t", mat[i]);
    }
    fprintf(stdout, "\n\nRCL: ");
    codifica *head = codifica_RCL(mat);
    display_list(head);

    return EXIT_SUCCESS;

}


codifica *codifica_RCL(int mat[]){
    int i = 0;
    codifica *head = NULL;

    if(mat[0] == 1)
        head = crea_nodo(0);

    while(i < N){
        int len = 1;
        int index = i;
        while(index + 1 < N && mat[index] == mat[index + 1]){
            len++;
            index++;
        }
        i = index + 1;
        codifica *nodo = crea_nodo(len);
        if(head == NULL)
            head = nodo;
        else
            add_node(head, nodo);
    }

    return head;
}


void add_node(codifica *head, codifica *nodo){
    if(head == NULL || nodo == NULL)
        return;

    codifica *ptr = head;
    while(ptr->next)
        ptr = ptr->next;

    ptr->next = nodo;

    return;
}


codifica *crea_nodo(int len){
    codifica *ptr = (codifica *) malloc(sizeof(codifica));

    ptr->next = NULL;
    ptr->len = len;

    return ptr;
}


void display_list(codifica *head){
    if(head == NULL)
        return;

    codifica  *ptr = head;
    while(ptr){
        fprintf(stdout, "%d\t", ptr->len);
        ptr = ptr->next;
    }

    return;
}