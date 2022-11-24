CC = gcc
AR = ar
OBJECTS_MAIN = main.o
OBJECTS_BASIC = basicClassification.o
OBJECTS_LOOP = advancedClassificationLoop.o
OBJECTS_RECURSION = advancedClassificationRecursion.o
FLAGS = -Wall -g
LIB = NumClass.h
MAIN_BASIC_REC = main.o basicClassification.o advancedClassificationRecursion.o
MAIN_BASIC_LOOP = main.o basicClassification.o advancedClassificationLoop.o


all: libclassloops.a libclassrec.a libclassrec.so libclassloops.so loops recursives recursived loopd mains maindloop maindrec

loops: $(OBJECTS_BASIC) $(OBJECTS_MAIN) libclassloops.a
	$(CC) $(FLAGS) -o $@ $^ -lm

recursives:  $(OBJECTS_BASIC) $(OBJECTS_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o $@ $^ -lm

loopd: $(MAIN_BASIC_LOOP)
	$(CC) $(FLAGS) -o $@ $^ ./libclassloops.so -lm

recursived: $(MAIN_BASIC_REC)
	$(CC) $(FLAGS) -o $@ $^ ./libclassrec.so -lm

libclassloops.a: $(OBJECTS_LOOP)
	$(AR) -rcs $@ $^ -lm

libclassrec.a: $(OBJECTS_RECURSION)
	$(AR) -rcs $@ $^ -lm

libclassloops.so: $(OBJECTS_LOOP)
	$(CC) -shared -o $@ $^ -lm

libclassrec.so: $(OBJECTS_RECURSION)
	$(CC) -shared -o $@ $^ -lm

mains: loops recursives
	$(CC) $(FLAGS) -o $@ $(MAIN_BASIC_REC) -lm

maindloop: loopd
	$(CC) $(FLAGS) -o $@ $(MAIN_BASIC_LOOP) -lm

maindrec: recursived
	$(CC) $(FLAGS) -o $@ $(MAIN_BASIC_REC) -lm

%.o: %.c $(LIB).
	$(CC) -c $@ $< $(FLAGS)

.PHONY: clean all

clean:
	rm -f *.o *.a *.so loops recursives recursived loopd mains maindloop maindrec

