#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED


#include <string>
#include <vector>

using namespace std;

typedef struct Line Line;

typedef struct Matrix Matrix;
Matrix* matrix_new();
void matrix_input(Matrix &matrix, const unsigned int &size);
void matrix_output(const Matrix& matrix);
void matrix_delete(Matrix *matrix);
void style_input(Matrix &matrix, const string &str);
void lines_delete(Line* lines, unsigned int size);

void array_delete(int** array, size_t size);
int** matrix_get_array(Matrix &matrix);
size_t matrix_get_clines(Matrix &matrix);
size_t matrix_get_ccolumn(Matrix &matrix, unsigned int line);
string matrix_get_style(Matrix &matrix);
char* matrix_get_cstyle(Matrix &matrix);
std::vector<std::vector<int>> matrix_get_vector(Matrix &matrix);


#endif