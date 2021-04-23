#include <stdio.h>

void vett_init(int *pv, int size);
void vett_raddoppia(int *pv, int size);
void vett_stampa(int *pv, int size);

int main(){

	int num[10];

	printf("Vettori e Puntatori\n\n");

	printf("Valori iniziali\n");
	vett_init(num, 10);
	vett_stampa(num, 10);
	putchar('\n');

	printf("Valori finali\n");
	vett_raddoppia(num, 10);
	vett_stampa(num, 10);
	putchar('\n');

	return 0;
}

void vett_init(int *pv, int size){

	int i;

	for (i = 0; i < size; i++) {
		*(pv+i) = 1;
	}
}

void vett_raddoppia(int *pv, int size){

	int i;

	for (i = 0; i < size; i++) {
		*(pv+i) = (*(pv+i) + i) * 2;
	}
}

void vett_stampa(int *pv, int size){

	int i;

	for (i = 0; i < size; i++) {
		printf("%d ", *(pv+i));
	}
	putchar('\n');
}
