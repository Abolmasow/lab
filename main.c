#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void swapMinMaxRows(matrix* m) {
    position max = getMaxValuePos(*m);
    position min = getMinValuePos(*m);
    swapRows(m, max.rowIndex, min.rowIndex);
}

int getMax(int *a, int n) {
    int max = a[0];
    for (size_t i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void sortRowsByMaxElement(matrix *m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

int getMin(int *a, int n) {
    int min = a[0];
    for (size_t i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

void sortColsByMinElement(matrix *m) {
    selectionSortColsMatrixByColCriteria(m, getMin);
}

matrix mulMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows) {
        fprintf(stderr, "It is not a square matrix");
        exit(1);
    }
    matrix res = getMemMatrix(m1.nRows, m2.nRows);
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++) {
            res.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; k++)
                res.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }
    return res;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (!isSymmetricMatrix(m))
        return;

    matrix res = mulMatrices(*m, *m);
    freeMemMatrix(m);
    m->values = res.values;
    m->nRows = res.nRows;
    m->nCols = res.nCols;
}

bool isUnique(long long *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                return false;
            }
        }
    }
    return true;
}

long long getSum(int *a, int n) {
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i];
    }
    return res;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix *m) {
    long long sum[m->nRows];
    for (int i = 0; i < m->nRows; i++) {
        sum[i] = getSum(m->values[i], m->nCols);
    }
    if (isUnique(sum, m->nRows))
        transposeSquareMatrix(m);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix res = mulMatrices(m1, m2);
    bool is_e_m = isEMatrix(&res);
    freeMemMatrix(&res);
    return is_e_m;
}
