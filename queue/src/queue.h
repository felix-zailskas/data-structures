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
 * This representation of a queue uses an array. There is one value pointing
 * to the front of the queue and one pointing to the back.
 *
 * To enqueue a value in the queue we store the value at the position in the
 * array to which the back variable points. This variable must always point
 * to the back of the queue. This means that if the array is completely filled
 * after enqueuing the new value we must double the queue size. For this the
 * data array is reallocated and the values are shifted so that front and back
 * pointers are still valid.
 *
 * To dequeue a value from the queue we return the value stored in the data
 * array at the position of the front pointer. Afterwards we increase the front
 * pointer by one to indicate that one position in the data array has cleared.
 *
 * For peeking we just return the value at the front of the queue without changing
 * the front pointer of the queue.
 *
 * Any edit of the front and back pointers must be accompanied by a modulo
 * operation with the size of the data array. This increases space efficiency
 * since we can fill up the queue from the front again when there is space.
 * This means that the value of the front can be both smaller and larger than
 * the one for the back.
 *
 * We can determine the amount of elements in the queue by examining the difference
 * between the front and back value.
 *
 * The queue is empty exactly when the front and back values are equal.
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