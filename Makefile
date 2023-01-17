CC = gcc
FLAGS = -Wall -g


all: graph

graph: graph.o nodes.o edges.o algo.o main.o
	$(CC) $(FLAGS) -o graph graph.o nodes.o edges.o algo.o main.o

graph.o: graph.c graph.h edges.h nodes.h
	$(CC) $(FLAGS) -c graph.c

nodes.o: nodes.c nodes.h graph.h edges.h
	$(CC) $(FLAGS) -c nodes.c

edges.o: edges.c edges.h graph.h
	$(CC) $(FLAGS) -c edges.c

algo.o: algo.c algo.h graph.h
	$(CC) $(FLAGS) -c algo.c

main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c

.PHONEY: all clean

clean:
	rm -f *.o graph