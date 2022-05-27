#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct data_tag data;
struct data_tag{
	char lettera;
	int occorrenze;
	data *next;
};

data* conta_occorrenze(FILE *fp);
data* is_present(char lettera, data *head);
void add_node(data *head, data *node);
void display(data *head_list);
void free_list(data *head);


int main(){
	char *file_name = "./file.txt";
	
	FILE *fp = fopen(file_name, "r");
	
	if(fp == NULL){
		perror("Error opening the file");
		exit(1);
	}
	
	data *list = conta_occorrenze(fp);
	
	display(list);
	
	free_list(list);
	
	return EXIT_SUCCESS;

}

data* conta_occorrenze(FILE *fp){
	char temp;
	data *head = NULL;
	data *ptr = NULL;
	
	while((temp = fgetc(fp)) != EOF){
		if(isalpha(temp))
			if(ptr = is_present(temp, head))
				ptr->occorrenze++;
			else{
				data *node = (data *) malloc(sizeof(data));
				node->lettera = temp;
				node->occorrenze = 1;
				
				if(head == NULL)
					head = node;
					
				else
					add_node(head, node);
			}
	}
	return head;
}


data* is_present(char lettera, data *head){
	if(head == NULL)
		return NULL;
	
	data *ptr = head;
	
	while(ptr /*!= NULL*/){
		if(ptr->lettera == lettera)
			return ptr;	
		ptr = ptr->next;
	}
	
	return NULL;

}


void add_node(data *head, data *node){
	data *ptr = head;
	
	while(ptr->next)
		ptr = ptr->next;
		
	ptr->next = node;
	node->next = NULL;
	
	return;
}

void display(data *head_list){
	data *ptr = head_list;
	
	while(ptr){
		fprintf(stdout, "\nLettera: %c, Occorenze: %d", ptr->lettera, ptr->occorrenze);
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











