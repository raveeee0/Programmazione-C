#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct accesso_tag accesso;
struct accesso_tag {
    char targa[8];
    accesso *next;
};

typedef struct permesso_tag permesso;
struct permesso_tag {
    char targa[8];
    permesso *next;
};


void inserimento_ordinato_accesso(accesso *head, accesso *nodo, accesso **head_ptr);
void inserimento_ordinato_permesso(permesso *head, permesso *nodo, permesso **head_ptr);
accesso *crea_nodo_accesso(char *targa);
permesso *crea_nodo_permesso(char *targa);
void display_list_accessi(accesso *head);
void display_list_permessi(permesso *head);
int controlla_accessi(accesso *head_acc, permesso *head_perm, char *targa);

int main(){

    accesso *head_acc = crea_nodo_accesso("TA234BC");
    inserimento_ordinato_accesso(head_acc, crea_nodo_accesso("RD463GD"), &head_acc);
    inserimento_ordinato_accesso(head_acc, crea_nodo_accesso("RG362ER"), &head_acc);
    inserimento_ordinato_accesso(head_acc, crea_nodo_accesso("AO890HF"), &head_acc);
    inserimento_ordinato_accesso(head_acc, crea_nodo_accesso("TF182HV"), &head_acc);
    inserimento_ordinato_accesso(head_acc, crea_nodo_accesso("AO890HF"), &head_acc);
    display_list_accessi(head_acc);

    permesso *head_perm = crea_nodo_permesso("TA234BC");
    inserimento_ordinato_permesso(head_perm, crea_nodo_permesso("KI890LO"), &head_perm);
    inserimento_ordinato_permesso(head_perm, crea_nodo_permesso("RT342DD"), &head_perm);
    inserimento_ordinato_permesso(head_perm, crea_nodo_permesso("MG738DC"), &head_perm);
    inserimento_ordinato_permesso(head_perm, crea_nodo_permesso("TF182HV"), &head_perm);
    inserimento_ordinato_permesso(head_perm, crea_nodo_permesso("RT342DD"), &head_perm);
    display_list_permessi(head_perm);

    fprintf(stdout, "---------------------------\n\n");

    int i = controlla_accessi(head_acc, head_perm, "RT842DD");

    if(i == 0)
        fprintf(stdout, "Targa già presente nella ZTL\n");
    if(i == 1)
        fprintf(stdout, "Veicolo non autorizzato\n");
    if(i == 2)
        fprintf(stdout, "Targa aggiunta nella lista accessi\n");


    display_list_accessi(head_acc);
    display_list_permessi(head_perm);

    return EXIT_SUCCESS;
}


void inserimento_ordinato_accesso(accesso *head, accesso *nodo, accesso **head_ptr){
    if(head == NULL)
        exit(1);

    accesso *ptr = head;
    if(strcmp(ptr->targa, nodo->targa) > 0){
        nodo->next = ptr;
        *head_ptr = nodo;
        return;
    }

    while(ptr){
        if(strcmp(ptr->targa, nodo->targa) == 0)
            return;

        if(ptr->next == NULL){
            ptr->next = nodo;
            return;
        }

        if(strcmp(ptr->targa, nodo->targa) < 0 && strcmp(ptr->next->targa, nodo->targa) > 0){
            nodo->next = ptr->next;
            ptr->next = nodo;
            return;
        }

        ptr = ptr->next;
    }

    return;
}

void inserimento_ordinato_permesso(permesso *head, permesso *nodo, permesso **head_ptr){
    if(head == NULL)
        exit(1);

    permesso *ptr = head;
    if(strcmp(ptr->targa, nodo->targa) > 0){
        nodo->next = ptr;
        *head_ptr = nodo;
        return;
    }

    while(ptr){
        if(strcmp(ptr->targa, nodo->targa) == 0)
            return;

        if(ptr->next == NULL){
            ptr->next = nodo;
            return;
        }

        if(strcmp(ptr->targa, nodo->targa) < 0 && strcmp(ptr->next->targa, nodo->targa) > 0){
            nodo->next = ptr->next;
            ptr->next = nodo;
            return;
        }

        ptr = ptr->next;
    }

    return;
}

accesso *crea_nodo_accesso(char *targa){
    accesso *nodo = (accesso *) malloc(sizeof(nodo));
    strcpy(nodo->targa, targa);
    return nodo;
}

permesso *crea_nodo_permesso(char *targa){
    permesso *nodo = (permesso *) malloc(sizeof(nodo));
    strcpy(nodo->targa, targa);
    return nodo;
}

void display_list_accessi(accesso *head){
    fprintf(stdout, "Lista accessi: ");
    accesso *ptr = head;
    while(ptr) {
        fprintf(stdout, "%s\t", ptr->targa);
        ptr = ptr->next;
    }
    fprintf(stdout, "\n");
    return;
}

void display_list_permessi(permesso *head){
    fprintf(stdout, "Lista permessi: ");
    permesso *ptr = head;
    while(ptr) {
        fprintf(stdout, "%s\t", ptr->targa);
        ptr = ptr->next;
    }
    fprintf(stdout, "\n");
    return;
}

int controlla_accessi(accesso *head_acc, permesso *head_perm, char *targa){
    accesso *ptr_acc = head_acc;
    while(ptr_acc){
        if(strcmp(ptr_acc->targa, targa) == 0)
            return 0;
        ptr_acc = ptr_acc->next;
    }

    permesso *ptr_perm = head_perm;
    int is_presente = 0;

    while(ptr_perm){
        if(strcmp(ptr_perm->targa, targa) == 0)
            is_presente = 1;
        ptr_perm = ptr_perm->next;
    }

    if(is_presente){
        inserimento_ordinato_accesso(head_acc, crea_nodo_accesso(targa), &head_acc);
        return 2;
    }

    return 1;
}