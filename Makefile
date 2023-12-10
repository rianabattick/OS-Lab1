# list/Makefile
#
# Makefile for list implementation and test file.
#
# <RBattick>

CC=gcc
CFLAGS=-Wall

list: list.o main.o
	$(CC) $(CFLAGS) list.o main.o -o list

list.o: list.c
	$(CC) $(CFLAGS) -c list.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o list
