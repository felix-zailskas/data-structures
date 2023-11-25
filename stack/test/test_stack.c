//
// Created by Felix Zailskas on 25.06.21.
//

#include "../../testing/testing.h"
#include "../stack.h"

void test_make_stack() {
  int tests = 0;
  printf("Create a stack with no error.\n");
  Stack *s = new_stack(5);
  tests += test(s != NULL);
  printf("Stack should have size 5.\n");
  tests += test(s->size == 5);
  printf("Stack should be empty.\n");
  tests += test(is_empty_stack(s));
  printf("Stack should have 0 elements.\n");
  tests += test(amt_elements(s) == 0);
  pass_message(4, tests);
  destroy_stack(s);
}

void test_push() {
  int tests = 0;
  Stack *s = new_stack(5);

  printf("Stack should be empty.\n");
  tests += test(is_empty_stack(s));
  printf("Stack should have 0 elements.\n");
  tests += test(amt_elements(s) == 0);

  printf("Pushing value 4 to stack\n");
  push(4, s);
  printf("Pushing value -2 to stack\n");
  push(-2, s);
  printf("Pushing value 0 to stack\n");
  push(0, s);

  printf("Stack should not be empty.\n");
  tests += test(!is_empty_stack(s));
  printf("Stack should have 3 elements.\n");
  tests += test(amt_elements(s) == 3);

  printf("Pushing value 7 to stack\n");
  push(7, s);
  printf("Pushing value 2 to stack\n");
  push(2, s);
  printf("Pushing value -132 to stack\n");
  push(-132, s);

  printf("Stack should have 6 elements.\n");
  tests += test(amt_elements(s) == 6);
  printf("Stack size should be 10.\n");
  tests += test(s->size == 10);

  pass_message(6, tests);
  destroy_stack(s);
}

void test_pop() {
  int tests = 0;
  Stack *s = new_stack(5);

  printf("Pushing value 5 to stack.\n");
  push(5, s);
  printf("Pushing value 4 to stack.\n");
  push(4, s);
  printf("Pushing value -7 to stack.\n");
  push(-7, s);

  printf("Stack should have 3 items.\n");
  tests += test(amt_elements(s) == 3);

  printf("Pop should give -7.\n");
  tests += test(pop(s) == -7);

  printf("Pop should give 4.\n");
  tests += test(pop(s) == 4);

  printf("Stack should have 1 items.\n");
  tests += test(amt_elements(s) == 1);

  printf("Pushing value 6 to stack.\n");
  push(6, s);
  printf("Pushing value 3 to stack.\n");
  push(3, s);
  printf("Pushing value -22 to stack.\n");
  push(-22, s);
  printf("Pushing value -2 to stack.\n");
  push(-2, s);

  printf("Stack should have 5 items.\n");
  tests += test(amt_elements(s) == 5);

  printf("Pop should give -2.\n");
  tests += test(pop(s) == -2);

  printf("Pop should give -22.\n");
  tests += test(pop(s) == -22);

  printf("Pop should give 3.\n");
  tests += test(pop(s) == 3);

  printf("Pop should give 6.\n");
  tests += test(pop(s) == 6);

  printf("Pop should give 5.\n");
  tests += test(pop(s) == 5);

  printf("Stack should be empty.\n");
  tests += test(is_empty_stack(s));

  printf("Stack should have no elements.\n");
  tests += test(amt_elements(s) == 0);

  pass_message(12, tests);
  destroy_stack(s);
}

void test_peek() {
  int tests = 0;
  Stack *s = new_stack(5);

  printf("Pushing value 5 to stack.\n");
  push(5, s);
  printf("Pushing value 4 to stack.\n");
  push(4, s);
  printf("Pushing value -7 to stack.\n");
  push(-7, s);

  printf("Stack should have 3 items.\n");
  tests += test(amt_elements(s) == 3);

  printf("Peek should give -7.\n");
  tests += test(peek_stack(s) == -7);

  printf("Peek should still give -7.\n");
  tests += test(peek_stack(s) == -7);

  printf("Stack should have 3 items.\n");
  tests += test(amt_elements(s) == 3);

  printf("Popping 2 elements.\n");
  pop(s);
  pop(s);

  printf("Peek should still give 5.\n");
  tests += test(peek_stack(s) == 5);

  printf("Stack should have 1 element.\n");
  tests += test(amt_elements(s) == 1);

  pass_message(6, tests);
  destroy_stack(s);
}

int main(int argc, char const *argv[]) {

  printf("Testing creation.\n");
  test_make_stack();

  printf("Testing pushing.\n");
  test_push();

  printf("Testing popping.\n");
  test_pop();

  printf("Testing peeking.\n");
  test_peek();

  return 0;
}
