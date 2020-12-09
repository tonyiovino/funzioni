#include <stdio.h>
#include <math.h>

/* Prototipi */
double ipotenusa(int lato1, int lato2);

int main(void){

    double ipotenusa1, ipotenusa2, ipotenusa3;

    printf("Calcolare l'ipotenusa di triangoli rettangoli\n\n");

    printf("Triangolo\tLato1\tLato2\tIpotenusa\n");

    ipotenusa1 = ipotenusa(3, 4);
    printf("\t1\t3\t4\t%.1f\n", ipotenusa1);

    ipotenusa2 = ipotenusa(5, 12);
    printf("\t2\t5\t12\t%.1f\n", ipotenusa2);

    ipotenusa3 = ipotenusa(8, 15);
    printf("\t3\t8\t15\t%.1f\n", ipotenusa3);

    return 0;
}


double ipotenusa(int lato1, int lato2){

    double ipotenusa;

    ipotenusa = sqrt( (lato1 * lato1) + (lato2 * lato2) );

    return ipotenusa;
}