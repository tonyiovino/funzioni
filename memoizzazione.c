#include <stdio.h>

int fibonacci_helper(int n, int cache[], int size_cache);
int fibonacci(int n);

int main(){

	int i;

	for (i = 0; i < 10; i++) {
		printf("%d ", fibonacci(i));
	}

	putchar('\n');

	return 0;
}

int fibonacci(int n){

	#define CACHE_SIZE 30
	static int cache[CACHE_SIZE];

	cache[0] = 0;
	cache[1] = 1;

	if (n >= CACHE_SIZE) {
		printf("fibonacci(): Il limite massimo è %d\n\n", CACHE_SIZE-1);
		return -1;
	}

	return fibonacci_helper(n, cache, CACHE_SIZE);
}

int fibonacci_helper(int n, int cache[], int size_cache) {

	if (n == 0 || n == 1) return n;

	if (n >= size_cache) {
		printf("fibonacci_helper(): Il limite massimo è %d\n\n", size_cache-1);
		return -1;
	}
	
	if (cache[n]) return cache[n];

	cache[n] = fibonacci_helper(n-1, cache, size_cache) + fibonacci_helper(n-2, cache, size_cache);

	return cache[n];
}