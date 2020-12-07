#include <stdio.h>

/*Prototipi*/
int menu(void);

void converti(int num, int base);

int main(void){

    int decimale;
    int scelta;

    printf("Conversione da decimale a binario, ottale ed esadecimale\n\n");

    do {
        printf("Inserisci il numero da convertire (0-255): ");
        scanf("%d", &decimale);

    } while (decimale < 0 || decimale > 255);

    scelta = menu();

    printf("Scelta: %d\n", scelta);

    switch (scelta){
        case 1:
            converti(decimale, 2);
            break;
        case 2:
            converti(decimale, 8);
            break;
        case 3:
            converti(decimale, 16);
            break;
    }

    return 0;
}

/* Menù */
int menu(void){

    int scelta;

    do {
        printf("\nScegli la base:\n"
                "1) Binario\n"
                "2) Ottale\n"
                "3) Esadecimale\n\n");

        printf("Scelta: ");
        scanf("%d", &scelta);
        putchar('\n');

    } while(scelta < 1 || scelta > 3);

    return scelta;
}

/* Converti */
void converti(int num, int base){

    int peso;
    int posti;
    int bit;
    int i;
    int count = 0;

    switch (base){
        case 2:
            peso = 128;
            posti = 8;
            break;
        case 8:
            peso = 64;
            posti = 3;
            break;
        case 16:
            peso = 16;
            posti = 2;
            break;
        default:
            printf("Base deve essere 2, 8 oppure 16!\n");
            count = 1;
            break;
    }

    if (count == 1){
        return;
    }

    for (i = 0; i < posti; i++){
        bit = num / peso;
        num %= peso;
        peso /= base;

        switch (bit){
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                printf("%d", bit);
            break;
            case 10:
                printf("A");
            break;
            case 11:
                printf("B");
            break;
            case 12:
                printf("C");
            break;
            case 13:
                printf("D");
            break;
            case 14:
                printf("E");
            break;
            case 15:
                printf("F");
            break;
            default:
                printf(" ");
        }
    }
    printf(" (%d)\n", base);
}