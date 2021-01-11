#include "random.h"

void cai_init(void){
    random_init();
}

int cai_generate_num(int min, int max){

    int num;

    max += 1;

    num = random_between(min, max);

    return num;
}