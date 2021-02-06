CC=gcc
CFLAGS=-Wall -pedantic
LDLIBS=

main: random.o guess.o main.o save.o io.o

main.o: main.c guess.h save.h io.h
random.o: random.c random.h
guess.o: guess.c guess.h random.h
save.o: save.c save.h guess.h io.h
io.o: io.c io.h

.PHONY: clean
clean:
	rm -f *.o main