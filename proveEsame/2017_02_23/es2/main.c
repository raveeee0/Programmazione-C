#include<stdio.h>
#include<stdlib.h>

int cifra_max(int num, int max /* 0 */);


int main(){
  fprintf(stdout, "Cifra max: %d\n", cifra_max(12399453, 0));

  return EXIT_SUCCESS;
}


int cifra_max(int num, int max /* 0 */){
  if(num > 9){
    int last = num % 10;
    if(last > max)
      max = last;

    return cifra_max(num/10, max);
  }

  if(num > max)
    return num;

  return max;
}
