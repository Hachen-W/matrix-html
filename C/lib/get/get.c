#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get.h"


enum errors {
    OK = 0,
    UNDEFINED,
};

int get_int(int* number, int min, int max) {
    if (number == NULL)
        return UNDEFINED;
    int check = 0;
    do {
        check = scanf("%d", number);
        if (check == 0) {
            printf("Incorrect input!\n");
            scanf("%*[^\n]");
        }
        if (check == -1) {
            scanf("%*[^\n]");
            return -1;
        }
    } while (check != 1 || *number < min || *number > max);
    return OK;
}

char* readline(char* msg) {
    int check = 0, length_buffer = 0, length_string = 0;
    int i = 0;
    char buffer[51] = "";
    char* string = NULL;
    
    if (msg != NULL)
        printf("%s", msg);

    do {
        for (int i = 0; i < 51; i++)
            buffer[i] = 0;
        check = scanf("%50s", buffer);
        length_buffer = strlen(buffer);
        string = realloc(string, (length_string + length_buffer + 1) * sizeof(char));
        for (int i = 0; i < length_buffer + 1; i++)
            string[length_string + i] = buffer[i];
        length_string += length_buffer;
        if (length_buffer < 50 || buffer[49] == 0)
            break;
    } while (check == 1);
    return string;
}
