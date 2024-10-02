#ifndef MATRIX_PRIVATE_H_INCLUDED
#define MATRIX_PRIVATE_H_INCLUDED


typedef struct Line {
    int size;
    int* array;
} Line;

typedef struct Matrix {
    int size;
    Line* lines;
    char* style;
    char* html;
} Matrix;

typedef struct String {
    char* string;
    int size;
} String;

Matrix* matrix_new();
Line* line_array_new(unsigned int size);
int* int_array_new(unsigned int size);
void lines_delete(Line* lines, unsigned int size);
int string_add(String* string, const char* addition);


#endif