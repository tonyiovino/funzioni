#include <stdio.h>
#include "guess.h"

int estrai_controlla_e_punti(int numero, int punti);
/*void salvataggio_partita(void);*/

int main(){

    int numero;
    char scelta;
    int punti = 0;

    guess_init();

    /* INIZIO GIOCO */
    do {
        printf("Your points: %d\n", punti);
        printf("\nI have a number between 1 and 1000.\n"
            "Can you guess my number?\n"
            "Please type your first guess.\n\n");

        numero = guess_generate_num(1, 1000);

        punti = estrai_controlla_e_punti(numero, punti);

        printf("Would you like to play again? (y or n)\n");
        printf("Choice: ");
        if (getchar() == '\n') scelta = getchar();

    } while (scelta == 'y');

    printf("Do you want save the game? (y or n)");
    if (getchar() == '\n') scelta = getchar();

    if (scelta == 'y') {
        /*salvataggio_partita();*/
    }
    else {
        printf("Good Bye!\n");
    }    

    return 0;
}

int estrai_controlla_e_punti(int numero, int punti){

    int tentativi_max = 10, num_tentativi = 0;
    int tentativo;
    int indovinato;

    /* Temntativi */
    do {
        /* Raggiunto il limite dei tentativi */
        if (! (num_tentativi < tentativi_max) ){
            printf("\nYou have exceeded the limit of attempts (%d)\n", tentativi_max);
            printf("The number was %d\n\n", numero);
            punti += rm_punti(tentativi_max, num_tentativi);
            break;
        }

        printf("Tentativo %d: ", ++num_tentativi);
        scanf("%d", &tentativo);

        indovinato = guess_controlla_numero_e_restituisci(numero, tentativo, num_tentativi);

        putchar('\n');

        if (indovinato == 1) punti += add_punti(tentativi_max, num_tentativi);

    } while (indovinato != 1);

    return punti;
}

/*void salvataggio_partita(void){

    FILE *file_punti;
    int scelta;
    int nome_salvataggio;

    printf("Do you want save the game? (y or n)");
    if (getchar() == '\n') scelta = getchar();

    if (scelta == 'y') {
        printf("Nome salvataggio: ");
        scanf("%d", nome_salvataggio);
    }
    else {
        printf("Tutti i tuoi progressi andranno persi!");
    }
}*/