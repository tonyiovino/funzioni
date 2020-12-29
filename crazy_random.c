#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Prototipi */
int crazy_random(void);

int main(){

  int i;

  srand( time(NULL) );

  printf("Crazy Random\n\n");

  printf("Estrae tre numeri pari:\n");
  for (i = 0; i < 3; i++) {
    printf("%d\n", crazy_random());
  }

  putchar('\n');

  printf("D'ora in avanti estrae solo numeri dispari:\n");
  for (i = 0; i < 3; i++) {
    printf("%d\n", crazy_random());
  }


  return 0;
}

int crazy_random(void){

  static int count = 0;

  int num;
  int min = 0, max = 4;

  if (count < 3) {
    num = 2 * ( rand() % (max - min) );
  }
  else {
    num = 2 * ( rand() % (max - min) ) + 1;
  }

  count++;

  return num;
}