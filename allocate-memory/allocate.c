//
// Created by Felix Zailskas on 19.06.21.
//

#include "allocate.h"
#include "assert.h"
#include "stdlib.h"

void *safe_malloc(int s, int t) {
  void *p = malloc(s * t);
  assert(p != NULL);
  return p;
}

void *safe_calloc(int s, int t) {
  void *p = calloc(s, t);
  assert(p != NULL);
  return p;
}