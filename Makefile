CC = gcc
AR = ar -rcs
FLAGS = -Wall -g
LIB = my_mat.h
OBJECT_MAT = my_mat.o
OBJECTS_MAIN = main.o

all: libclassmat.a connections

connections: $(OBJECTS_MAIN) libclassmat.a
	$(CC) $(FLAGS) -o $@ $^

libclassmat.a: $(OBJECT_MAT)
	$(AR) $@ $^

my_mat.o: my_mat.c $(LIB)
	$(CC) $(FLAGS) -c my_mat.c

main.o: main.c $(LIB)
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a connections