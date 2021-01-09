#include "coin.h"
#include "random.h"

void coin_init(void){
    random_init();
}

int coin_lancio(void){

    int esito = random_between(1, 3);

    return esito;
}