#include <stdio.h>
#include "save.h"
#include "guess.h"

void salvataggio_punti(int punti);
int caricamento_punti(void);

int save_chiedi_caricamento_punti(void){

    int punti = 0;
    int scelta;

    do {
        printf("Do you want load the game? (y or n): ");
        while ( (scelta = getchar()) == '\n' );

        if (scelta == 'y'){
            punti = caricamento_punti();
        }
        else if (scelta == 'n'){
            printf("Tutti i tuoi progressi non verranno caricati!\n");
            printf("Sei sicuro di continuare? ");
            while ( (scelta = getchar()) == '\n' );

            if (scelta == 'y') {
                printf("\nBuona nuova Partita!\n");
                punti = 0;
            }
            else if (scelta == 'n') {
                punti = caricamento_punti();
            }

        }
        else {
            printf("\nDigit 'y' for YES or 'n' for NO.\n\n");
        }

    } while ( ((scelta = getchar()) != '\n') && (scelta != 'y' || scelta != 'n') );


    return punti;
}

void save_chiedi_salvataggio_punti(int punti){

    int scelta;

    do {
        printf("Do you want save the game? (y or n): ");

        while ( (scelta = getchar()) == '\n' );
        if (scelta == 'y'){
            salvataggio_punti(punti);
        }
        else if (scelta == 'n'){
            printf("Tutti i tuoi progressi andranno persi!\n");
            printf("Sei sicuro di continuare? ");
            while ( (scelta = getchar()) == '\n' );

            if (scelta == 'n') {
                salvataggio_punti(punti);
            }
            else if (scelta == 'y')

        printf("\nGood Bye!\n");
        }
        else {
            printf("\nDigit 'y' for YES or 'n' for NO.\n\n");
        }

    } while ( ((scelta = getchar()) != '\n') && (scelta != 'y' || scelta != 'n') );
}

int caricamento_punti(void){

    FILE *file_punti = fopen("saved_points.txt", "r");
    int punti;


    fprintf(stdout, "\nWait a moment...\n");
    guess_count_down_or_up(2, 0, 0);

    if (!file_punti) {
        fprintf(stderr, "\nImpossibile aprire il file saved_points.txt\n");
        printf("Non esiste il file saved_points.txt\n\n");
        punti = 0;
    }
    else {
        fscanf(file_punti, "%d", &punti);
        fprintf(stdout, "Caricamento Completato!\n");
    }

    fclose(file_punti);

    return punti;
}

void salvataggio_punti(int punti){

    FILE *file_punti = fopen("saved_points.txt", "w");


    fprintf(stdout, "\nWait a moment...\n");
    guess_count_down_or_up(2, 0, 0);

    fprintf(file_punti, "%d\n", punti);

    fprintf(stdout, "Salvataggio Completato!\n");

    fclose(file_punti);
}