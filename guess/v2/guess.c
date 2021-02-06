#include <stdio.h>
#include <time.h>
#include "guess.h"
#include "random.h"

void guess_init(void){
    random_init();
}

int guess_generate_num(int min, int max){

    int num;

    max += 1;

    num = random_between(min, max);

    return num;
}

int guess_controlla_numero(int numero, int tentativo){

    int hai_indovinato = 0;

    if (tentativo > numero){
        printf("\t\t **-** Too high. Try again. **-**\n");
    }
    else if (tentativo < numero) {
        printf("\t\t **-** Too low. Try again. **-**\n");
    }
    else {
        printf("\t\t **$** Excellent! You guess the number! **$**\n");
        hai_indovinato = 1;
    }

    return hai_indovinato;
}

void guess_count_down_or_up(int iniziale, int finale, int stampa){

    int i = 0;
    struct timespec intervallo;

    intervallo.tv_sec = 1;
    intervallo.tv_nsec = 0;

    if (iniziale > finale){
        for (i = iniziale; i > finale; i--){
            if (stampa == 1) {
                printf("%d...\n", i);
            }
            nanosleep(&intervallo, NULL);
        }
    }
    else if (iniziale < finale){
        for (i = iniziale; i < finale; i++){
            if (stampa == 1) {
                printf("%d...\n", i);
            }
            nanosleep(&intervallo, NULL);
        }
    }
    else {
        if (stampa == 1) {
            printf("%d...\n", i);
        }
        nanosleep(&intervallo, NULL);
    }
}

int guess_add_e_rm_punti(int tentativi_max, int num_tentativi, int hai_indovinato, int numero){

    int punti = 0;
    int rnd_molt = guess_generate_num(1, 100); /* Moltiplicatore Random */

    /* Calcolo punti */
    punti = (int)((num_tentativi / tentativi_max) * 10 + 1) * rnd_molt;

    if (num_tentativi == tentativi_max && hai_indovinato != 1){
        printf("\nYou have exceeded the limit of attempts (%d)\n", tentativi_max);
        printf("The number was %d\n\n", numero);

        punti *= -1;
    }
    guess_count_down_or_up(1, 0, 0);

    printf("\nAttendiamo l'estrazione del numero...\n");
    guess_count_down_or_up(3, 0, 1);

    if (hai_indovinato == 1){
        guess_print_vittoria(rnd_molt);
    }
    else {
        guess_print_sconfitta(rnd_molt);
    }

    printf("\nMoltiplicatore Random: %d\n", rnd_molt);
    printf("Aggiunti %d punti.\n\n", punti);

    return punti;
}

void guess_print_vittoria(int moltiplicatore){

    putchar('\n');

    if (moltiplicatore == 100) {
        printf(
            "************************\n"
            "*  Hai fatto Jackpot!  *\n"
            "************************\n\n"
        );
    }
    else if (moltiplicatore >= 50) {
        printf("Hai avuto molta fortuna!\n");
    }
    else if (moltiplicatore >= 20) {
        printf(
            "Non è il massimo, ma magari la fortuna ti\n"
            "assisterà la prossima volta!\n"
        );
    }
    else {
        printf("Sfortunato... Ma meglio di niente dai!\n");
    }
}

void guess_print_sconfitta(int moltiplicatore){

    putchar('\n');

    if (moltiplicatore == 100) {
        printf("Non so che dirti... Non è colpa mia...\n");
    }
    else if (moltiplicatore >= 50) {
        printf("Beh... Dai, poteva andare peggio...\n");
    }
    else if (moltiplicatore >= 20) {
        printf("Fidati, ti è andata abbastanza bene.\n");
    }
    else {
        printf(
            "**********************************\n"
            "*  Ti è andata proprio di culo!  *\n"
            "**********************************\n\n"
        );
    }
}