#include<stdlib.h>
#include<stdio.h>


typedef struct occ_tag occ;
struct occ_tag{
    int valore;
    int occorrenze;
    occ *next;
};


void analisi_file(char *exam_file, char *report_file);
occ* contains_element(occ *head, int value);
void add_node(occ *head, occ *node);
void free_list(occ *head);



int main(int argc, char *argv[]){
    if(argc != 3)
        exit(1);
    analisi_file(argv[1], argv[2]);

    return EXIT_SUCCESS;
}

void analisi_file(char *exam_file, char *report_file){
    FILE *fp = fopen(exam_file, "r");
    if(fp == NULL)
        exit(1);

    int temp;
    occ *head = NULL;

    while(fscanf(fp, "%d", &temp) != EOF){
        occ *node = NULL;
        if(node = contains_element(head, temp))
            node->occorrenze++;
        else{
            node = (occ *) malloc(sizeof(occ));
            node->occorrenze = 1;
            node->valore = temp;
            node->next = NULL;
            if(head == NULL)
                head = node;
            else
                add_node(head, node);
        }
    }
    fclose(fp);

    fp = fopen(report_file, "w");
    occ *ptr = head;

    while(ptr){
        fprintf(fp, "Valore: %d -> %d ripetizioni\n", ptr->valore, ptr->occorrenze);
        fflush(fp);
        ptr = ptr->next;
    }

    fclose(fp);
    free_list(head);

    return;
}

occ* contains_element(occ *head, int value){
    if(head == NULL)
        return 0;

    occ *ptr = head;
    while(ptr){
        if(ptr->valore == value)
            return ptr;
        ptr = ptr->next;
    }

    return 0;
}

void add_node(occ *head, occ *node){
    if(head == NULL || node == NULL)
        return;

    occ *ptr = head;

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = node;
}

void free_list(occ *head){
    occ *ptr = head;

    while(ptr){
        occ *temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
}