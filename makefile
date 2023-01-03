CC = gcc
FLAGS = -Wall -g

all: isort txtfind

txtfind: txtfind.o
	$(CC) $(FLAGS) -o $@ $^

isort: isort.o
	$(CC) $(FLAGS) -o $@ $^

%.o: %.c.
	$(CC) $(FLAGS) -c $@ $<

.PHONEY: all clean

clean:
	rm -f *.o txtfind isort