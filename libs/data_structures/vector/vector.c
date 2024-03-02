#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <stdlib.h>
#include "../../data_structures/vector/vector.h"

vector create_vector(size_t capacity) {
    if (capacity <= UINT64_MAX) {
        return (vector) {malloc(sizeof(int) * capacity), 0, capacity};
    } else {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

