#include <stdio.h>
#include "random.h"

void print_num(int min, int max);

int main(void){

  random_init();

  printf("Random\nModulo per la generazione di numeri pseudocasuali\n");

  print_num(1, 1);
  print_num(1, 2);
  print_num(1, 3);
  print_num(100, 150);

  return 0;
}

void print_num(int min, int max){

  int i;

  putchar('\n');

  printf("5 numeri compresi tra %d e %d:\n", min, max);
  for (i = 0; i < 5; i++){
    printf("%d\n", random_between(min, max));
  }
}