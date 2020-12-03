#include <stdio.h>

/*Prototipi*/
int menu(void);

void converti_in_binario(int num);
void converti_in_esadecimale(int num);
void converti_in_ottale(int num);

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
            converti_in_binario(decimale);
            break;
        case 2:
            converti_in_ottale(decimale);
            break;
        case 3:
            converti_in_esadecimale(decimale);
  
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


/* Converti in binario */
void converti_in_binario(int num){

    int peso = 128;
    int bit;
    int i;

    for (i = 0; i < 8; i++) {
        if (num >= peso) {
            num -= peso;
            bit = 1;
        }
        else {
            bit = 0;
        }

        peso /= 2;
        printf("%d", bit);

    }

    printf(" (2)\n");
}
void converti_in_ottale(int num){

    int peso = 64;
    int bit;
    int i;

    for (i = 0; i < 3; i++) {
        bit = num / peso;
        printf("%2d", bit);
        num %= peso;
        peso /= 8;
    }

    printf(" (8)\n");
}

void converti_in_esadecimale(int num){

    int peso = 64;
    int bit;
    int i;

    peso = 16;
    for (i = 0; i < 2; i++) {
        bit = num / peso;
        switch(bit) {
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
        num %= peso;
        peso /= 16;
    }

    printf(" (16)\n");
}