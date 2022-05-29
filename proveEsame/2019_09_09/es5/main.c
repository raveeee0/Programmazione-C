#include<stdio.h>
#include<stdlib.h>


typedef struct data_tag data;
struct data_tag {
	char lett;
	int count;
	data *next;
};


data *calcolo_occorrenze(char *s);
void add_node_in_order(data *head, data *nodo);
data *is_present(char p, data *head);

void display(data *head_list){
	data *ptr = head_list;
	
	while(ptr){
		fprintf(stdout, "\nLettera: %c, Occorenze: %d", ptr->lett, ptr->count);
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



int main(){
	
	char *s = "Stringa";

	data *list = calcolo_occorrenze(s);
	
	display(list);
	
	free_list(list);
	
	
	return EXIT_SUCCESS;	
}

data *is_present(char p, data *head){
	if(head == NULL)
		return NULL;
	
	data *ptr = head;
	while(ptr){
		if(p == ptr->lett)
			return ptr;
		ptr = ptr->next;
		}
	return NULL;
}


void add_node_in_order(data *head, data *nodo){
	if(head == NULL || nodo == NULL)
		return;
		
	if(head->lett > nodo->lett){
		nodo->next = head;
		head = nodo;
		return;
	}
	
	data *ptr = head->next;
	data *ptr_prev = head;
	while(ptr_prev){
		if(ptr == NULL || nodo->lett < ptr->lett){
			ptr_prev->next = nodo;
			nodo->next = ptr;
			return;
		}
		ptr_prev = ptr;
		ptr = ptr->next;
	}
	
	return;
}


data *calcolo_occorrenze(char *s){

	data *head = NULL;
	data *ptr = NULL;
	
	char p = s[0];
	int counter = 1;
	
	while(p != '\0'){
		if(ptr = is_present(p, head))
			ptr->count++;
		
		if(head == NULL){
			head->lett = p;
			head->count = 1;
			head->next = NULL;
		} else {
			data *nodo = (data *) malloc(sizeof(data));
			nodo->lett = p;
			nodo->count = 1;
			nodo->next = NULL;
			add_node_in_order(head, nodo);
		}
		
		p = s[counter++];
	}
	
	return head;
}
