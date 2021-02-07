#include <stdio.h>
#include "save.h"
#include "guess.h"
#include "io.h"

int indovinato_e_aggiorna_punti(int numero, int punti);
void print_name_game(void);

int main(){

    int numero;
    int scelta;
    int punti;

    guess_init();

    print_name_game();

    /* Caricamento di un salvataggio */
    punti = save_chiedi_caricamento_punti();

    /* Inizia Il Gioco */
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
        printf(
            "\nI have a number between 1 and 1000.\n"
            "Can you guess my number?\n"
            "Please type your first guess.\n\n"
        );

        /* Genera un numero da 1 a 1000*/
        numero = guess_generate_num(1, 1000);

        /* Esegue i tentativi, vede se hai vinto o no, e da i punti */
        punti = indovinato_e_aggiorna_punti(numero, punti);

        printf("Would you like to play again? (y or n)\n");
        printf("Choice: ");
        scelta = getchar();
        io_clean_buffer();

        putchar('\n');

    } while (scelta == 'y');

    /* Salvataggio Partita */
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
        io_clean_buffer();

        hai_indovinato = guess_controlla_numero(numero, tentativo);

    } while ( (tentativi_max > num_tentativi && hai_indovinato == 0));

    punti += guess_add_e_rm_punti(tentativi_max, num_tentativi, hai_indovinato, numero);

    return punti;
}