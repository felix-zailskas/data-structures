//
// Created by Felix Zailskas on 25.06.21.
//

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