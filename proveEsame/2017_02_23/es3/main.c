#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct str_tag str;
struct str_tag {
  char parola[20];
  str *next;
};


str *lettura(FILE *read);
void free_str(str *head);
void scrittura(FILE *write, str *head);


int main(int argc, char *argv[]){
  FILE *read = fopen(argv[1], "r");
  FILE *write = fopen(argv[2], "w");

  if(!read || !write)
    exit(EXIT_FAILURE);

  str *list = lettura(read);
  scrittura(write, list);
  
  fclose(read);
  fclose(write);

  free_str(list);


  return EXIT_SUCCESS;
}




str *lettura(FILE *read){
  if(!read)
    exit(EXIT_FAILURE);

  str *head = (str *) malloc(sizeof(str));
  str *ptr = head;
  str *ptr_prev = head;

  while(fscanf(read, "%s", ptr->parola) != EOF){
    ptr->next = (str *) malloc(sizeof(str));
    ptr_prev = ptr;
    ptr = ptr->next;
  }

  ptr_prev->next = NULL;
  free(ptr);

  return head;
}


void free_str(str *head){
  while(head){
    str *temp = head->next;
    free(head);
    head = temp;
  }

  return;
}


void scrittura(FILE *write, str *head){
  if(!head)
    return;

  str *ptr = head;
  while(ptr){
    int is_alphabet = 1;
    int is_b_even = 1;
    int is_c_two = 1;
    int b_counter = 0;
    int c_counter = 0;

    char *str = ptr->parola;
    int len = strlen(str);
    int i = 0;

    while(str[i]){
      if(str[i] != 'a' && str[i] != 'b' && str[i] != 'c'){
        is_alphabet = 0;
        break;
      }

      if(str[i] == 'b')
        b_counter++;
      
      if(b_counter && (str[i] != 'b' || i == len - 1)){
        if(b_counter % 2){
          is_b_even = 0;
          break;
        }
        b_counter = 0;
      }

      if(str[i] == 'c')
        c_counter++;

      if(c_counter > 2){
        is_c_two = 0;
        break;
      }
      
      i++;      
    }

    printf("%s %d %d %d\n", ptr->parola, is_alphabet, is_c_two, is_b_even);
    if(is_alphabet && is_c_two && is_b_even)
      fprintf(write, "%s\n", ptr->parola);

    ptr = ptr->next;

  }

  return;
}

