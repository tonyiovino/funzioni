#include <stdio.h>
#include "cai.h"

int rispondi_e_controlla(int a, int b, int risposta_esatta, int num_domande);
void controlla_risposte_esatte(int num_esatte, int num_domande);

int main(){

    int a, b;
    int risposta_esatta;
    int num_esatte = 0;
    int num_domande = 10, num_risposte = 0;

    cai_init();

    do {
        a = cai_generate_num(0, 10);
        b = cai_generate_num(0, 10);

        risposta_esatta = a * b;

        num_esatte += rispondi_e_controlla(a, b, risposta_esatta, num_domande);
        num_risposte++;

    } while (num_risposte < num_domande);

    controlla_risposte_esatte(num_esatte, num_domande);

    return 0;
}

int rispondi_e_controlla(int a, int b, int risposta_esatta, int num_domande){

    int risposta;
    static int num_esatte = 0;

    printf("Quanto fa %d per %d? (CTRL+C per uscire)\nRisposta: ", a, b);
    scanf("%d", &risposta);

    num_esatte += cai_generate_string(risposta, risposta_esatta);
    putchar('\n');

    return num_esatte;
}

/* VEDI SE FUNZIONA  */

void controlla_risposte_esatte(int num_esatte, int num_domande){

    /* A : B = X : 100 ==> X = (A : 100) x B */
    int percentuale = num_esatte * num_domande;

    printf("Your rate is: %d\n", percentuale);

    if (percentuale < 75) printf("Please ask your instructor for extra help");

    else printf("Good Job!");

    putchar('\n');
}