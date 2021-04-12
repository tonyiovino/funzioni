#include <stdio.h>

int fibonacci_helper(int n, int cache[]);
int fibonacci(int n);

int main(){

	int i;

	for (i = 0; i < 5; i++) {
		printf("%d ", fibonacci(i));
	}

	putchar('\n');

	return 0;
}

int fibonacci(int n){

	static int cache[47];

	if (n > 47) {
		printf("Il limite massimo è 47\n\n");
		return n;
	}

	return fibonacci_helper(n, cache);
}

int fibonacci_helper(int n, int cache[]) {

    if (n == 0 || n == 1) return n;

	if (cache[n]){
		return cache[n];
	}

	cache[n] = fibonacci_helper(n-1, cache) + fibonacci_helper(n-2, cache);

    return cache[n];
}