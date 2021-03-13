#include <stdio.h>

void swap(int *a, int *b);

int main(){

	int a, b;

	printf("Swap\n\n\n");

	printf("Valori iniziali\n");

	printf("a: ");
	scanf("%d", &a);
	printf("b: ");
	scanf("%d", &b);

	swap(&a, &b);

	putchar('\n');

	printf("Dopo lo scambio\n");
	printf("a = %d\nb = %d\n\n", a, b);

	return 0;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}