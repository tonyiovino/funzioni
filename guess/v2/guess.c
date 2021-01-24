#include "guess.h"
#include "random.h"
#include <stdio.h>

void guess_init(void){
    random_init();
}

int guess_generate_num(int min, int max){

    int num;

    max += 1;

    num = random_between(min, max);

    return num;
}

int guess_controlla_numero(int numero, int tentativo){

    int count = 0;

    if (tentativo > numero){
        printf("Too high. Try again.\n");
    }
    else if (tentativo < numero) {
        printf("Too low. Try again.\n");
    }
    else {
        printf("\nExcellent! You guess the number!\n");
        count++;
    }

    return count;
}