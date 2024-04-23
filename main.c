#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int max(int a, int b){
    return a > b ? a : b;
}

long long  findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int r = m.nRows;
    int c = m.nCols;
    int* max_value =(int*)malloc(sizeof(int) * (r + c - 1));
    for (int i = 0; i < r + c - 1; i++) {
        max_value[i] = 0;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i != j) {
                max_value[i - j + c - 1] = max(max_value[i - j + c - 1],m.values[i][j]);
            }
        }
    }
    long long sum = 0;
    for (int i = 0; i < r + c - 1; i++) {
        sum += max_value[i];
    }
    free(max_value);
    return sum;
}

bool valueInArea(position max, int i, int j) {
    position new_position = {i - max.rowIndex, j - max.colIndex};
    return (new_position.rowIndex <= new_position.colIndex) && (new_position.rowIndex <= - new_position.colIndex);
}

int  getMinInArea(matrix m) {
    position max = getMaxValuePos(m);
    int min = INT_MAX;
    for (int i = 0; i <= max.rowIndex; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (valueInArea(max,i,j) && m.values[i][j] < min) {
                min = m.values[i][j];
            }
        }
    }
    return min;
}

float getDistance(int *a, int n) {
    long long square_sum = 0;
    for (int i = 0; i < n; i++) {
        square_sum += a[i] * a[i];
    }
    return sqrt(square_sum);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix* m, float (*criteria)(int*, int)) {
    float res_criteria[m->nRows];
    for (size_t i = 0; i < m->nRows; i++)
        res_criteria[i] = criteria(m->values[i], m->nCols);
    int i, j;
    float key;
    int* address_key;
    for (i = 1; i < m->nRows; i++) {
        key = res_criteria[i];
        address_key = m->values[i];
        j = i - 1;
        while (j >= 0 && res_criteria[j] > key) {
            res_criteria[j + 1] = res_criteria[j];
            swapRows(m, j + 1, j);
            j -= 1;
        }
        res_criteria[j + 1] = key;
        m->values[j + 1] = address_key;
    }
}

void sortByDistance(matrix *m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int cmpLongLong(const void* pa, const void* pb) {
    return (int)(*(long long int*) pa - *(long long int*) pb);
}
int countNUnique(long long int *a, int n) {
    int amount = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1])
            amount++;
    }
    return amount;
}
int countEqClassesByRowsSum(matrix m) {
    long long int values[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        values[i] = getSum(m.values[i], m.nCols);
    qsort(values, m.nRows, sizeof(long long int), cmp_long_long);
    int result = countNUnique(values, m.nRows);
    return result;
}

int getNSpecialElement(matrix m) {
    int amount = 0;
    for (int i = 0; i < m.nCols; i++) {
        int sum = m.values[0][i];
        int max_value = m.values[0][i];
        for (int j = 1; j < m.nRows; j++) {
            sum += m.values[j][i];
            if (m.values[j][i] > max_value) {
                max_value = m.values[j][i];
            }
        }
        if (max_value > (sum - max_value)) {
            amount++;
        }
    }
    return amount;
}

position getLeftMin(matrix m) {
    int min = INT_MAX;
    position min_pos;
    for (int j = 0; j < m.nRows; j++) {
        for (int i = 0; i < m.nCols; i++) {
            if (m.values[j][i] < min) {
                min = m.values[i][0];
                min_pos.rowIndex = j;
                min_pos.colIndex = i;
            }
        }
    }
    return min_pos;
}

void swapPenultimateRow(matrix* m) {
    if (m->nRows != m->nCols) {
        return;
    }
    position min_pos = getLeftMin(*m);
    int* temp = (int*) malloc(sizeof(int) * m->nRows);
    for (int i = 0; i < m->nRows; i++)
        temp[i] = m->values[i][min_pos.colIndex];
    for (int i = 0; i < m->nCols; i++)
        m->values[m->nRows - 2][i] = temp[i];
    free(temp);
}
