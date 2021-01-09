#include <stdio.h>
#include "coin.h"

int simulazione_moneta(int volte);

int main(void){

  int testa, croce;
  int volte = 100;

  coin_init();

  printf("Su 100 lanci, quante volte escono \"Testa\" e \"Croce\"?\n\n");

  testa = simulazione_moneta(volte);

  croce = volte - testa;

  printf("Volte Testa: %d\n", testa);
  printf("Volte Croce: %d\n", croce);

  return 0;
}

int simulazione_moneta(int volte){

  int i, count = 0;

  for (i = 0; i < volte; i++){
    if ( coin_lancio() == 1 ) count++; /*È Testa Se Esce 1*/
  }

  return count;
}