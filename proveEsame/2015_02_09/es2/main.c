#include<stdlib.h>
#include<stdio.h>

#define N 64

void polybius(FILE *ptr, char key[][5], int *cifratura);
int cifra(char t, char key[][5]);


int main(){

	int cifratura[N] = {0};

	FILE *ptr;
	fopen("fle.txt", "r");
	
	if(ptr == NULL){
		perror("Error opening the text file");
		exit(1);
	}
	
	char key[5][5];
	polybius(ptr, key, cifratura);
	
	return EXIT_SUCCESS;

}


void polybius(FILE *ptr, char key[][5], int *cifratura){
	int *cif_ptr = cifratura;
	char temp;
	
	while((temp = fgetc(ptr)) != EOF){
		if(temp == ' ' || temp == '\n')
			*cif_ptr = 0;
		else
			*cif_ptr = cifra(temp, key);
		ptr++;
	}

	return;
}


int cifra(char t, char key[][5]){
	for(int i = 0; i < 5; i ++)
		for(int j = 0; j < 5; j++)
			if(key[i][j] == t)
				return (i+1)*10 + j+1;
	return 1;


}
