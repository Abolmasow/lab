#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <stdlib.h>
#include <memory.h>
#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);

    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);

    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);

    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);

    free(m->values);
    m->values = NULL;
    m->nRows = 0;
    m->nCols = 0;
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        freeMemMatrix(ms + i);
    }

    free(ms->values);
    ms->values = NULL;
    ms->nRows = 0;
    ms->nCols = 0;
}

void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        printf("input %d row:", i + 1);
        for (int j = 0; j < m->nCols; j++) {
            scanf("%d", &m->values[i][j]);
        }
    }
}

void inputMatrices(matrix *ms, int n_matrices) {
    for (int i = 0; i < n_matrices; i++) {
        printf("input %lld matrix\n", i + 1);
        inputMatrix(ms + i);
        printf("\n");
    }
}

void outputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            printf("%d ", m->values[i][j]);
        }

        printf("\n");
    }
    printf("\n");
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms + i);
    }
}

void swapRows(matrix *m, int i1, int i2) {
    int *temp = m->values[i1];
    m->values[i1] = m->values[i2];
    m->values[i2] = temp;
}

void swapColumns(matrix *m, int j1, int j2) {
    for (int i = 0; i < m->nRows; i++) {
        int temp = *(&m->values[i][j1]);
        *(&m->values[i][j1]) = *(&m->values[i][j2]);
        *(&m->values[i][j2]) = temp;
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix *m, int (*criteria)(int*, int)) {
    int res_criteria[m->nRows];

    for(int i = 0; i < m->nRows; i++)
        res_criteria[i] = criteria(m->values[i], m->nCols);

    for (int i = 1; i < m->nRows; i++) {
        int key = res_criteria[i];
        int *address_key = m->values[i];
        int j = i - 1;

        while (j >= 0 && res_criteria[j] > key) {
            res_criteria[j + 1] = res_criteria[j];
            swapRows(m, j + 1, j);

            j -= 1;
        }

        res_criteria[j + 1] = key;
        m->values[j + 1] = address_key;
    }
}

void selectionSortColsMatrixByColCriteria(matrix *m, int (*criteria)(int*, int)) {
    int res_criteria[m->nCols];

    for (size_t i = 0; i < m->nCols; i++) {
        int temp[m->nRows];
        for (size_t j = 0; j < m->nRows; j++)
            temp[j] = m->values[j][i];

        res_criteria[i] = criteria(temp, m->nRows);
    }

    int value_min_idx;
    for (int i = 0; i < m->nCols; i++) {
        value_min_idx = i;

        for (int j = i + 1; j < m->nCols; j++)
            if (res_criteria[j] < res_criteria[value_min_idx])
                value_min_idx = j;

        int temp = *(&res_criteria[value_min_idx]);
        *(&res_criteria[value_min_idx]) = *(&res_criteria[i]);
        *(&res_criteria[i]) = temp;

        swapColumns(m, value_min_idx, i);
    }
}