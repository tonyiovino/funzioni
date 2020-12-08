#include <stdio.h>

/* Prototipi */
int menu(void);

double area_quadrato(double lato);
double area_cerchio(double raggio);

int main(){

    int scelta;

    double area;
    double lato, raggio;

    printf("Calcola l'area di figure geometriche\n\n");

    scelta = menu();

    switch (scelta){
        case 1:
            do {
                printf("Inserire il lato: ");
                scanf("%lf", &lato);
                putchar('\n');
            } while (lato < 0);

            area = area_quadrato(lato);
            printf("%.2f\n", area);

            break;

        case 2:
            do {
                printf("Inserire il raggio: ");
                scanf("%lf", &raggio);
                putchar('\n');
            } while (raggio < 0);

            area = area_cerchio(raggio);
            printf("%.2f\n", area);

            break;
    }

    return 0;
}

int menu(void){

    int scelta;

    do {
        printf("\nScegli la figura geometrica:\n"
                "1) Quadrato\n"
                "2) Cerchio\n\n");

        printf("Scelta: ");
        scanf("%d", &scelta);
        putchar('\n');

    } while(scelta < 1 || scelta > 2);

    return scelta;
}

double area_quadrato(double lato){
    return lato * lato;
}

double area_cerchio(double raggio){
    return 3.141592654 * raggio * raggio;
}