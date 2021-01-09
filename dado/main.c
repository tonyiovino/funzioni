#include <stdio.h>
#include "dado.h"

void simula_dado(int volte);
void stampa_asterischi(int num);

int main(){

    dado_init();

    simula_dado(100);

    return 0;
}

void simula_dado(int volte){

    int i;
    int facce[7];
    int num;
    
    for (i = 1; i < 7; i++) {
        facce[i] = 0;
    }

    for (i = 0; i < volte; i++){
        num = dado_lancio();
        facce[num]++;
    }

    for (i = 1; i < 7; i++) {
        printf("#%d) %2d  ", i, facce[i]);
        stampa_asterischi( facce[i] );
    }
}

void stampa_asterischi(int num){
    int i;

    for (i = 0; i < num; i++) {
        putchar('*');
    }
    putchar('\n');
}