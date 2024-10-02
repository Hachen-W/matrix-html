#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../lib/get/get.h"
#include "../lib/matrix/matrix.h"


enum errors {
    OK = 0,
    UNDEFINED,
    ALLOCATION,
};

const char *msgs[] = {"Input Matrix", "Input Style", "Output Matrix", 
                            "Matrix To HTML", "Output HTML", "Exit"};
const int N = sizeof(msgs) / sizeof(msgs[1]);

typedef int (*func)(Matrix*);
func funcs[] = {&matrix_input, &style_input, &matrix_output, 
                    &matrix_to_html, &html_output};

int dialog(int* option);

int main() {
    int option = 0, check = 0;
    Matrix* matrix = matrix_new();
    if (matrix == NULL) {
        check = ALLOCATION;
        goto error;
    }
    do {
        check = dialog(&option);
        printf("\n\n");
        if (check != 0)
            goto error;
        if (option != N - 1)
            check = (funcs[option])(matrix);
        if (check != 0)
            goto error;
    } while (option != N - 1);
    
  error:
    matrix_delete(matrix);
    return 0;
}
int dialog(int* option) {
    int rc;
    int i, check = 0;
    do {
        for (i = 0; i < N; ++i)
            printf("%d. %s\n", i, msgs[i]);
        printf("Choose Option: ");
        check = get_int(option, 0, N);
        if (check != 0)
            break;
    } while (*option < 0 || *option >= N);
    return check;
}