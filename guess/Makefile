CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDLIBS=

main: random.o guess.o main.o

main.o: main.c guess.h
random.o: random.c random.h
guess.o : guess.c guess.h random.h

.PHONY: clean
clean:
	rm -f *.o main