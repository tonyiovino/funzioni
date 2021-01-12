#include "cai.h"
#include "random.h"
#include <stdio.h>

void cai_init(void){
    random_init();
}

int cai_generate_num(int min, int max){

    int num;

    max += 1;

    num = random_between(min, max);

    return num;
}

void cai_generate_string(int risposta, int risposta_esatta){

    int num = cai_generate_num(1, 4);

    if (risposta == risposta_esatta) cai_risposta_esatta(num);

    else cai_risposta_errata(num);
    
    putchar('\n');

}

void cai_risposta_esatta(int num){

    switch (num) {
        case 1:
            printf("Very good!");
            break;
        case 2:
            printf("Excellent!");
            break;
        case 3:
            printf("Nice work!");
            break;
        case 4:
            printf("Keep up the good work!");
            break;
        default:
            printf("Error");
            break;
    }
}

void cai_risposta_errata(int num){

    switch (num) {
        case 1:
            printf("No. Please try again.");
            break;
        case 2:
            printf("Wrong. Try once more.");
            break;
        case 3:
            printf("Don't give up!");
            break;
        case 4:
            printf("No. Keep trying.");
            break;
        default:
            printf("Error");
            break;
    }
}
