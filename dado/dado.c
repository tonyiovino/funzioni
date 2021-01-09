#include "dado.h"
#include "random.h"

void dado_init(void){
    random_init();
}

int dado_lancio(void){

    int esito = random_between(1, 7);

    return esito;
}