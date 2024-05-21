#ifndef UNTITLED6_REARRANGE_STRING_H
#define UNTITLED6_REARRANGE_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../string/string_.h"

void _rearrange_string(const char* s, char* res, const int a[], const int n) {
    for (int i = 0; i < n; i++)
        res[i] = s[a[i]];
}

void rearrange_string(const char* filename) {
    FILE* file = fopen(filename, "r");

    char s[1024] = "";
    fscanf(file, "%s", s);

    size_t len = strlen_(s);
    int* numbers = (int *) malloc(len * sizeof(int));

    for (int i = 0; i < len; i++)
        fscanf(file, "%d", numbers + i);

    fclose(file);


    char res[1024] = "";
    _rearrange_string(s, res, numbers, len);


    file = fopen(filename, "w");

    fprintf(file, "%s", res);

    fclose(file);

    free(numbers);
}

void test_rearrange_string() {
    const char filename[] = "C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests_20_lab\\task_8_test.txt";

    FILE* file = fopen(filename, "w");

    fprintf(file, "abap\n");
    fprintf(file, "0 3 2 1");

    fclose(file);

    rearrange_string(filename);

    file = fopen(filename, "r");

    char res[100] = "";
    fscanf(file, "%s", res);

    fclose(file);

    assert(strcmp_(res, "apab") == 0);
}

#endif //UNTITLED6_REARRANGE_STRING_H
