/*
  Scrivere un programma che stampa la tavola dei quadrati e dei cubi dei
  numeri da 0 a 10.
  Stampare la tavola per colonne con intestazione Numero Quadrato Cubo
  allineando i valori relativi secondo le seguenti regole:
  - la prima colonna viene stampata come numeri interi allineati a destra,
  - la seconda colonna conterrĂ  numeri con due cifre decimali allineati
    a destra,
  - la terza colonna deve contenere numeri con una cifra decimale allineati
    a sinistra.
  */

#include <stdlib.h>
#include <stdio.h>

int main(){

  printf("Numero    Quadrato    Cubo\n");

  for (int i = 0; i <= 10; i++)
    printf("%6d\t%8.2f\t%.1f\n", i, (double) i*i, (double) i*i*i);

  return EXIT_SUCCESS;

}
