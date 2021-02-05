#include <stdio.h>
#include "guess.h"
#include "save.h"

int indovinato_e_aggiorna_punti(int numero, int punti);
void print_name_game(void);

int main(){

    int numero;
    int scelta;
    int punti;

    guess_init();

    print_name_game();

    punti = save_chiedi_caricamento_punti();

    /* INIZIO GIOCO */
    do {
        if (scelta == 'y') {
            printf(
                "\t\t***********************************\n"
                "\t\t* Hai iniziato una nuova partita! *\n"
                "\t\t***********************************\n"
            );
            guess_count_down_or_up(2, 0, 0);
        }

        printf("\n\t\t\t\t\t$*$*$*$ Your points: %d $*$*$*$\n", punti);
        printf("\nI have a number between 1 and 1000.\n"
            "Can you guess my number?\n"
            "Please type your first guess.\n\n");

        numero = guess_generate_num(1, 1000);

        punti = indovinato_e_aggiorna_punti(numero, punti);

        printf("Would you like to play again? (y or n)\n");
        printf("Choice: ");
        scelta = save_input_char(scelta);

        putchar('\n');

    } while (scelta == 'y');

    save_chiedi_salvataggio_punti(punti);

    printf("\nGood Bye!\n");

    return 0;
}

void print_name_game(void){

    printf(
        "\t**************************************************************\n"
        "\t*   ****    *    *  *****   ****   ****    *     *     ***   *\n"
        "\t*  *    *   *    *  *      *      *        *     *    *   *  *\n"
        "\t*  *        *    *  *****   ***    ***      *   *        *   *\n"
        "\t*  *   ***  *    *  *          *      *      * *       *     *\n"
        "\t*   *****    ****   *****  ****   ****        *   *   *****  *\n"
        "\t**************************************************************\n\n"
    );
}

int indovinato_e_aggiorna_punti(int numero, int punti){

    int tentativi_max = 10, num_tentativi = 0;
    int tentativo;
    int hai_indovinato;

    /* Tentativi e controlla se indovinato */
    do {
        printf("Tentativo %d: ", ++num_tentativi);
        scanf("%d", &tentativo);

        hai_indovinato = guess_controlla_numero(numero, tentativo);

    } while ( (tentativi_max > num_tentativi && hai_indovinato == 0));

    punti += guess_add_e_rm_punti(tentativi_max, num_tentativi, hai_indovinato, numero);

    return punti;
}