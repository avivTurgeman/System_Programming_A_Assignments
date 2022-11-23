CC = gcc
AR = ar
OBJECTS_MAIN = main.o
OBJECTS_BASIC = basicClassification.o
OBJECTS_LOOP = advancedClassificationLoop.o
OBJECTS_RECURSION = advancedClassificationRecursion.o
FLAGS = -Wall -g

all: libclassloops.a libclassrec.a libclassrec.so libclassloops.so loops recursives recursived loopd mains maindloop maindrec

loops: $(OBJECTS_BASIC) $(OBJECTS_MAIN) libclassloops.a
	$(CC) $(FLAGS) -o loops $(OBJECTS_BASIC)  $(OBJECTS_MAIN) libclassloops.a -lm

recursives:  $(OBJECTS_BASIC) $(OBJECTS_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o recursives $(OBJECTS_BASIC) $(OBJECTS_MAIN) libclassrec.a -lm

loopd: $(OBJECTS_LOOP) $(OBJECTS_BASIC) $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o loopd $(OBJECTS_LOOP) $(OBJECTS_BASIC) $(OBJECTS_MAIN) ./libclassloops.so -lm

recursived: $(OBJECTS_RECURSION) $(OBJECTS_BASIC) $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o recursived $(OBJECTS_RECURSION) $(OBJECTS_BASIC) $(OBJECTS_MAIN) ./libclassrec.so -lm

libclassloops.a: $(OBJECTS_LOOP)
	$(AR) -rcs libclassloops.a $(OBJECTS_LOOP) -lm

libclassrec.a: $(OBJECTS_RECURSION)
	$(AR) -rcs libclassrec.a $(OBJECTS_RECURSION) -lm

libclassloops.so: $(OBJECTS_LOOP)
	$(AR) -rcs libclassloops.so $(OBJECTS_LOOP) -lm

libclassrec.so: $(OBJECTS_RECURSION)
	$(AR) -rcs libclassrec.so $(OBJECTS_RECURSION) -lm

mains: loops recursives
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) $(OBJECTS_BASIC) $(OBJECTS_RECURSION) -lm

maindloop: loopd
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) $(OBJECTS_BASIC) $(OBJECTS_LOOP) -lm

maindrec: recursived
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) $(OBJECTS_BASIC) $(OBJECTS_RECURSION) -lm

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c -fPIC basicClassification.c -lm

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c -fPIC advancedClassificationLoop.c -lm

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c -fPIC advancedClassificationRecursion.c -lm 

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c -lm

.PHONY: clean all

clean:
	rm -f *.o *.a *.so loops recursives recursived loopd mains maindloop maindrec

