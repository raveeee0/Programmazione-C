#include<stdlib.h>
#include<stdio.h>


void saldo_sotto_quota(char *file_name, int quota);


int main(int argc, char *argv[]){
    saldo_sotto_quota(argv[1], atoi(argv[2]));

    return EXIT_SUCCESS;
}



void saldo_sotto_quota(char *file_name, int quota){
    FILE *fp = fopen(file_name, "r");
    if(fp == NULL)
        exit(EXIT_FAILURE);

    char data[9] = {0};
    int saldo = 0;
    int temp;
    int flag = 0;
    char sign;

    while(fscanf(fp, "%s", data) != EOF){

        fscanf(fp, "%d", &temp);
        fgetc(fp);
        fscanf(fp, "%c", &sign);

        if(sign == '+')
            saldo += temp;
        else if(sign == '-')
            saldo -= temp;

        if(saldo < quota){
            flag = 1;
            fprintf(stdout, "%s: %d\n", data, saldo);
        }


    }

    if(!flag)
        fprintf(stdout, "Saldo: %d\n", saldo);


    fclose(fp);

    return;
}