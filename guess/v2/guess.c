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

    int indovinato = 0;

    if (tentativo > numero){
        printf("\t\t**-** Too high. Try again. **-**\n");
    }
    else if (tentativo < numero) {
        printf("\t\t**-** Too low. Try again. **-**\n");
    }
    else {
        printf("\t\t**$** Excellent! You guess the number! **$**\n");
        indovinato = 1;
    }

    return indovinato;
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

int guess_add_punti(int tentativi_max, int num_tentativi){

    int punti;
    /* Moltiplicatore Random */
    int rnd_molt = guess_generate_num(1, 100);

    printf("Attendiamo l'estrazione del numero...\n");
    guess_count_down_or_up(3, 0, 1);

    punti = (tentativi_max - num_tentativi) * rnd_molt;

    guess_print_vittoria(rnd_molt);

    printf("Moltiplicatore Random: %d\n\n", rnd_molt);

    return punti;
}

int guess_rm_punti(int tentativi_max, int num_tentativi){

    int punti;
    /* Moltiplicatore Random */
    int rnd_molt = guess_generate_num(1, 100);
 
    printf("Attendiamo l'estrazione del numero...\n");
    guess_count_down_or_up(3, 0, 1);

    punti = (int)(tentativi_max + num_tentativi) / 2 * rnd_molt;

    guess_print_sconfitta(rnd_molt);

    printf("Moltiplicatore Random: %d\n", rnd_molt);

    return -1 * punti;
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