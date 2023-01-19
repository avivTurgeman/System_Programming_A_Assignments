#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

#ifndef Q_H_
#define Q_H_

typedef struct PAIR_ {
    int node_num;
    int dist;
} pair;

typedef struct PRIORITY_QUEUE_{
    pair* array;
    int size;
    int capacity;
} priority_queue;

priority_queue* create_queue(int capacity);
int is_empty(priority_queue* q);
void swap(pair* a, pair* b);
void push(priority_queue* q, int node_num, int dist);
pair* pop(priority_queue* q);
void heapify(priority_queue* q, int i) ;
void free_queue(priority_queue* q);

#endif