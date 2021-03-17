#include <stdio.h>

void diventa_uno(int v[], int size);
void raddoppia(int v[], int size);
void stampa_vett(int v[], int size);
void raddoppia_intero(int *p_num);

int main(void){

	int vett[10];

	diventa_uno(vett, 10);

	printf("Valori iniziali:\n");
	stampa_vett(vett, 10);
	putchar('\n');

	raddoppia(vett, 10);


	printf("Valori finali:\n");
	stampa_vett(vett, 10);
	putchar('\n');

	return 0;
}

void diventa_uno(int v[], int size){

	int i;

	for (i = 0; i < size; i++) {
		v[i] = i + 1;
	}
}

void raddoppia(int v[], int size){

	int i;

	for (i = 0; i < size; i++) {
		raddoppia_intero(&v[i]);
	}
}

void stampa_vett(int v[], int size){

	int i;

	for (i = 0; i < size; i++) {
		printf("%4d", v[i]);
	}
}

void raddoppia_intero(int *p_num){
	*p_num *= 2;
}