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

int guess_controlla_numero_e_restituisci(int numero, int tentativo){

    int indovinato = 0;

    if (tentativo > numero){
        printf("Too high. Try again.\n");
    }
    else if (tentativo < numero) {
        printf("Too low. Try again.\n");
    }
    else {
        printf("Excellent! You guess the number!\nWould you like to play again (y or n)?");
        indovinato = 1;
    }

    return indovinato;
}