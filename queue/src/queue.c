//
// Created by Felix Zailskas
//

#include "queue.h"

Queue *new_queue (int s) {
    if (s < 1) {
        invalid_size_error();
    }
    Queue *q = malloc(sizeof(struct Queue));
    assert(q != NULL);
    q->array = malloc(s * sizeof(int));
    assert(q->array != NULL);
    q->back = 0;
    q->front = 0;
    q->size = s;
    return q;
}

int is_empty_queue(Queue *q) {
    return (q->back == q->front);
}

void queue_empty_error() {
    printf("This queue operation is invalid on an empty queue.\n");
    abort();
}

void invalid_size_error() {
    printf("Queue needs to be initialized with a positive size.\n");
    abort();
}

void double_queue_size(Queue *q) {
    int i;
    int oldSize = q->size;
    q->size = 2 * oldSize;
    q->array = realloc(q->array, q->size * sizeof(int));
    assert(q->array != NULL);
    for (i=0; i < q->back ; i++) { /* eliminate the split configuration */
        q->array[oldSize + i] = q->array[i];
    }
    q->back = q->back + oldSize;  /* update q->back */
}

void enqueue(int item, Queue *q) {
    q->array[q->back] = item;
    q->back = (q->back + 1) % q->size;
    if ( q->back == q->front ) {
        double_queue_size(q);
    }
}

int dequeue(Queue *q) {
    int item;
    if (is_empty_queue(q)) {
        queue_empty_error();
    }
    item = q->array[q->front];
    q->front = (q->front + 1) % q->size;
    return item;
}

int peek_queue(Queue *q) {
    int item;
    if (is_empty_queue(q)) {
        queue_empty_error();
    }
    item = q->array[q->front];
    return item;
}

int amt_elements(Queue *q) {
    if (q->front == q->back) return 0;
    if (q->front < q->back) return (q->back - q->front);
    return (q->size - q->front + q->back);
}

void destroy_queue(Queue *q) {
    if (q == NULL) return;
    if (q->array != NULL) free(q->array);
    free(q);
}