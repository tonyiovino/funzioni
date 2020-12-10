#include <stdio.h>
#include <math.h>

/* Prototipi */
double ipotenusa(int lato1, int lato2);

int main(void){

    int count = 0;

    printf("Calcolare l'ipotenusa di triangoli rettangoli\n\n");

    printf("Triangolo\tLato1\tLato2\tIpotenusa\n");

    printf("\t1\t3\t4\t%.1f\n", ipotenusa(3, 4));

    printf("\t2\t5\t12\t%.1f\n", ipotenusa(5, 12));

    printf("\t3\t8\t15\t%.1f\n", ipotenusa(8, 15));

    return 0;
}


double ipotenusa(int lato1, int lato2){

    return sqrt( (lato1 * lato1) + (lato2 * lato2) );
}