CC = gcc
FLAGS = -Wall -g


all: graph

%.o: %.c.
	$(CC) $(FLAGS) -c $@ $<

graph: %.o.
	$(CC) $(FLAGS) -o $@ $^

.PHONEY: all clean

clean: rm -f *.o graph