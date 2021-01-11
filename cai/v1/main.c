#include <stdio.h>
#include "cai.h"

void ritenta_se_errore(int a, int b, int risposta_esatta);

int main(){

    int a, b;
    int risposta_esatta;

    cai_init();

    do {
        a = cai_generate_num(0, 10);
        b = cai_generate_num(0, 10);

        risposta_esatta = a * b;

        ritenta_se_errore(a, b, risposta_esatta);

    } while (1);

    return 0;
}

void ritenta_se_errore(int a, int b, int risposta_esatta){

    int risposta;

    do {
        printf("Quanto fa %d per %d? (CTRL+C per uscire)\nRisposta: ", a, b);
        scanf("%d", &risposta);

        if (risposta == risposta_esatta) {
            printf("Very Good!\n"); /* void risposta_giusta(void)*/
        }
        else {
            printf("No. Please Try Again\n"); /* void risposta_errata(void) */
        }

        putchar('\n');

    } while (risposta != risposta_esatta);
}