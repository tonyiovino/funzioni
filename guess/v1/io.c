#include <stdio.h>
#include "io.h"

void io_clean_buffer(void){

    int temp;

    while ( (temp = getchar()) != '\n' )
    ;
}