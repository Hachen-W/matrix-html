#include <string.h>
#include <catch2/catch_test_macros.hpp>
#include "html.hpp"
#include <typeinfo>

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE_THROWS( matrix_to_html(nullptr, 2, 2) );
    string str;
    int** array = new int*[2];
    for (int i = 0; i < 2; i++) {
        int* array_sub = new int[2];
        for (int j = 0; j < 2; j++) {
            array_sub[j] = j;
        }
        array[i] = array_sub;
    }
    str = "<!DOCTYPE html>\n<html>\n<head>\n<style>\ntable, th, td {\n\tborder:1px solid black;\n}\n</style>\n</head>\n<body>\n\n<table>\n\t<tr>\n\t\t<th>0</th>\n\t\t<th>1</th>\n\t</tr>\n\t<tr>\n\t\t<td>0</td>\n\t\t<td>1</td>\n\t</tr>\n</table>\n\n</body>\n</html>\n";
    REQUIRE( matrix_to_html((const int**) array, 2, 2) == str );
    str.clear();
    str = "<!DOCTYPE html>\n<html>\n<head>\n<style>\nabacaba abc\ntable, th, td {\n\tborder:1px solid black;\n}\n</style>\n</head>\n<body>\n\n<table>\n\t<tr>\n\t\t<th>0</th>\n\t\t<th>1</th>\n\t</tr>\n\t<tr>\n\t\t<td>0</td>\n\t\t<td>1</td>\n\t</tr>\n</table>\n\n</body>\n</html>\n";
    REQUIRE( matrix_to_html((const int**) array, 2, 2, "abacaba abc") == str );
    str.clear();
    
    std::vector<std::vector<int>> varray;
    std::vector<int> varray_sub;
    for (int i = 0; i < 2; i++) {
        varray_sub.clear();
        for (int j = 0; j < 2; j++)
            varray_sub.insert(varray_sub.end(), j);
        varray.insert(varray.end(), varray_sub);
    }
    str = "<!DOCTYPE html>\n<html>\n<head>\n<style>\ntable, th, td {\n\tborder:1px solid black;\n}\n</style>\n</head>\n<body>\n\n<table>\n\t<tr>\n\t\t<th>0</th>\n\t\t<th>1</th>\n\t</tr>\n\t<tr>\n\t\t<td>0</td>\n\t\t<td>1</td>\n\t</tr>\n</table>\n\n</body>\n</html>\n";
    REQUIRE( matrix_to_html(varray) == str );
    str.clear();
    str = "<!DOCTYPE html>\n<html>\n<head>\n<style>\nabacaba abc\ntable, th, td {\n\tborder:1px solid black;\n}\n</style>\n</head>\n<body>\n\n<table>\n\t<tr>\n\t\t<th>0</th>\n\t\t<th>1</th>\n\t</tr>\n\t<tr>\n\t\t<td>0</td>\n\t\t<td>1</td>\n\t</tr>\n</table>\n\n</body>\n</html>\n";
    REQUIRE( matrix_to_html(varray, "abacaba abc") == str );
    str.clear();
}
