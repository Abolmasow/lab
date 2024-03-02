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

void reserve(vector *v, size_t new_capacity) {
    if (new_capacity > 0) {
        int *new_data = realloc(v->data, new_capacity * sizeof(int));
        if (new_data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        v->data = new_data;
        v->capacity = new_capacity;
        if (new_capacity < v->size) {
            v->size = new_capacity;
        }
    } else {
        delete_vector(v);
    }
}
