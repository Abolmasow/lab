#ifndef UNTITLED6_BIN_TREE_H
#define UNTITLED6_BIN_TREE_H

#include <stdio.h>
#include "../data_structures/vector/vector.h"

void print_vector(vector* v) {
    for (int i = 0; i < v->size; i++)
        printf("%d ", getVectorValue(*v, i));
    printf("\n");
}

int get_max_vector(vector* v) {
    if (v->size == 0)
        return (int) -1e4;

    int max = getVectorValue(v, 0);
    for (int i = 1; i < v->size; i++) {
        int x = getVectorValue(v, i);
        if (max < x)
            max = x;
    }

    return max;
}

int get_index_vector(vector* v, int x) {
    int i = -1;
    for (int j = 0; j < v->size; j++)
        if (getVectorValue(v, j) == x)
            i = j;
    return i;
}

void _generate_tree(vector* nums, vector* result) {
    if (nums->size == 0) {
        pushBack(result, -1);
        return;
    } else if (nums->size == 1) {
        int x = getVectorValue(nums, 0);
        pushBack(result, x);
        return;
    }

    int mx = get_max_vector(nums);
    int ind = get_index_vector(nums, mx);
    pushBack(result, mx);

    vector left = create_vector(ind + 1);
    for (int i = 0; i < ind; i++)
        pushBack(&left, getVectorValue(nums, i));

    vector right = create_vector(nums->size - ind + 1);
    for (int i = ind + 1; i < nums->size; i++)
        pushBack(&right, getVectorValue(nums, i));

    _generate_tree(&left, result);
    _generate_tree(&right, result);

    deleteVector(&left);
    deleteVector(&right);
}

vector generate_tree(vector* v) {
    vector result = create_vector(32);
    _generate_tree(v, &result);

    return result;
}

void test_generate_tree() {
    vector v = create_vector(12);
    pushBack(&v, 3);
    pushBack(&v, 2);
    pushBack(&v, 1);
    pushBack(&v, 6);
    pushBack(&v, 0);
    pushBack(&v, 5);

    v = generate_tree(&v);

    assert(getVectorValue(&v, 0) == 6);
    assert(getVectorValue(&v, 1) == 3);
    assert(getVectorValue(&v, 2) == -1);
    assert(getVectorValue(&v, 3) == 2);
    assert(getVectorValue(&v, 4) == -1);
    assert(getVectorValue(&v, 5) == 1);
    assert(getVectorValue(&v, 6) == 5);
    assert(getVectorValue(&v, 7) == 0);
    assert(getVectorValue(&v, 8) == -1);

    deleteVector(&v);
}

#endif //UNTITLED6_BIN_TREE_H
