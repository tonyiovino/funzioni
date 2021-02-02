#include <stdio.h>
#include "save.h"

void salvataggio_punti(int punti);
int caricamento_punti(void);

int save_chiedi_caricamento_punti(void){

    int punti = 0;
    int scelta;

    /*do {*/
        printf("Do you want load the game? (y or n): ");
        while ( (scelta = getchar()) != '\n' );

        if (scelta == 'y'){
            punti = caricamento_punti();            
        }
        else if (scelta == 'n'){
            printf("Tutti i tuoi progressi non verranno caricati!\n");
            printf("Sei sicuro di continuare? ");
            while ( (scelta = getchar()) != '\n' );

            if (scelta == 'y') {
                printf("\nBuona nuova Partita!\n");

            }
            else if (scelta == 'n') {
                punti = caricamento_punti();
            }
        }
        else {
            printf("\nDigit 'y' for YES or 'n' for NO.\n\n");
        }

    /*} while (scelta != 'y' || scelta != 'n');*/

    return punti;
}

void save_chiedi_salvataggio_punti(int punti){

    int scelta;

    /*do {*/
        printf("Do you want save the game? (y or n): ");
        while ( (scelta = getchar()) != '\n' );


        if (scelta == 'y'){
            salvataggio_punti(punti);
        }
        else if (scelta == 'n'){
            printf("Tutti i tuoi progressi andranno persi!\n");
            printf("Sei sicuro di continuare? ");
            while ( (scelta = getchar()) != '\n' );

            if (scelta == 'y') {
                printf("\nGood Bye!\n");
            }
            else if (scelta == 'n') {
                salvataggio_punti(punti);
            }
        }
        else {
            printf("\nDigit 'y' for YES or 'n' for NO.\n\n");
        }
    /*} while (scelta != 'y' || scelta != 'n');*/
}

void salvataggio_punti(int punti){

    FILE *file_punti = fopen("saved_points.txt", "w");

    fprintf(file_punti, "%d\n", punti);

    fclose(file_punti);
}

int caricamento_punti(void){

    FILE *file_punti = fopen("saved_points.txt", "r");
    int punti;

    if (!file_punti) {
        fprintf(stderr, "\nImpossibile aprire il file saved_points.txt\n");
        printf("Non esiste il file saved_points.txt\n\n");
        punti = 0;
    }
    else {
        fscanf(file_punti, "%d", &punti);
    }

    fclose(file_punti);

    return punti;
}