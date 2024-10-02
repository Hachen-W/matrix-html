#ifndef HTML_H_INCLUDED
#define HTML_H_INCLUDED


#include <string>
#include <vector>

using namespace std;


string matrix_to_html(const int** array, size_t count_lines, size_t count_columns);
string matrix_to_html(const int** array, size_t count_lines, size_t count_columns, const char* style);
string matrix_to_html(std::vector<std::vector<int>>);
string matrix_to_html(std::vector<std::vector<int>>, std::string);


#endif