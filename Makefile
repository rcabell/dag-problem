CC = gcc
CFLAGS = -Wall -std=c89

OBJS = main.o graph_utils.o

all: $(OBJS)
	$(CC) $(CFLAGS) -o is_dag $(OBJS)
	$(CC) $(CFLAGS) -o build_graphs build_graphs.c graph_utils.o

clean:
	$(RM) -f is_dag build_graphs $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $<
