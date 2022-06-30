#include <iostream>

/**
 * Напишите функцию, которая принимает на вход целочисленную матрицу M (другими словами, просто двумерный целочисленный массив)
 * размера rows×cols, и возвращает транспонированную матрицу M^T (тоже двумерный целочисленный массив) размера cols×rows.
 * Если в M на пересечении i-ой строки и j-ого столбца стояло число x, то на пересечении  j-ой строки и i-ого столбца в матрице M^T
 * тоже будет стоять число x, или другими словами M^T[j][i] = M[i][j]
 * Обратите внимание, что вам неизвестно, каким именно способом выделялась память для массива M.
 * Выделять память под массив M^T можете любым удобным вам способом. Изменять исходную матрицу нельзя.
 * */
int **transpose(const int *const *m, unsigned rows, unsigned cols) {
    int **matrix = new int *[cols];
    for (int k = 0; k < cols; ++k) matrix[k] = new int[rows];
    for (int i = 0; i != cols; ++i) {
        for (int j = 0; j != rows; ++j) matrix[i][j] = m[j][i];
    }
    return matrix;
}

void print_matrix(const int *const *m, unsigned rows, unsigned cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
}

#define ROW 6
#define COL 5

int main() {
    int filler = 1;
    int **matrix = new int *[ROW];
    for (size_t k = 0; k < ROW; ++k) {
        matrix[k] = new int[COL];
    }
    for (size_t i = 0; i != ROW; ++i) {
        for (size_t j = 0; j != COL; ++j) {
            matrix[i][j] = filler;
            ++filler;
        }
    }
    print_matrix(matrix, ROW, COL);
    std::cout << "\nresult:\n\n";
    int **t_matrix = transpose(matrix, ROW, COL);
    print_matrix(t_matrix, COL, ROW);
    return 0;
}
