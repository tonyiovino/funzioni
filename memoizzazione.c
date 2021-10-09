#include <stdio.h>

int fibonacci_helper(int n, int cache[], int size_cache);
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

	return fibonacci_helper(n, cache, 47);
}

int fibonacci_helper(int n, int cache[], int size_cache) {

	if (n == 0 || n == 1) return n;

	if (cache[n]){
		return cache[n];
	}

	if (n > size_cache) {
		printf("Il limite massimo è %d\n\n", size_cache);
		return n;
	}

	cache[n] = fibonacci_helper(n-1, cache, size_cache) + fibonacci_helper(n-2, cache, size_cache);

	return cache[n];
}