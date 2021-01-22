#include <stdio.h>
#include "guess.h"

int estrai_e_controlla(int numero);

int main(){

    int numero;
    int scelta;

    guess_init();

    do {
        printf("I have a number between 1 and 1000.\n"
            "Can you guess my number?\n"
            "Please type your first guess.\n\n");

        numero = guess_generate_num(1, 1000);

        scelta = estrai_e_controlla(numero);
        putchar('\n');
    } while (scelta == 'y');

    printf("Good Bye!\n");

    return 0;
}

int estrai_e_controlla(int numero){

    int tentativo;
    int indovinato;
    char scelta;

    do {
        printf("Tentativo: ");
        scanf("%d", &tentativo);

        indovinato = guess_controlla_numero(numero, tentativo);

        putchar('\n');

    } while (indovinato != 1);

    printf("Scelta: ");
    scanf("%s", &scelta);

    return scelta;
}