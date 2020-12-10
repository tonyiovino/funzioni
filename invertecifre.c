#include <stdio.h>

void invertiPositivo(int num);
void invertiNegativo(int num);

int main(){

    int num;

    printf("Inverte Cifre\n\n");

    printf("Inserisci un numero: ");
    scanf("%d", &num);

    printf("A cifre invertite: ");

    if (num > 0){
        invertiPositivo(num);
    }
    else if(num < 0){
        invertiNegativo(num);
    }
    else{
        printf("0");
    }

    putchar('\n');

    return 0;
}

void invertiPositivo(int num){

    int cifra;

    while (num > 0){
        cifra = num % 10;
        printf("%d", cifra);
        num /= 10;
    }
}

void invertiNegativo(int num){

    int cifra;

    putchar('-');
    num *= -1;
    while (num > 0){
        cifra = num % 10;
        printf("%d", cifra);
        num /= 10;
    }
}