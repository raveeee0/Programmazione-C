#include<stdlib.h>
#include<stdio.h>
#include<string.h>


typedef struct occ_tag occ;
struct occ_tag{
    char str[20];
    int occ;
    occ *next;
};


typedef struct stats_tag stats;
struct stats_tag{
    int tot_parole;
    char *freq_min_str;
    int freq_min;
    char *freq_max_str;
    int freq_max;
};



occ *frequenza(FILE *fp);
occ *is_present(occ *head, char *temp);
occ *add_node_in_order(occ *head, occ *node);
void display_occ(occ *head);
void free_occ(occ *head);
stats *statistiche(occ *head);



int main(int argc, char *argv[]){
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL)
        exit(EXIT_FAILURE);

    occ *freq = frequenza(fp);
    display_occ(freq);
    stats *ptr = statistiche(freq);

    fprintf(stdout, "Tot: %d\nMax: %s %d\nMin: %s %d\n", ptr->tot_parole, ptr->freq_max_str, ptr->freq_max, ptr->freq_min_str, ptr->freq_min);


    free_occ(freq);
    free(ptr);

    fclose(fp);

    return EXIT_SUCCESS;
}


stats *statistiche(occ *head){
    if(head == NULL)
        return NULL;

    int tot_parole = 0;
    char *freq_min_str = head->str;
    int freq_min = head->occ;
    char *freq_max_str = head->str;
    int freq_max = head->occ;

    occ *ptr = head;

    while(ptr){
        if(ptr->occ > freq_max){
            freq_max = ptr->occ;
            freq_max_str = ptr->str;
        }
        if(ptr->occ < freq_min){
            freq_min = ptr->occ;
            freq_min_str = ptr->str;
        }

        tot_parole++;
        ptr = ptr->next;
    }

    stats *nodo = (stats *) malloc(sizeof(stats));
    nodo->freq_min_str = freq_min_str;
    nodo->freq_max_str = freq_max_str;
    nodo->tot_parole = tot_parole;
    nodo->freq_min = freq_min;
    nodo->freq_max = freq_max;

    return nodo;
}


void free_occ(occ *head){
    if(head == NULL)
        return;

    occ *ptr = head;
    while(ptr){
        occ *temp = ptr->next;
        free(ptr);
        ptr = temp;
    }

    return;
}


void display_occ(occ *head){
    if(head == NULL)
        return;

    occ *ptr = head;
    while(ptr){
        fprintf(stdout, "%s %d\n", ptr->str, ptr->occ);
        ptr = ptr->next;
    }

    fprintf(stdout, "\n");

    return;
}


occ *add_node_in_order(occ *head, occ *node){
    if(head == NULL)
        return NULL;
    if(node == NULL)
        return head;

    if(strcmp(node->str, head->str) < 0){
        node->next = head;
        return node;
    } else {
        occ *ptr = head;
        while(ptr->next){
            if(strcmp(ptr->str, node->str) < 0 && strcmp(ptr->next->str, node->str) > 0){
                occ *temp = ptr->next;
                ptr->next = node;
                node->next = temp;
                return head;
            }
            ptr = ptr->next;
        }
        ptr->next = node;
    }

    return head;
}


occ *is_present(occ *head, char *temp){
    if(head == NULL || temp == NULL)
        return NULL;
    occ *ptr = head;
    while(ptr){
        if(strcmp(ptr->str, temp) == 0)
            return ptr;
        ptr = ptr->next;
    }

    return NULL;
}


occ *frequenza(FILE *fp){
    if(fp == NULL)
        exit(EXIT_FAILURE);

    char temp[64];
    occ *head = NULL;

    while(fscanf(fp, "%s", temp) != EOF){
        occ *ptr = NULL;

        if(strlen(temp) < 2)
            continue;

        if(ptr = is_present(head, temp))
            ptr->occ++;
        else {
            ptr = (occ *) malloc(sizeof(occ));
            ptr->next = NULL;
            ptr->occ = 1;
            strcpy(ptr->str, temp);
            if(head == NULL)
                head = ptr;
            else
                head = add_node_in_order(head, ptr);
        }
    }

    return head;
}