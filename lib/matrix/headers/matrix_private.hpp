#ifndef MATRIX_PRIVATE_H_INCLUDED
#define MATRIX_PRIVATE_H_INCLUDED


#include <vector>

using namespace std;

typedef struct Line {
    int size;
    int* array;
} Line;

typedef struct Matrix {
    int size;
    Line* lines;
    string style;
    string html;
} Matrix;


#endif