// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2023 Felix Zailskas <felixzailskas@gmail.com>

#include "testing.h"

int test(int testing) {
  if (testing) {
    printf("Test Passed.\n");
    return 1;
  }
  printf("Test Failed.\n");
  return 0;
}

void pass_message(int from, int passed) {
  printf("Passed %d/%d cases.\n\n", passed, from);
}
