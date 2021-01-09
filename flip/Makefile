CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDLIBS=

main: random.o coin.o main.o

main.o: main.c coin.h
random.o: random.c random.h
coin.o: coin.c coin.h random.h

.PHONY: clean
clean:
	rm -f *.o main
