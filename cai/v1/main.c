#include <stdio.h>
#include "cai.h"

void ritenta_se_errore(int a, int b, int risposta_esatta);

int main(){

    int a, b;
    int risposta_esatta;

    cai_init();

    while (1){
        a = cai_generate_num(0, 10);
        b = cai_generate_num(0, 10);

        risposta_esatta = a * b;

        ritenta_se_errore(a, b, risposta_esatta);
    } 

    return 0;
}

void ritenta_se_errore(int a, int b, int risposta_esatta){

    int risposta;

    do {
        printf("Quanto fa %d per %d? (CTRL+C per uscire)\nRisposta: ", a, b);
        scanf("%d", &risposta);

        cai_generate_string(risposta, risposta_esatta);

        putchar('\n');

    } while (risposta != risposta_esatta);
}