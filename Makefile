CC = gcc
CFLAGS = -g -Wall
default: fitness
fitness: main.o fitness.o
	$(CC) $(CFLAGS) -o fitness main.o fitness.o
main.o: main.c fitness.h
	$(CC) $(CFLAGS) -c main.c
fitness.o: fitness.c fitness.h
	$(CC) $(CFLAGS) -c fitness.c
clean:
	rm -f fitness *.o
