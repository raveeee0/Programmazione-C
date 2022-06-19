#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define N 4
#define M 4

int trova_occorrenze(char mat[][M], char *stringa, int length);
void displayMatrice(char mat[][N]);

int main(int argc, char *argv[]){

    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL)
        exit(1);

    char mat[N][M] = { 0 };
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            fscanf(fp, "%c", &mat[i][j]);
        }
    }
    fclose(fp);


    fp = fopen(argv[2], "r");
    char *strings[10] = { 0 };

    int i = 0;
    do {
        strings[i] = (char *) malloc(sizeof (char) * 64);
    } while (fscanf(fp, "%s", strings[i++]) != EOF);
    fclose(fp);

    free(strings[i]);

    int j = 0;
    while(j < i - 1){
        fprintf(stdout, "Le occorrenze della parola %s sono: %d\n", strings[j], trova_occorrenze(mat, strings[j], strlen(strings[j])));
        j++;
    }

    for(int j = 0; j < i; j++)
        free(strings[j]);

    return EXIT_SUCCESS;
}

int trova_occorrenze(char mat[][M], char *stringa, int length){
    int counter = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(mat[i][j] == stringa[0] && length <= M - j){
                int offset = 0;
                int not_valid = 0;
                int temp = length;

                while(temp){
                    if(stringa[offset] != mat[i][j + offset])
                        not_valid = 1;
                    offset++;
                    temp--;
                }

                if(!not_valid)
                    counter++;
                if(length <= M - j + 1)
                    continue;
                break;
            }
        }
    }

    return counter;
}

void displayMatrice(char mat[][M]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			fprintf(stdout, "%c ", mat[i][j]);
		}
		fprintf(stdout, "\n");
	}

	return;
}
