#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "headers/matrix_private.h"
#include "../get/get.h"


enum errors {
    OK = 0,
    UNDEFINED,
    ALLOCATION,
};

Matrix* matrix_new() {
    return (Matrix*) calloc(1, sizeof(Matrix));
}
Line* line_array_new(unsigned int size) {
    return (Line*) calloc(size, sizeof(Line));
}
int* int_array_new(unsigned int size) {
    return (int*) calloc(size, sizeof(int));
}

int matrix_input(Matrix* matrix) {
    if (matrix == NULL)
        return UNDEFINED;

    int check = 0;
    int temp = 0;

    printf("Input matrix's size\n");
    check = get_int(&(matrix->size), 1, INT_MAX);
    if (check != OK)
        return check;

    matrix->lines = line_array_new(matrix->size);
    if (matrix->lines == NULL) {
        check = ALLOCATION;
        goto error;
    }

    for (int i = 0; i < matrix->size; i++) {
        printf("Input %d line's size\n", i);
        check = get_int(&temp, INT_MIN, INT_MAX);
        if (check != 0)
            goto error;
        (matrix->lines)[i].size = temp;
        (matrix->lines)[i].array = int_array_new((matrix->lines)[i].size);
        if ((matrix->lines)[i].array == NULL) {
            check = ALLOCATION;
            goto error;
        }
        for (int j = 0; j < (matrix->lines)[i].size; j++) {
            printf("Input matr[%d][%d] = ", i, j);
            check = get_int(&temp, INT_MIN, INT_MAX);
            if (check != 0)
                goto error;
            (matrix->lines)[i].array[j] = temp;
        }
    }

  error:
    if (check != 0) {
        lines_delete(matrix->lines, matrix->size);
        matrix->lines = NULL;
    }
    return check;
}

int matrix_output(Matrix* matrix) {
    if (matrix == NULL || matrix->lines == 0)
        return UNDEFINED;
    printf("~YOUR MATRIX~\n");
    if (matrix->style != NULL)
        printf("Style: %s\n", matrix->style);
    for (int i = 0; i < matrix->size; i++) {
        if (matrix->lines[i].array != NULL)
            for (int j = 0; j < matrix->lines[i].size; j++)
                printf("%d\t", matrix->lines[i].array[j]);
        printf("\n");
    }
    printf("~~~~~~~~~~~~~\n");
    return OK;
}

int style_input(Matrix* matrix) {
    if (matrix == NULL)
        return UNDEFINED;
    free(matrix->style);
    matrix->style = readline("Input Style\n");
    if (matrix->style == NULL)
        return ALLOCATION;
    return OK;
}

int matrix_to_html(Matrix* matrix) {
    if (matrix == NULL)
        return UNDEFINED;
    int check = 0;
    String html = {NULL, 1};
    string_add(&html, "<!DOCTYPE html>\n");
    string_add(&html, "<html>\n");
    string_add(&html, "<head>\n");
    string_add(&html, "<style>\n");
    if (matrix->style != NULL) {
        string_add(&html, matrix->style);
        string_add(&html, "\n");
    }
    string_add(&html, "table, th, td {\n");
    string_add(&html, "\tborder:1px solid black;\n");
    string_add(&html, "}\n");
    string_add(&html, "</style>\n");
    string_add(&html, "</head>\n");
    string_add(&html, "<body>\n");
    string_add(&html, "\n");
    string_add(&html, "<table>\n");
    for (int i = 0; i < matrix->size; i++) {
        if (matrix->lines[i].array != NULL) {
            string_add(&html, "\t<tr>\n");
            for (int j = 0; j < matrix->lines[i].size; j++) {
                char str[11];
                snprintf(str, sizeof str, "%d", matrix->lines[i].array[j]);
                string_add(&html, "\t\t<td>");
                string_add(&html, str);
                string_add(&html, "</th>\n");
            }
            string_add(&html, "\t</tr>\n");
        }
    }
    string_add(&html, "</table>\n");
    string_add(&html, "\n");
    string_add(&html, "</body>\n");
    string_add(&html, "</html>\n");
    matrix->html = html.string;
    return check;
}

int html_output(Matrix* matrix) {
    if (matrix == NULL || matrix->html == NULL)
        return UNDEFINED;
    printf("%s\n", matrix->html);
    return OK;
}

int string_add(String* string, const char* addition) {
    if (string == NULL || addition == NULL)
        return UNDEFINED;
    
    int addition_length = strlen(addition);
    string->string = (char*) realloc(string->string, (string->size + addition_length) * sizeof(char));
    
    for (int i = 0; i < addition_length; i++)
        string->string[string->size + i - 1] = addition[i];
    string->size += addition_length;
    string->string[string->size - 1] = '\0';
    return OK;
}

int html_to_matrix(Matrix* matrix) {

}

void matrix_delete(Matrix* matrix) {
    if (matrix != NULL) {
        free(matrix->style);
        free(matrix->html);
        lines_delete(matrix->lines, matrix->size);
    }
    free(matrix);
}

void lines_delete(Line* lines, unsigned int size) {
    if (lines != NULL)
        for (int i = 0; i < size; i++)
            free(lines[i].array);
    free(lines);
}