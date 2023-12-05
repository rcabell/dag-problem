CC = gcc
CFLAGS = -Wall -std=c89

all: main.o
	$(CC) $(CFLAGS) -o is_dag main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	\rm -f is_dag main.o
