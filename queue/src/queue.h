//
// Created by Felix Zailskas
//

#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**
 * A queue storing integers.
 */
typedef struct Queue {
    int *array;
    int back;
    int front;
    int size;
} Queue;

/**
 * Returns a pointer to a new queue of a given size.
 * @param s Size of the queue
 * @return Pointer to queue
 */
Queue *new_queue (int s);

/**
 * Checks whether a queue is empty.
 * @param q Pointer to queue.
 * @return 1 if the queue is empty, 0 otherwise.
 */
int is_empty_queue(Queue *q);

/**
 * Prints an error and aborts the program when dequeueing on an empty queue.
 */
void queue_empty_error();

/**
 * Prints an error and aborts the program when initializing a queue with invalid size.
 */
void invalid_size_error();

/**
 * Doubles the size of a queue. This function is called when enqueueing more items
 * than possible given the original size of the queue.
 * @param q Pointer to the queue.
 */
void double_queue_size(Queue *q);

/**
 * Enqueues an item in the queue.
 * @param item Item to enqueue.
 * @param q Pointer to the queue.
 */
void enqueue(int item, Queue *q);

/**
 * Dequeues an item from the queue.
 * @param q Pointer to the queue.
 * @return The dequeued item.
 */
int dequeue(Queue *q);

/**
 * Returns the first item in the queue without dequeueing it.
 * @param q Pointer to the queue.
 * @return First item in the queue.
 */
int peek_queue(Queue *q);

/**
 * Returns the elements currently enqueued.
 * @param q Pointer to the queue.
 * @return Amount of elements in the queue.
 */
int amt_elements(Queue *q);

/**
 * Frees the memory allocated by a queue.
 * @param q Pointer to the queue.
 */
void destroy_queue(Queue *q);

#endif