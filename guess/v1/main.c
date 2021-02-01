#include <stdio.h>
#include "guess.h"

void tenta_e_controlla_indovinato(int numero);
int rigioca(void);

int main(){

    int numero;
    char scelta;

    guess_init();

    do {
        printf("I have a number between 1 and 1000.\n"
            "Can you guess my number?\n"
            "Please type your first guess.\n\n");

        numero = guess_generate_num(1, 1000);

        tenta_e_controlla_indovinato(numero);

        scelta = rigioca();

        putchar('\n');

    } while (scelta == 'y');

    printf("Good Bye!\n");

    return 0;
}

void tenta_e_controlla_indovinato(int numero){

    int tentativo;
    int indovinato;

    do {
        printf("Tentativo: ");
        scanf("%d", &tentativo);

        indovinato = guess_controlla_numero(numero, tentativo);

        putchar('\n');

    } while (indovinato != 1);

}

int rigioca(void){

    char scelta;

    printf("Would you like to play again (y or n)?\n");
    printf("Choice: ");
    if (getchar() == '\n') scelta = getchar();

    return scelta;
}