//
// Created by Felix Zailskas on 19.06.21.
//

#include "stdlib.h"
#include "assert.h"
#include "allocate.h"

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