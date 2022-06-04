#include<stdio.h>
#include<stdlib.h>


int caratteri_numerici_ricorsiva(char *stringa, int index);

int main(){

	char *stringa = "Quant1 c3 n3 son0?";
	
	int numero = caratteri_numerici_ricorsiva(stringa, 0);
	
	fprintf(stdout, "Il numero di caratteri numerici nella stringa è: %d\n", numero);
	
	return EXIT_SUCCESS;

}


int caratteri_numerici_ricorsiva(char *stringa, int index){

	if(stringa[index] == '\0')
		return 0;
		
	if(stringa[index] >= '0' && stringa[index] <= '9')
		return caratteri_numerici_ricorsiva(stringa, index + 1) + 1;
		
	return caratteri_numerici_ricorsiva(stringa, index + 1);

}
