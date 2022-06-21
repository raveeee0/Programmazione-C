#include<stdio.h>
#include<stdlib.h>

#define NUMERO_LETTERE 26


typedef struct occorrenza_tag occorrenza;
struct occorrenza_tag{
	char lettera;
	int contatore;
};

occorrenza *lettera_maggiore_frequenza(FILE *file_ptr);

int main(int argc, char *argv[]){

	if(argc != 2){
		fprintf(stdout, "Inserire unicamente il nome del file come parametro.\n");
		exit(1);
	}
	

	char *path = argv[1];
	
	FILE *file_ptr = fopen(path, "r");

	occorrenza *ptr = lettera_maggiore_frequenza(file_ptr);
	
	fprintf(stdout, "Lettera: %c, Conteggio: %d\n", ptr->lettera, ptr->contatore);
	free(ptr);

	return EXIT_SUCCESS;	
}

occorrenza *lettera_maggiore_frequenza(FILE *file_ptr){
		
	if(file_ptr == NULL){
		perror("Errore nella lettura file");
		exit(1);
	}
	
	
	int freq[NUMERO_LETTERE] = {0};
	char temp;
	
	
	while(fscanf(file_ptr, "%c", &temp) == 1){
		if(temp >= 97 && temp <= 122)
			freq[temp - 'a']++;
		if(temp >= 65 && temp <= 90)
			freq[temp - 'A']++;	
	}
	
	
	
	int max = 0;
	int index = 0;
	
	for(int i = 0; i < 26; i++){
		if(freq[i] > max){
			max = freq[i];
			index = i;
		}
	}
	
	
	occorrenza *ptr = (occorrenza *) malloc(sizeof(occorrenza));
	
	ptr->lettera = 'a' + index;
	ptr->contatore = freq[index];
	
	
	return ptr;
	
}




