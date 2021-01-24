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

    int i = 0;
    int tentativo;
    int indovinato;
    char scelta;

    do {
        if (! (i < 10) ){
            printf("\nYou have exceeded the limit of attempts (10)\n");
            printf("The number was %d\n\n", numero);
            break;
        }

        printf("Tentativo %d: ", ++i);
        scanf("%d", &tentativo);

        indovinato = guess_controlla_numero(numero, tentativo);
        putchar('\n');

    } while (indovinato != 1);

    printf("Would you like to play again? (y or n)\n");
    printf("Choice: ");
    scanf("%s", &scelta);

    return scelta;
}