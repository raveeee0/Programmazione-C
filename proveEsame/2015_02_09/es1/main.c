#include<stdlib.h>
#include<stdio.h>

typedef struct node_tag node;
struct node_tag {
	int data;
	node *next;
};


void deleteEven(node *head){
	if(head == NULL){
		fprintf(stdout, "The given list is null!");
		exit(1);
	}
	
	node *ptr_prev = NULL;
	node *ptr_present = head;
	
	int counter = 1; /*Assumendo "posizione" != "indice", ovvero posizioni: 1, 2, 3, ...*/
	
	while(ptr_present/* != NULL*/){
	
		if(counter % 2 == 0){
			ptr_prev->next = ptr_present->next;
			free(ptr_present);		
		}	
		
		ptr_prev = ptr_present;
		ptr_present = ptr_present->next;
		counter++;
	}
}

int main() {
	
	return EXIT_SUCCESS;

}
