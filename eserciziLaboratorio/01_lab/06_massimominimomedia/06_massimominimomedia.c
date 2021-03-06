/*
  Leggere in input una sequenza di numeri naturali (interi positivi 
  strettamente maggiori di zero) e calcolare e visualizzare il massimo, 
  il minimo e la media.
  La sequenza si interrompe non appena viene introdotto un numero negativo 
  o uguale a zero
  Per esempio, data la sequenza 5, 1, 2, 3, 6, -5, l'output deve essere: 
  "Il massimo è 6, il minimo è 1, la media è 3.4".
  Data la sequenza -2, l'output deve essere "La sequenza inserita è nulla".
*/

#include <stdlib.h>
#include <stdio.h>

int main(){

  int counter = 0;
  int max, min;
  int num, sum = 0;

  printf("Immetti il primo numero naturale positivo. Immetti un numero negativo o pari a 0 per terminare l'inserimento: ");
  scanf("%d", &num);
  min = num;
  max = num;
  
  while (num > 0){
    counter++;
    if (num > max)
      max = num;
    if (num < min)
      min = num;
    sum += num;
    printf("Immetti un numero naturale positivo. Immetti un numero negativo o pari a 0 per terminare l'inserimento: ");
    scanf("%d", &num);
  }

  if (counter == 0){
    printf("Non sono stati inseriti numeri validi");
    return EXIT_SUCCESS;
  }

  printf("\n\nIl massimo è %d, il minimo è %d, la media è %.2f\n", max, min, (float)sum/counter);

  return EXIT_SUCCESS;

}
