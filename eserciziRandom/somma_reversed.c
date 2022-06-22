#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode_tag ListNode;
struct ListNode_tag{
    int val;
    ListNode *next;
};


ListNode *addTwoNumbers(ListNode* l1, ListNode* l2);
void free_list(ListNode *head);
void display_list(ListNode *head);
ListNode *crea_nodo(int number);
void add_node(ListNode *head, ListNode *nodo);



int main() {

    //Prima Lista
    ListNode *l1_head = crea_nodo(9);
    add_node(l1_head, crea_nodo(9));
    add_node(l1_head, crea_nodo(9));
    add_node(l1_head, crea_nodo(9));
    add_node(l1_head, crea_nodo(9));
    add_node(l1_head, crea_nodo(9));
    add_node(l1_head, crea_nodo(9));

    //Seconda Lista
    ListNode *l2_head = crea_nodo(9);
    add_node(l2_head, crea_nodo(9));
    add_node(l2_head,crea_nodo(9));
    add_node(l2_head,crea_nodo(9));


    display_list(l1_head);
    display_list(l2_head);

    ListNode *result = addTwoNumbers(l1_head, l2_head);
    display_list(result);

    free_list(l1_head);
    free_list(l2_head);
    free_list(result);

    return EXIT_SUCCESS;

}


/* ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    if(l1 == NULL || l2 == NULL)
        return NULL;

    ListNode *result = NULL;

    ListNode *l1_ptr = l1;
    ListNode *l2_ptr = l2;


    int resto = 0;  //  Il resto deve rimanere invariato tra i vari cicli
    ListNode *prev = NULL;  //  Per linkare la lista

    while(l1_ptr || l2_ptr){

        // Costruzione della somma
        int somma = 0;

        if(l1_ptr == NULL)      // Solo l1_ptr è nullo
            somma = l2_ptr->val;
        else if(l2_ptr == NULL) // Solo l2_ptr è nullo
            somma = l1_ptr->val;
        else                    // Nessuno dei due è nullo
            somma = l1_ptr->val + l2_ptr->val;

        somma += resto;         //  Sommo il resto
        resto = 0;              //  Default

        if(somma >= 10){        //  Se c'è resto
            somma -= 10;
            resto = 1;
        }

        ListNode *ptr = crea_nodo(somma);   //  Creo un nuovo nodo
        if(result == NULL) {    // Se la testa è nulla (prima iterazione
            result = ptr;   // Set head
            prev = ptr;
        } else {
            prev->next = ptr;   // Link nodi
            prev = ptr;         // Prossimo per il link
        }

        if(l1_ptr)
            l1_ptr = l1_ptr->next;  // Avanzo lista evitando SEGFAULT
        if(l2_ptr)
            l2_ptr = l2_ptr->next;

        if(!l1_ptr && !l2_ptr && resto) {     //  Se sono alla fine e ho ancora resto (che sarà 1) devo aggiungere una cifra
            ListNode *last = crea_nodo(resto);
            ptr->next = last;
        }
    }

    return result;
}*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = malloc(sizeof(ListNode));
    result->next = NULL;
    ListNode* temp = result;
    int somma = 0;
    while (l1 != NULL || l2 != NULL || somma != 0) {
        if (l1 != NULL) {
            somma += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            somma += l2->val;
            l2 = l2->next;
        }

        temp->val = somma % 10;
        somma /= 10;
        if (l1 != NULL || l2 != NULL || somma != 0) {
            temp->next = malloc(sizeof(ListNode));
            temp = temp->next;
            temp->next = NULL;
        }
    }
    return result;
}


void add_node(ListNode *head, ListNode *nodo){
    if(head == NULL || nodo == NULL)
        return;

    ListNode *ptr = head;
    while(ptr->next)
        ptr = ptr->next;

    ptr->next = nodo;

    return;
}


ListNode *crea_nodo(int number){
    ListNode *ptr = (ListNode *) malloc(sizeof(ListNode));
    ptr->next = NULL;
    ptr->val = number;

    return ptr;
}


void display_list(ListNode *head){
    if(head == NULL)
        return;

    ListNode *ptr = head;
    while(ptr){
        fprintf(stdout, "%d\t", ptr->val);
        ptr = ptr->next;
    }
    fprintf(stdout, "\n");

    return;
}


void free_list(ListNode *head){
    if(head == NULL)
        return;

    ListNode *ptr = head;
    while(ptr){
        ListNode *temp = ptr->next;
        free(ptr);
        ptr = temp;
    }

    return;

}