#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "matrix.hpp"
#include "headers/matrix_private.hpp"
#include "../get/get.hpp"


using namespace std;

enum errors {
    OK = 0,
    UNDEFINED,
    ALLOCATION,
    LOGICAL,
};

/**
 * @brief func to create a matrix with empty fields
 * 
 * @return Matrix* - new matrix
 */
Matrix* matrix_new() {
    Matrix* matrix = new Matrix;
    matrix->size = 0;
    matrix->lines = nullptr;
    matrix->style = "";
    matrix->html = "";
    return matrix;
}
Line* line_array_new(unsigned int size) {
    return new Line[size];
}
int* int_array_new(unsigned int size) {
    return new int[size];
}

/**
 * @brief func to input matrix from console
 * 
 * @param matrix - previously generated matrix
 * @param size - required quantity of lines
 */
void matrix_input(Matrix &matrix, const unsigned int &size) {
    if (size < 0)
        throw std::logic_error("Incorrect Argument");
    else
        matrix.size = 0;

    int temp = 0;

    try {
        matrix.lines = line_array_new(size);
        for (int i = 0; i < size; i++) {
            printf("Input %d line's size\n", i);
            temp = get_int();
            (matrix.lines)[i].size = temp;
            (matrix.lines)[i].array = int_array_new((matrix.lines)[i].size);
            matrix.size += 1;
        }

        for (int i = 0; i < matrix.size; i++) {
            for (int j = 0; j < (matrix.lines)[i].size; j++) {
                printf("Input matr[%d][%d] = ", i, j);
                temp = get_int();
                (matrix.lines)[i].array[j] = temp;
            }
        }
    } catch (const std::exception &e) {
        cout << e.what() << endl;
        lines_delete(matrix.lines, matrix.size);
        matrix.lines = nullptr;
        throw;
    }
}

/**
 * @brief func to output your matrix
 * 
 * @param matrix - previously generated matrix
 */
void matrix_output(const Matrix &matrix) {
    if (matrix.lines == nullptr)
        throw std::logic_error("Incorrect Argument");
    cout << "~YOUR MATRIX~" << endl;
    if (!matrix.style.empty())
       cout << "Style: " << matrix.style << endl;
    for (int i = 0; i < matrix.size; i++) {
        if (matrix.lines[i].array != nullptr)
            for (int j = 0; j < matrix.lines[i].size; j++)
                printf("%d\t", matrix.lines[i].array[j]);
        cout << "\n";
    }
    cout << "~~~~~~~~~~~~~" << endl;
}

void style_input(Matrix &matrix, const string &str) {
    matrix.style.clear();
    matrix.style = str;
}

/**
 * @brief func to delete your matrix
 * 
 * @param matrix - previously generated matrix
 */
void matrix_delete(Matrix* matrix) {
    if (matrix == nullptr)
        return;
    if (!((*matrix).style.empty()))
        (*matrix).style.clear();
    if (!((*matrix).style.empty()))
        (*matrix).html.clear();
    if ((*matrix).lines != nullptr)
        lines_delete((*matrix).lines, (*matrix).size);
    delete matrix;
}

/**
 * @brief func to delete lines in matrix
 * 
 * @param lines - pointer to lines in your matrix
 * @param size - count of lines in your matrix
 */
void lines_delete(Line* lines, unsigned int size) {
    if (lines != nullptr)
        for (int i = 0; i < size; i++)
            if (lines[i].array != nullptr)
                delete [] lines[i].array;
    delete [] lines;
}

/**
 * @brief func to generated matrix in new type
 * 
 * @param matrix 
 * @return std::vector<std::vector<int>> - vector of vector of int with your matrix in new type
 */
std::vector<std::vector<int>> matrix_get_vector(Matrix &matrix) {
    std::vector<std::vector<int>> array;
    std::vector<int> array_sub;
    for (int i = 0; i < matrix.size; i++) {
        array_sub.clear();
        for (int j = 0; j < matrix.lines[i].size; j++)
            array_sub.insert(array_sub.end(), matrix.lines[i].array[j]);
        array.insert(array.end(), array_sub);
    }
    return array;
}

/**
 * @brief func to generated matrix in new type
 * 
 * @param matrix - previously generated matrix
 * @return int** - array of array of int with your matrix in new type
 */
int** matrix_get_array(Matrix &matrix) {
    int **array = new int*[matrix.size];
    for (int i = 0; i < matrix.size; i++) {
        try {
            int *array_sub = new int[matrix.lines[i].size];
            for (int j = 0; j < matrix.lines[i].size; j++)
                array_sub[j] = matrix.lines[i].array[j];
            array[i] = array_sub;
        } catch (const std::exception &e) {
            cout << e.what() << endl;
            array_delete(array, matrix.size);
        }
    }
    return array;
}

void array_delete(int** array, size_t size) {
    for (int i = 0; i < size; i++)
        delete [] array[i];
    delete [] array;
}

size_t matrix_get_clines(Matrix &matrix) {
    return matrix.size;
}

size_t matrix_get_ccolumn(Matrix &matrix, unsigned int line) {
    if (matrix.size == 0)
        return 0;
    return matrix.lines[line].size;
}

char* matrix_get_cstyle(Matrix &matrix) {
    char* style = new char[matrix.style.size() + 1];
    for (int i = 0; i < matrix.style.size() + 1; i++)
        style[i] = matrix.style[i];
    return style;
}

string matrix_get_style(Matrix &matrix) {
    return matrix.style;
}