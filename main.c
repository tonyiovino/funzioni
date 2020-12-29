#include <stdio.h>

int main__menu(void);

int encry__menu(void);/*
int decry__menu(void);*/

void encry__selection(void);/*
void decry__selection(void);*/

void encry__to_text_in_number(void);
void encry__to_number_in_letter(void);

/*
void decry__to_letter_in_number(void);
void decry__to_number_in_text(void);
*/

int main(){

    int choice = main__menu();

    if (choice == 1) {
        encry__selection();
    }
    else if (choice == 2) {
        /*DECRYPT (coming soon...)
        int decry_choice = decry__menu();*/
    }
    else {
        printf("Choice 1 or 2!");
    }

    putchar('\n');

    return 0;
}

void encry__to_number_in_letter(void){

    enum Stato { NORM };

    int stato = NORM;
    int c;

    while ( (c = getchar()) != EOF ){
        if (stato == NORM){
            if (c == '0'){
                putchar('A');
            }
            else if (c == '1') {
                putchar('B');
            }
            else if (c == '2') {
                putchar('C');
            }
            else if (c == '3') {
                putchar('D');
            }
            else if (c == '4') {
                putchar('E');
            }
            else if (c == '5') {
                putchar('F');
            }
            else if (c == '6') {
                putchar('G');
            }
            else if (c == '7') {
                putchar('H');
            }
            else if (c == '8') {
                putchar('I');
            }
            else if (c == '9') {
                putchar('J');
            }
            else {
                putchar(c);
            }
        }
    }
}

void encry__to_text_in_number(void){

    enum Stato { NORM, NUM };

    int stato = NORM;
    int c;

    while ( (c = getchar()) != EOF ){
        if (stato == NORM){
            /*if (c == ' ' || c == '\n' || c == '\t') {
                printf("--");
            }
            else*/ 
            if (c == 'a' || c == 'A'){
                printf("12");
                stato = NUM;
            }
            else if (c == 'b' || c == 'B') {
                printf("76");
                stato = NUM;
            }
            else if (c == 'c' || c == 'C') {
                printf("54");
                stato = NUM;
            }
            else if (c == 'd' || c == 'D') {
                printf("34");
                stato = NUM;
            }
            else if (c == 'e' || c == 'E') {
                printf("3");
                stato = NUM;
            }
            else if (c == 'f' || c == 'F') {
                printf("45");
                stato = NUM;
            }
            else if (c == 'g' || c == 'G') {
                printf("56");
                stato = NUM;
            }
            else if (c == 'h' || c == 'H') {
                printf("67");
                stato = NUM;
            }
            else if (c == 'i' || c == 'I') {
                printf("8");
                stato = NUM;
            }
            else if (c == 'j' || c == 'J') {
                printf("78");
                stato = NUM;
            }
            else if (c == 'k' || c == 'K') {
                printf("89");
                stato = NUM;
            }
            else if (c == 'l' || c == 'L') {
                printf("90");
                stato = NUM;
            }
            else if (c == 'm' || c == 'M') {
                printf("98");
                stato = NUM;
            }
            else if (c == 'n' || c == 'N') {
                printf("87");
                stato = NUM;
            }
            else if (c == 'o' || c == 'O') {
                printf("9");
                stato = NUM;
            }
            else if (c == 'p' || c == 'P') {
                printf("0");
                stato = NUM;
            }
            else if (c == 'q' || c == 'Q') {
                printf("1");
                stato = NUM;
            }
            else if (c == 'r' || c == 'R') {
                printf("4");
                stato = NUM;
            }
            else if (c == 's' || c == 'S') {
                printf("23");
                stato = NUM;
            }
            else if (c == 't' || c == 'T') {
                printf("5");
                stato = NUM;
            }
            else if (c == 'u' || c == 'U') {
                printf("7");
                stato = NUM;
            }
            else if (c == 'v' || c == 'V') {
                printf("65");
                stato = NUM;
            }
            else if (c == 'w' || c == 'W') {
                printf("2");
                stato = NUM;
            }
            else if (c == 'x' || c == 'X') {
                printf("43");
                stato = NUM;
            }
            else if (c == 'y' || c == 'Y') {
                printf("6");
                stato = NUM;
            }
            else if (c == 'z' || c == 'Z') {
                printf("32");
                stato = NUM;
            }
            else {
                putchar(c);
            }
        }
        else if (stato == NUM) {
            if (c == EOF){
                printf(".");
            }
            else {
                printf("-");
                stato = NORM;
            }

            
        }
    }
}

int main__menu(void){

    int choice;

    printf("************************************\n"
           "************************************\n"
           "**                                **\n"
           "**      HITLOCKER'S  MESSAGE      **\n"
           "**                                **\n"
           "************************************\n"
           "************************************\n\n"
    );

    do {
        printf("Do you want to encrypt or decrypt the message?");
        printf("\n1) Encrypt;\n2) Decrypt;\n");

        printf("Insert choice (1 or 2): ");
        scanf("%d", &choice);
        putchar('\n');

    } while(choice < 1 || choice > 2);

    return choice;
}

int encry__menu(void){

    int encry_choice;

    printf("************************************\n"
           "************************************\n"
           "**                                **\n"
           "**      ENCRYPTING   MESSAGE      **\n"
           "**                                **\n"
           "************************************\n"
           "************************************\n\n"
    );

    do {
        printf("Do you want encrypt in letter or in number the message?");
        printf("\n1) To text in number;\n2) To number in letter;\n");

        printf("Insert choice (1 or 2): ");
        scanf("%d", &encry_choice);
        putchar('\n');

    } while(encry_choice < 1 || encry_choice > 2);

    return encry_choice;
}

void encry__selection(void){

    int encry_choice = encry__menu();

    if (encry_choice == 1) {
        encry__to_text_in_number();
    }
    else if (encry_choice == 2) {
        encry__to_number_in_letter();
    }
    else {
        printf("Choice 1 or 2!");
    }
}