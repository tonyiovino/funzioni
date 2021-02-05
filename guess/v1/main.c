#include <stdio.h>
#include "guess.h"

void tenta_e_controlla_indovinato(int numero);
int input_char(int input);
int rigioca(void);

int main(){

    int numero;
    int scelta;

    guess_init();

    do {
        printf("I have a number between 1 and 1000.\n"
            "Can you guess my number?\n"
            "Please type your first guess.\n\n");

        numero = guess_generate_num(1, 1000);
        printf("%d", numero);

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

    int scelta;

    do {
        printf("Would you like to play again? (y or n)\n");
        printf("Choice: ");
        scelta = input_char(scelta);

    } while (scelta != 'y' && scelta != 'n');

    return scelta;
}

int input_char(int input){

    int temp;
    
    /* Elimina i newline precedenti */
    while ( (temp = getchar()) != '\n' );

    input = getchar();
    if (input != '\n') {
        while ( (temp = getchar()) != '\n' );
    }

    return input;
}