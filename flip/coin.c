#include "coin.h"
#include "random.h"
#include <stdio.h>

int coin_lancio(void){

    int esito = random_between(1, 3);

    return esito;
}