#include<stdlib.h>
#include<sdtio.h>

typedef struct nodo_tag nodo;
struct nodo_tag{
	int numero;
	nodo *next;
};



void display_list(nodo *head);
void somma_lista(nodo *head);
nodo* gen_node(int numero);
void add_node(nodo *nuovo_nodo, nodo *head);
void free_list(nodo *head);



int main(){
	
	nodo *head = gen_node(0);
	
	for(int i = 1;i < 10; i++)
		add_node(gen_node(i), head);
		
	display_list(head);
	
	somma_lista(head);
		
	display_list(head);
	
	free_list(head);
	

	return EXIT_SUCCESS;
}




nodo* gen_node(int numero){
	nodo *ptr = (nodo *) malloc(sizeof(nodo));
	ptr->numero = numero;
	ptr->next = NULL;
	
	return ptr;

}


void add_node(nodo *nuovo_nodo, nodo *head){
	if(head == NULL)
		return NULL;
		
	nodo *ptr = head;
	
	while(ptr->next)
		ptr = ptr->next;
	
	ptr->next = nuovo_nodo;
	
	return;
}


void display_list(nodo *head){

	nodo *ptr = head;
	
	while(ptr){
		fprintf(stdout, "%d\t", ptr->numero);
		ptr = ptr->next;
	}

	return;
}

void somma_lista(nodo *head){
	int temp = 0;
	nodo *ptr = head;
	
	while(ptr){
		int temp_sum = ptr->number;
		ptr->number += temp;
		temp = temp_sum;
		
		ptr = ptr->next;
	}
}


void free_list(nodo *head){
	
	if(head == NULL)
		return;	
	
	nodo *prev_ptr = head;
	nodo *ptr = head->next;
	
	while(prev_ptr){
		free(prev_ptr);
		prev_ptr = ptr;
		
		if(ptr != NULL)
			ptr = ptr->next;
	}

	return;
}




