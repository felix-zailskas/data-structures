// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2023 Felix Zailskas <felixzailskas@gmail.com>

#ifndef STACK_H
#define STACK_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * A Stack storing Integers.
 * This representation of a stack works with an array. The value of top always
 * points to the next free position in the array of values.
 *
 * For pushing on the stack we store the value on the current free position of
 * the array and increase the top value by one. In the case that the array is
 * full we double the amount of elements we can store. This is done by
 * reallocating the array with twice its size.
 *
 * For popping from the stack we reduce the top value by one and then return the
 * value at the current position of the array. Since the top value now points to
 * the position of the value we have returned it is marked as a free position so
 * the stack does not store the values anymore.
 *
 * For peeking we do the same process as in popping without reducing the value
 * of top. We only return the value stored at one position lower than the top
 * value.
 *
 * The size of the stack can be determined by examining the value of the top
 * variable.
 *
 * The Stack is empty exactly when the top value is 0 (points to the first entry
 * of the array).
 */
typedef struct Stack {
  int *array;
  int top;
  int size;
} Stack;

/**
 * Returns a pointer to a new Stack with a given size.
 * @param s Size of the Stack.
 * @return Pointer to the Stack.
 */
Stack *new_stack(int s);

/**
 * Doubles the size of a given Stack.
 * @param s Pointer to the Stack.
 */
void double_stack_size(Stack *s);

/**
 * Prints an error and aborts the program when popping from an empty Stack.
 */
void stack_empty_error();

/**
 * Prints an error and aborts the program when initializing a Stack with invalid
 * size.
 */
void invalid_size_error();

/**
 * Checks if a given stack is empty.
 * @param s Pointer to the Stack.
 * @return 1 if the Stack is empty, 0 otherwise.
 */
int is_empty_stack(Stack *s);

/**
 * Pushes an element onto the stack.
 * @param value Element to push.
 * @param s Pointer to the Stack onto which to push.
 */
void push(int value, Stack *s);

/**
 * Pops the top element from a given Stack.
 * @param s Pointer to the Stack from which to pop.
 * @return Top element of the Stack.
 */
int pop(Stack *s);

/**
 * Returns the top element of a given stack without removing it from the stack
 * @param s Pointer to the Stack.
 * @return Top element of the Stack.
 */
int peek_stack(Stack *s);

/**
 * Returns the amount of elements stors in a stack.
 * @param s Pointer to the Stack.
 * @return Amount of elements in the Stack.
 */
int amt_elements(Stack *s);

/**
 * Frees the memory allocated by a Stack.
 * @param s Pointer to the Stack.
 */
void destroy_stack(Stack *s);

#endif // DATA_STRUCTURES_STACK_H
