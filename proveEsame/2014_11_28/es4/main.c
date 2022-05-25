#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define EXAM_NUM 30

typedef struct esame_tag esame;
struct esame_tag {
	char nome[64];
	int codice;
	int valutazione;
};

typedef struct carriera_tag carriera;
struct carriera_tag {
	int matricola;
	char nome[64];
	char cognome[64];
	char indirizzo[64];
	
	esame esami[EXAM_NUM];
};

carriera* modifica(carriera* ptr, int codice_esame, int valutazione_esame);

int main(){

	carriera *io = (carriera *) malloc(sizeof(carriera));
	modifica(io, 12, 133);
	
	printf("%d\n", io->esami[0].valutazione);
	
	free(io);

	return EXIT_SUCCESS;
}



carriera* modifica(carriera* ptr, int codice_esame, int valutazione_esame){

	int isFound = 0;
	
	for(int i = 0; i < EXAM_NUM; i++){
		esame *temp = &(ptr->esami[i]);
		if(temp->codice == codice_esame){
			temp->valutazione = valutazione_esame;
			isFound = 1;
		}
	}
		
	if (!isFound){
		esame *exam_ptr = &(ptr->esami[0]);
		strcpy(exam_ptr->nome, "Analisi Matematica 1");
		exam_ptr->codice = codice_esame;
		exam_ptr->valutazione = valutazione_esame;		
	}
	
	return ptr;
	
}
