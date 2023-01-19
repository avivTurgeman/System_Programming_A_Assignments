#include "queue.h"

priority_queue* create_queue(int capacity) {
    priority_queue* q = (priority_queue*) malloc(sizeof(priority_queue));
    q->array = (pair*) malloc(capacity * sizeof(pair));
    q->capacity = capacity;
    q->size = 0;
    return q;
}

int is_empty(priority_queue* q) {
    return q->size == 0;
}

void swap(pair* a, pair* b) {
    pair temp = *a;
    *a = *b;
    *b = temp;
}

void push(priority_queue* q, int node_num, int dist) {
    if (q->size == q->capacity) {
        return;
    }

    pair p = { node_num, dist };
    q->array[q->size] = p;
    int i = q->size;
    q->size++;

    while (i != 0 && q->array[i].dist < q->array[(i - 1) / 2].dist) {
        swap(&q->array[i], &q->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

pair* pop(priority_queue* q) {
    if (is_empty(q)) {
        return NULL;
    }
    pair* root = &q->array[0];
    q->array[0] = q->array[q->size - 1];
    q->size--;
    heapify(q, 0);
    return root;
}

void heapify(priority_queue* q, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < q->size && q->array[left].dist < q->array[smallest].dist) {
        smallest = left;
    }

    if (right < q->size && q->array[right].dist < q->array[smallest].dist) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&q->array[i], &q->array[smallest]);
        heapify(q, smallest);
    }
}

void free_queue(priority_queue* q) {
    free(q->array);
    free(q);
}