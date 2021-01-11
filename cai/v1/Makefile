CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDLIBS=

main: random.o cai.o main.o

main.o: main.c cai.h
random.o: random.c random.h
cai.o : cai.c cai.h random.h

.PHONY: clean
clean:
	rm -f *.o main
