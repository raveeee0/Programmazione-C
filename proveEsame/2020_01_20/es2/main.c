#include<stdio.h>
#include<stdlib.h>

#define SIZE 8

int funzione_ricorsiva(int a[], int val, int index);

int main(){

	int a[SIZE] = {1, 2, 3, -3, -4, -6, 7, -5};
	
	fprintf(stdout, "%d\n", funzione_ricorsiva(a, 5, SIZE - 1));
	
	return EXIT_SUCCESS;
	
}

int funzione_ricorsiva(int a[], int val, int index){

	if(val == -1)
		return 0;
		
	if(index < 0)
		return 1;
	
	if(a[index] < 0)
		return funzione_ricorsiva(a, val - 1, index - 1);
	else
		return funzione_ricorsiva(a, val, index - 1);
	
}
