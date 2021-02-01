#include <stdio.h>
#include "guess.h"

int estrai_controlla_e_punti(int numero, int punti);
void chiedi_salvataggio_partita(int punti);
int chiedi_caricamento_partita(void);

int main(){

    int numero;
    char scelta;
    int punti;

    guess_init();

    punti = chiedi_caricamento_partita();
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

    chiedi_salvataggio_partita(punti);

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

void chiedi_salvataggio_partita(int punti){

    FILE *file_punti;
    char scelta;

    do {
        printf("Do you want save the game? (y or n): ");
        if (getchar() == '\n') scelta = getchar();

        if (scelta == 'y'){
            file_punti = fopen("saved_points.txt", "w");
            fprintf(file_punti, "%d\n", punti);
            fclose(file_punti);
        }
        else if (scelta == 'n'){
            printf("Tutti i tuoi progressi andranno persi!\n");
            printf("Sei sicuro di continuare? ");
            if (getchar() == '\n') scelta = getchar();

            if (scelta == 'y') {
                printf("\nGood Bye!\n");
            }
            else if (scelta == 'n') {
                file_punti = fopen("saved_points.txt", "w");
                fprintf(file_punti, "%d\n", punti);
                fclose(file_punti);
            }
        }
        else {
            printf("\nDigit 'y' for YES or 'n' for NO.\n\n");
        }
    } while (scelta != 'y' || scelta != 'n');
}

int chiedi_caricamento_partita(void){

    FILE *file_punti;
    int punti;
    char scelta;

    do {
        printf("Do you want load the game? (y or n): ");
        if (getchar() == '\n') scelta = getchar();

        if (scelta == 'y'){
            file_punti = fopen("saved_points.txt", "r");
            if (!file_punti) {
                fprintf(stderr, "\nImpossibile aprire il file saved_points.txt\n");
                printf("Non esiste il file saved_points.txt\n");
                punti = 0;
            }
            else {
                fscanf(file_punti, "%d", &punti);
            }
            
        }
        else if (scelta == 'n'){
            printf("Tutti i tuoi progressi non verranno caricati!\n");
            printf("Sei sicuro di continuare? ");
            if (getchar() == '\n') scelta = getchar();

            if (scelta == 'y') {
                printf("\nBuona nuova Partita!\n");
            }
            else if (scelta == 'n') {
                file_punti = fopen("saved_points.txt", "r");
                if (!file_punti) {
                    fprintf(stderr, "Impossibile aprire il file saved_points.txt\n");
                    printf("Non esiste il file saved_points.txt\n");
                    punti = 0;
                }
                else {
                    fscanf(file_punti, "%d", &punti);
                }
            }
        }
        else {
            printf("\nDigit 'y' for YES or 'n' for NO.\n\n");
        }

        putchar('\n');
        putchar(scelta);
        putchar('\n');
        putchar('\n');

    } while (scelta == 'y' || scelta != 'n');

    fclose(file_punti);

    return punti;
}