#ifndef UNTITLED6_MATRIX_H
#define UNTITLED6_MATRIX_H

#include <stdbool.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

// размещает в динамической памяти матрицу размером n_rows на n_cols. Возвращает матрицу.
matrix getMemMatrix(int n_rows, int n_cols);

// размещает в динамической памяти массив из n_matrices матриц размером n_rows на n_cols.
// Возвращает указатель на нулевую матрицу.
matrix *getMemArrayOfMatrices(int n_matrices, int n_rows, int n_cols);

// освобождает память, выделенную под хранение матрицы m.
void freeMemMatrix(matrix *m);

// освобождает память, выделенную под хранение массива ms из n_matrices матриц.
void freeMemMatrices(matrix *ms, int n_matrices);

#endif //UNTITLED6_MATRIX_H
