#include <stdio.h>

int inverti_cifre(int num);

int main(){

    int num;

    printf("Inverte Cifre\n\n");

    printf("Inserisci un numero: ");
    scanf("%d", &num);

    num = inverti_cifre(num);

    printf("A cifre invertite: %d", num);

    putchar('\n');

    return 0;
}

int inverti_cifre(int num){

    int numInverso = 0;
    int cifra;

    while (num > 0){
        cifra = num % 10;
        numInverso = (numInverso * 10) + cifra;
        num /= 10;
    }

    return numInverso;
}