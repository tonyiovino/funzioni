#include <stdio.h>

void diventa_uno(int v[], int size);
void raddoppia(int v[], int size);
void stampa_vett(int v[], int size);

int main(void){

	int vett[10];

	diventa_uno(vett, 10);

	raddoppia(vett, 10);

	stampa_vett(vett, 10);

	return 0;
}

void diventa_uno(int v[], int size){

	int i;

	for (i = 0; i < size; i++) {
		v[i] = 1;
	}
}

void raddoppia(int v[], int size){

	int i;

	for (i = 0; i < size; i++) {
		v[i] *= 2; 
	}
}

void stampa_vett(int v[], int size){

	int i;

	for (i = 0; i < size; i++) {
		printf("Vettore n°%d: %d\n", i, v[i]);
	}
}