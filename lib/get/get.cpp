#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "get.hpp"


using namespace std;

enum errors {
    OK = 0,
    UNDEFINED,
};

bool try_input(int &number) {
    std::cin >> number;
    if (std::cin.eof())
        throw std::runtime_error("EOF");
    if (std::cin.bad())
        throw std::runtime_error("Broken Input");
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        return false;
    }
    return true;
}

int get_int(int min, int max) {
    int res = 0;
    while (!try_input(res) || res < min || res > max);
    return res;
}

char* readline(char* msg) {
    int check = 0, length_buffer = 0, length_string = 0;
    int i = 0;
    char buffer[51] = "";
    char* str = nullptr;
    
    if (msg != nullptr)
        printf("%s", msg);

    do {
        for (int i = 0; i < 51; i++)
            buffer[i] = 0;
        check = scanf("%50s", buffer);
        length_buffer = strlen(buffer);
        str = (char*) realloc(str, (length_string + length_buffer + 1) * sizeof(char));
        for (int i = 0; i < length_buffer + 1; i++)
            str[length_string + i] = buffer[i];
        length_string += length_buffer;
        if (length_buffer < 50 || buffer[49] == 0)
            break;
    } while (check == 1);
    return str;
}
