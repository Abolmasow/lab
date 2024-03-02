#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <stdlib.h>
#include "../../data_structures/vectorVoid//vectorVoid.h"

vectorVoid createVectorVoid(size_t capacity, size_t base_type_size) {
    if (capacity <= UINT64_MAX) {
        return (vectorVoid) {malloc(base_type_size * capacity), 0, capacity, base_type_size};
    } else {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void reserveV(vectorVoid *v, size_t new_capacity) {
    if (new_capacity > 0) {

        int *new_data = realloc(v->data, new_capacity * new_capacity * v->base_type_size);
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
        deleteVectorV(v);
    }
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void vectorShrinkToFitV(vectorVoid *v) {
    if (v->size != v->capacity) {
        v->data = (void *) realloc(v->data, v->size * v->base_type_size);
        v->capacity = v->size;
    }
}