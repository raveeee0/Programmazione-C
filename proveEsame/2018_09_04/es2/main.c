#include<stdio.h>
#include<stdlib.h>

typedef struct data_tag data;
struct data_tag{
	char lettera;
	data *next;
};


data *somma_parentesi(data *head);
void display_list(data *head);
void free_list(data *head);
void add_node(data *nuovo_nodo, data *head);
data* genera_nodo(char lettera);



int main(){

	data *head = genera_nodo('r');
	add_node(genera_nodo('0'), head);
	add_node(genera_nodo('('), head);
	add_node(genera_nodo('2'), head);
	add_node(genera_nodo('5'), head);
	add_node(genera_nodo('0'), head);
	add_node(genera_nodo(')'), head);
	add_node(genera_nodo('0'), head);
	add_node(genera_nodo('0'), head);
	add_node(genera_nodo('('), head);
	add_node(genera_nodo('2'), head);
	add_node(genera_nodo('0'), head);
	add_node(genera_nodo('6'), head);
	add_node(genera_nodo(')'), head);
	
	display_list(head);
	
	somma_parentesi(head);
	
	
	display_list(head);


	return EXIT_SUCCESS;

}


data *somma_parentesi(data *head){
	data *ptr = head;
	
	while(ptr){
		if(ptr->lettera == '('){
			int sum = 0;
			int nodes_to_remove = 0;	
			data *ptr_cursor = ptr->next;
			
			while(ptr_cursor->lettera != ')'){
				sum += ptr_cursor->lettera - '0';
				nodes_to_remove++;
				ptr_cursor = ptr_cursor->next;
			}		
			
			ptr->lettera = sum + '0';
			data *free_ptr = ptr->next;
			ptr->next = ptr_cursor->next;
			
			while(nodes_to_remove > 0){
				data *temp = free_ptr->next;
				free(free_ptr);
				free_ptr = temp;
				nodes_to_remove--;
			}
			
		}
	
	
		ptr = ptr->next;
	}

}

data* genera_nodo(char lettera){
	data *ptr = (data *) malloc(sizeof(data));
	ptr->next = NULL;
	ptr->lettera = lettera;

	return ptr;
}


void add_node(data *nuovo_nodo, data *head){
	if(head == NULL)
		return;
		
	data *ptr = head;
	
	while(ptr->next)
		ptr = ptr->next;
	
	ptr->next = nuovo_nodo;
	
	return;
}


void display_list(data *head){

	data *ptr = head;
	
	while(ptr){
		fprintf(stdout, "%c\t", ptr->lettera);
		ptr = ptr->next;
	}
	
	fprintf(stdout, "\n");

	return;
}





void free_list(data *head){
	
	if(head == NULL)
		return;	
	
	data *prev_ptr = head;
	data *ptr = head->next;
	
	while(prev_ptr){
		free(prev_ptr);
		prev_ptr = ptr;
		
		if(ptr != NULL)
			ptr = ptr->next;
	}

	return;
}


