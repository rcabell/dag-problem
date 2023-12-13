FC = gfortran
CC = gcc
CFLAGS = -Wall -std=c89
FFLAGS = -Wall -std=f2008

OBJS = main.o graph_utils.o is_dag.o

all: $(OBJS)
	$(CC) -o is_dag $(OBJS)

clean:
	$(RM) -f is_dag $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

# Cancel the built-in implicit rule for Modula-2 files (.mod) to avoid having
# 'make' try to create .o files from Fortran .mod files
%.o : %.mod

%.o : %.F90
	$(FC) $(FFLAGS) -c $<
