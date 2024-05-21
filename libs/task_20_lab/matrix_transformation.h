#ifndef UNTITLED6_MATRIX_TRANSFORMATION_H
#define UNTITLED6_MATRIX_TRANSFORMATION_H
#include <stdio.h>
#include "../data_structures/matrix/matrix.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>

typedef struct coord {
    int row1;
    int col1;
    int row2;
    int col2;
} coord;


void matrix_transformation(const char* filename) {
    FILE* file = fopen(filename, "rb");

    int n;
    fread(&n, sizeof(int), 1, file);

    matrix m = getMemMatrix(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m.values[i][j] = 0;

    coord c;
    while(fread(&c, sizeof(coord), 1, file) == 1)
        for (int i = c.row1; i <= c.row2; i++)
            for (int j = c.col1; j <= c.col2; j++)
                m.values[i][j]++;

    fclose(file);


    file = fopen(filename, "wb");

    fwrite(&n, sizeof(int), 1, file);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fwrite(&m.values[i][j], sizeof(int), 1, file);


    freeMemMatrix(&m);
    fclose(file);
}

void test_matrix_transformation() {
    const char filename[] = "C:\\Users\\zevss\\CLionProjects\\lab\\tasks_tests_20_lab\\task_1_test_1.txt";

    FILE* file = fopen(filename, "wb");

    int n = 3;
    fwrite(&n, sizeof(int), 1, file);

    coord c1 = {1, 1, 2, 2};
    coord c2 = {0, 0, 1, 1};
    fwrite(&c1, sizeof(coord), 1, file);
    fwrite(&c2, sizeof(coord), 1, file);

    fclose(file);

    matrix_transformation(filename);


    file = fopen(filename, "rb");

    fread(&n, sizeof(int), 1, file);

    matrix m = getMemMatrix(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fread(&m.values[i][j], sizeof(int), 1, file);

    matrix check = createMatrixFromArray((int[]) {1, 1, 0,
                                                     1, 2, 1,
                                                     0, 1, 1}, 3, 3);

    assert(n == 3);
    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
    fclose(file);
}

#endif //UNTITLED6_MATRIX_TRANSFORMATION_H
