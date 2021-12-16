//
// Created by Felix Zailskas on 25.06.21.
//

#include "stack.h"

Stack *new_stack(int s) {
    if (s < 1) invalid_size_error();
    Stack *st = malloc(sizeof(Stack));
    assert(st != NULL);
    st->size = s;
    st->top = 0;
    st->array = malloc(s * sizeof(int));
    assert(st->array != NULL);
    return st;
}

void double_stack_size(Stack *s) {
    int new_size = s->size * 2;
    s->array = realloc(s->array, new_size);
    assert(s->array != NULL);
    s->size = new_size;
}

void stack_empty_error() {
    printf("This stack operation is invalid on an empty stack.\n");
    abort();
}

void invalid_size_error() {
    printf("Stack needs to be initialized with a size larger than 0.\n");
    abort();
}

int is_empty_stack(Stack *s) {
    return s->top == 0;
}

void push(int value, Stack *s) {
    if (s->top == s->size) double_stack_size(s);
    s->array[s->top++] = value;
}

int pop(Stack *s) {
    if (is_empty_stack(s)) stack_empty_error();
    return s->array[--s->top];
}

int peek_stack(Stack *s) {
    if (is_empty_stack(s)) stack_empty_error();
    return s->array[s->top - 1];
}

int amt_elements(Stack *s) {
    return s->top;
}

void destroy_stack(Stack *s) {
    if (s == NULL) return;
    if (s->array != NULL) free(s->array);
    free(s);
}