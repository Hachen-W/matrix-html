#include <iostream>
#include <string>
#include "../lib/get/get.hpp"
#include "../lib/matrix/matrix.hpp"
#include "../lib/html/html.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace std;

/**
 * @brief types of errors in current file<br>
 * OK - func work well
 * ALLOCATION - func can't work with memory
 * INPUT - incorrect input
 * UNDEFINED - undefined error
 */
enum errors {
    OK = 0,
    ALLOCATION,
    INPUT,
    UNDEFINED,
};

const char *msgs[] = {"Input Matrix", "Input Style", "Output Matrix", 
                            "Matrix To HTML", "Exit"};                  ///< array of menu's msgs
const int N = sizeof(msgs) / sizeof(msgs[1]);                           ///< size of array above

int dialog();

/**
 * @brief func for manual testing
 * 
 * @return int 
 */

int main() {
    Matrix* matrix = nullptr;
    int size;
    string style;
    int** array;
    char* cstyle;

    try {
        matrix = matrix_new();
        bool While = true;
        int option = 0;
        while (While) {
            switch (option = dialog()) {
                case 0:
                    std::cout << "Input Matrix's Size" << std::endl;
                    size = get_int();
                    matrix_input(*matrix, size);
                    break;
                case 1:
                    std::cin.ignore();
                    std::getline(std::cin, style);
                    style_input(*matrix, style);
                    break;
                case 2:
                    matrix_output(*matrix);
                    break;
                case 3:
                    array = matrix_get_array(*matrix);
                    cstyle = matrix_get_cstyle(*matrix);
                    std::cout << "~Type 1~" << std::endl;
                    cout << matrix_to_html((const int**) array, matrix_get_clines(*matrix), matrix_get_ccolumn(*matrix, 0));
                    std::cout << "~Type 2~" << std::endl;
                    cout << matrix_to_html((const int**) array, matrix_get_clines(*matrix), matrix_get_ccolumn(*matrix, 0), cstyle);
                    array_delete(array, matrix_get_clines(*matrix));
                    delete [] cstyle;
                    std::cout << "~Type 3~" << std::endl;
                    cout << matrix_to_html(matrix_get_vector(*matrix));
                    std::cout << "~Type 4~" << std::endl;
                    cout << matrix_to_html(matrix_get_vector(*matrix), matrix_get_style(*matrix));
                    break;
                case 4:
                    While = false;
                    break;
                default:
                    std::cout << "Error!" << std::endl;
                    While = false;
                    break;
            }
        }
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        matrix_delete(matrix);
        return INPUT;
    }
    matrix_delete(matrix);
    return OK;
}

/**
 * @brief func for choosing an option from menu
 * 
 * @return int - selected option
 */

int dialog() {
    int rc, option;
    int i, check = 0;
    do {
        for (i = 0; i < N; ++i)
            printf("%d. %s\n", i, msgs[i]);
        printf("Choose Option: ");
        option = get_int();
    } while (option < 0 || option >= N);
    return option;
}