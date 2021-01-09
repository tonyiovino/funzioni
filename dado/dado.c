#include "dado.h"
#include "random.h"

int dado_lancio(void){

    int esito = random_between(1, 7);

    return esito;
}