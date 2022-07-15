#include<stdio.h>
#include<stdlib.h>

typedef struct nodo_tag nodo;
struct nodo_tag {
  int val;
  nodo *next;
};


nodo *inserimento(nodo *head, int val, int k);
void stampa(nodo *head);
void free_nodo(nodo *head);


int main(){
  nodo *head = (nodo *) malloc(sizeof(nodo));
  head->val = 0;

  head = inserimento(head, 45, 1);
  head = inserimento(head, 45, 1);
  head = inserimento(head, 45, 1);
  head = inserimento(head, 45, 1);
  head = inserimento(head, 45, 1);
  head = inserimento(head, 45, 1);
  stampa(head);
  head = inserimento(head, 44, 7);

  
  stampa(head);
  


  return EXIT_SUCCESS;
}


nodo *inserimento(nodo *head, int val, int k){
  int len = 0;
  nodo **arr = (nodo **) malloc(sizeof(nodo *));
  nodo *ptr = head;

  while(ptr){
    arr[len ++] = ptr;
    ptr = ptr->next;
    arr = (nodo **) realloc(arr, (len + 1) * sizeof(nodo*));
  }

  if(k > len + 1)
    return head;

  nodo *new = (nodo *) malloc(sizeof(nodo));
  new->val = val;
  new->next = NULL;

  if(k == len + 1){
    new->next = arr[0];
    head = new;
  } else {
    arr[len - k]->next = new;

    if(len - k + 1 < len)
      new->next = arr[len - k + 1];
    
  }

  free(arr);


  return head;  
}


void stampa(nodo *head){
  if(!head)
    return;

  nodo *ptr = head;
  while(ptr){
    fprintf(stdout, "%d\t", ptr->val);
    ptr = ptr->next;
  }

  fprintf(stdout, "\n");
}


void free_nodo(nodo *head){
  nodo *ptr = head;

  while(ptr){
    nodo *temp = ptr->next;
    free(ptr);
    ptr = temp;
  }

  return;
}