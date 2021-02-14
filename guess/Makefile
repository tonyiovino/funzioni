CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDLIBS=

main: random.o guess.o main.o io.o

main.o: main.c guess.h io.h
random.o: random.c random.h
guess.o: guess.c guess.h random.h
io.o: io.c io.h

.PHONY: clean
clean:
	rm -f *.o main