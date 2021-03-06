/*
  Considerare la seguente funzione matematica:
  y = SUM (i = q...r) 1 / i
  (y uguale a sommatoria per i che va da q a r di 1 fratto i)
  Si scriva un programma per il calcolo di y.
  Si assuma di acquisire r e q dall'esterno (dati di input).
  Si controlli che r e q siano interi positivi tali che r > q.
 */

#include <stdlib.h>
#include <stdio.h>

float sommatoria(int start, int finish){
  float sum = 0;

  for (; start <= finish; start++)
    sum += (float) 1/start;

  return sum;
}

int main(){

  int q, r;

  printf("Inserisci prima q e successivamente r:\n" );
  scanf("%d", &q);
  scanf("%d", &r);

  while (q <= 0 || r <= 0 || q > r){
    printf("\nInserisci correttamente prima q e successivamente r (devono essere interi positivi con r > q:\n" );
    scanf("%d", &q);
    scanf("%d", &r);
  }

  float y = sommatoria(q, r);

  printf("\n\nLa sommatoria vale %.5f\n", y);

  return EXIT_SUCCESS;
}
