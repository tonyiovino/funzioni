#include "guess.h"
#include "random.h"
#include <stdio.h>
#include <time.h>

void guess_init(void){
    random_init();
}

int guess_generate_num(int min, int max){

    int num;

    max += 1;

    num = random_between(min, max);

    return num;
}

int guess_controlla_numero_e_restituisci(int numero, int tentativo, int num_tentativi){

    int indovinato = 0;

    if (tentativo > numero){
        printf("Too high. Try again.\n");
    }
    else if (tentativo < numero) {
        printf("Too low. Try again.\n");
    }
    else {
        printf("\nExcellent! You guess the number!\n\n");
        indovinato = 1;
    }

    return indovinato;
}

void count_down_or_up(int iniziale, int finale){

    int i;
    struct timespec intervallo;

    intervallo.tv_sec = 1;
    intervallo.tv_nsec = 0;

    if (iniziale > finale){
        for (i = iniziale; i > finale; i--){
            printf("%d...\n", i);
            nanosleep(&intervallo, NULL);
        }
    }
    else if (iniziale < finale){
        for (i = iniziale; i < finale; i++){
            printf("%d...\n", i);
            nanosleep(&intervallo, NULL);
        }
    }
    else {
        printf("%d", iniziale);
        nanosleep(&intervallo, NULL);
    }


}

int add_punti(int tentativi_max, int num_tentativi){

    int punti;
    /* Moltiplicatore Random */
    int rnd_molt = guess_generate_num(1, 10);

    printf("Attendiamo l'estrazione del numero...\n");
    count_down_or_up(3, 0);

    punti = (tentativi_max - num_tentativi) * rnd_molt;

    if (rnd_molt == 10) {
        printf(
            "************************\n"
            "*  Hai fatto Jackpot!  *\n"
            "************************\n\n"
        );
    }
    else if (rnd_molt >= 5) {
        printf("Hai avuto molta fortuna!\n");
    }
    else if (rnd_molt >= 2) {
        printf(
            "Non è il massimo, ma magari la fortuna ti\n"
            "assisterà la prossima volta!\n"
        );
    }
    else {
        printf("Sfortunato... Ma meglio di niente dai!\n");
    }

    printf("Moltiplicatore Random: %d\n\n", rnd_molt);

    return punti;
}

int rm_punti(int tentativi_max, int num_tentativi){

    int punti;
    /* Moltiplicatore Random */
    int rnd_molt = guess_generate_num(1, 10);
 
    printf("Attendiamo l'estrazione del numero...\n");
    count_down_or_up(3, 0);

    punti = (int)(tentativi_max + num_tentativi) / 2 * rnd_molt;

    if (rnd_molt == 10) {
        printf("Non so che dirti... Non è colpa mia...\n");
    }
    else if (rnd_molt >= 5) {
        printf("Beh... Dai, poteva andare peggio...\n");
    }
    else if (rnd_molt >= 2) {
        printf("Fidati, ti è andata abbastanza bene.\n");
    }
    else {
        printf("\n"
            "**********************************\n"
            "*  Ti è andata proprio di culo!  *\n"
            "**********************************\n\n"
        );
    }

    printf("Moltiplicatore Random: %d\n", rnd_molt);

    return -1 * punti;
}