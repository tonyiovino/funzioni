#include <stdio.h>
#include "guess.h"
#include "save.h"

int indovinato_e_aggiorna_punti(int numero, int punti);

int main(){

    int numero;
    int scelta;
    int punti;

    guess_init();

    punti = save_chiedi_caricamento_punti();

    /* INIZIO GIOCO */
    do {
        if (scelta == 'y') {
            printf(
                "***********************************\n"
                "* Hai iniziato una nuova partita! *\n"
                "***********************************\n"
            );
            guess_count_down_or_up(2, 0, 0);
        }

        printf("\n$*$*$*$*$ Your points: %d $*$*$*$*$\n", punti);
        printf("\nI have a number between 1 and 1000.\n"
            "Can you guess my number?\n"
            "Please type your first guess.\n\n");

        numero = guess_generate_num(1, 1000);

        punti = indovinato_e_aggiorna_punti(numero, punti);

        printf("Would you like to play again? (y or n)\n");
        printf("Choice: ");
        while ( (scelta = getchar()) == '\n' );

        putchar('\n');

    } while (scelta == 'y');


    save_chiedi_salvataggio_punti(punti);

    return 0;
}

int indovinato_e_aggiorna_punti(int numero, int punti){

    int tentativi_max = 10, num_tentativi = 0;
    int tentativo;
    int indovinato;

    /* Temntativi */
    do {
        /* Raggiunto il limite dei tentativi */
        if (! (num_tentativi < tentativi_max) ){
            printf("\nYou have exceeded the limit of attempts (%d)\n", tentativi_max);
            printf("The number was %d\n\n", numero);
            punti += guess_rm_punti(tentativi_max, num_tentativi);
            break;
        }

        printf("Tentativo %d: ", ++num_tentativi);
        scanf("%d", &tentativo);

        indovinato = guess_controlla_numero(numero, tentativo);

        putchar('\n');

        if (indovinato == 1) punti += guess_add_punti(tentativi_max, num_tentativi);

    } while (indovinato != 1);

    return punti;
}