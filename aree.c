#include <stdio.h>

/* Prototipi */
double area_quadrato(double lato);
double area_cerchio(double raggio);

int main(){

    int scelta;

    double area;
    double lato, raggio;

    printf("Calcola l'area di figure geometriche\n\n");

    do {
        printf("\nScegli la figura geometrica:\n"
                "1) Quadrato\n"
                "2) Cerchio\n\n");

        printf("Scelta: ");
        scanf("%d", &scelta);
        putchar('\n');

    } while(scelta < 1 || scelta > 2);

    switch (scelta){
        case 1:
            printf("Inserire il lato: ");
            scanf("%le", &lato);
            area = area_quadrato(lato);
            printf("%f\n", area);
            break;
        case 2:
            printf("Inserire il raggio: ");
            scanf("%le", &raggio);
            area = area_cerchio(raggio);
            printf("%f\n", area);
            break;
    }

    return 0;
}

double area_quadrato(double lato){
    return lato * lato;
}

double area_cerchio(double raggio){
    return 3.141592654 * raggio * raggio;
}