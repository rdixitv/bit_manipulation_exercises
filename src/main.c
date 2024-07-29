#include <stdio.h>
#include <stdlib.h>

#include "exercises.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Expected 1 argument.");
    }

    void (*runFunctions[])() = {runHammingSort};
    int ch = atoi(argv[1]);

    runFunctions[ch - 1]();

    return 0;
}
