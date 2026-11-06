CC=gcc
CFLAGS=-Wall -g

all: main


main: main.o mymath.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c mymath.h
	$(CC) $(CFLAGS) -c main.c

mymath.o: mymath.c mymath.h
	$(CC) $(CFLAGS) -c mymath.c

clean:
	rm -f *.o main