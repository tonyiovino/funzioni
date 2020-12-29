#include <stdio.h>
#include "random.h"
#include "coin.h"

int lancio_cento_volte(void);

int main(void){

  int testa, croce;

  random_init();

  printf("Su 100 lanci, quante volte escono \"Testa\" e \"Croce\"?\n\n");

  testa = lancio_cento_volte();

  croce = 100 - testa;

  printf("Volte Testa: %d\n", testa);
  printf("Volte Croce: %d\n", croce);

  return 0;
}

int lancio_cento_volte(void){

  int i, count = 0;

  for (i = 0; i < 100; i++){
    if ( coin_lancio() == 1 ) count++; /*È Testa Se Esce 1*/
  }

  return count;
}