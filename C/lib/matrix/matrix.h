#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED


typedef struct Matrix Matrix;
Matrix* matrix_new();
int matrix_input(Matrix* matrix);
int matrix_output(Matrix* matrix);
void matrix_delete(Matrix* matrix);
int style_input(Matrix* matrix);
int matrix_to_html(Matrix* matrix);
int html_output(Matrix* matrix);


#endif