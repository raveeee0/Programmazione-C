/*
  Scrivere un programma che chieda all'utente di inserire due frazioni di
  segno positivo nel formato "numeratore / denominatore", calcoli il
  risultato della somma e lo stampi a video.
*/


#include <stdlib.h>
#include <stdio.h>

int main(){

  int num1, den1, num2, den2;

  printf("Inserisci la prima frazione nel formato \"numeratore / denominatore\": ");
  scanf("%d/%d", &num1, &den1);

  printf("\nInserisci la prima seconda nel formato \"numeratore / denominatore\": ");
  scanf("%d/%d", &num2, &den2);

  double fract1 = (double) num1/den1;
  double fract2 = (double) num2/den2;

  double somma = fract1 + fract2;

  printf("\n\nLa somma è: %f\n", somma);

  return EXIT_SUCCESS;

}


