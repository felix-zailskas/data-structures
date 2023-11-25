// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2023 Felix Zailskas <felixzailskas@gmail.com>

#include "../../testing/testing.h"
#include "../queue.h"

void test_make_queue() {
  int tests = 0;
  printf("Create a queue with no error.\n");
  Queue *q = new_queue(5);
  tests += test(q != NULL);
  printf("Queue should have size 5.\n");
  tests += test(q->size == 5);
  printf("Queue should be empty.\n");
  tests += test(is_empty_queue(q));
  printf("Queue should have 0 elements.\n");
  tests += test(amt_elements(q) == 0);
  destroy_queue(q);
  pass_message(4, tests);
}

void test_enqueue() {
  int tests = 0;
  Queue *q = new_queue(5);

  printf("Queue should be empty.\n");
  tests += test(is_empty_queue(q));
  printf("Queue should have 0 elements.\n");
  tests += test(amt_elements(q) == 0);

  printf("Adding value 5 to queue.\n");
  enqueue(5, q);
  printf("Adding value 4 to queue.\n");
  enqueue(4, q);
  printf("Adding value -7 to queue.\n");
  enqueue(-7, q);

  printf("Queue should have 3 items.\n");
  tests += test(amt_elements(q) == 3);

  printf("Adding value 6 to queue.\n");
  enqueue(6, q);
  printf("Adding value 3 to queue.\n");
  enqueue(3, q);
  printf("Adding value -22 to queue.\n");
  enqueue(-22, q);

  printf("Queue should have 6 items.\n");
  tests += test(amt_elements(q) == 6);

  printf("Queue should not be empty.\n");
  tests += test(!is_empty_queue(q));

  printf("Queue should have size 10.\n");
  tests += test(q->size == 10);
  pass_message(6, tests);
  destroy_queue(q);
}

void test_dequeue() {
  int tests = 0;
  Queue *q = new_queue(5);

  printf("Adding value 5 to queue.\n");
  enqueue(5, q);
  printf("Adding value 4 to queue.\n");
  enqueue(4, q);
  printf("Adding value -7 to queue.\n");
  enqueue(-7, q);

  printf("Queue should have 3 items.\n");
  tests += test(amt_elements(q) == 3);

  printf("Dequeue should give 5.\n");
  tests += test(dequeue(q) == 5);

  printf("Dequeue should give 4.\n");
  tests += test(dequeue(q) == 4);

  printf("Queue should have 1 items.\n");
  tests += test(amt_elements(q) == 1);

  printf("Adding value 6 to queue.\n");
  enqueue(6, q);
  printf("Adding value 3 to queue.\n");
  enqueue(3, q);
  printf("Adding value -22 to queue.\n");
  enqueue(-22, q);
  printf("Adding value -2 to queue.\n");
  enqueue(-2, q);

  printf("Queue should have 5 items.\n");
  tests += test(amt_elements(q) == 5);

  printf("Dequeue should give -7.\n");
  tests += test(dequeue(q) == -7);

  printf("Dequeue should give 6.\n");
  tests += test(dequeue(q) == 6);

  printf("Dequeue should give 3.\n");
  tests += test(dequeue(q) == 3);

  printf("Dequeue should give -22.\n");
  tests += test(dequeue(q) == -22);

  printf("Dequeue should give -2.\n");
  tests += test(dequeue(q) == -2);

  printf("Queue should be empty.\n");
  tests += test(is_empty_queue(q));

  printf("Queue should have no elements.\n");
  tests += test(amt_elements(q) == 0);

  pass_message(12, tests);
  destroy_queue(q);
}

void test_peek() {
  int tests = 0;
  Queue *q = new_queue(5);

  printf("Adding value 5 to queue.\n");
  enqueue(5, q);
  printf("Adding value 4 to queue.\n");
  enqueue(4, q);
  printf("Adding value -7 to queue.\n");
  enqueue(-7, q);

  printf("Peek should give 5.\n");
  tests += test(peek_queue(q) == 5);

  printf("Peek should still give 5.\n");
  tests += test(peek_queue(q) == 5);

  printf("Queue should have 3 elements.\n");
  tests += test(amt_elements(q) == 3);

  printf("Dequeueing 2 elements.\n");
  dequeue(q);
  dequeue(q);

  printf("Peek should still give -7.\n");
  tests += test(peek_queue(q) == -7);

  printf("Queue should have 1 element.\n");
  tests += test(amt_elements(q) == 1);

  pass_message(5, tests);
  destroy_queue(q);
}

int main(int argc, char const *argv[]) {

  printf("Testing creation.\n");
  test_make_queue();

  printf("Testing enqueueing.\n");
  test_enqueue();

  printf("Testing dequeueing.\n");
  test_dequeue();

  printf("Testing peeking.\n");
  test_peek();

  return 0;
}
