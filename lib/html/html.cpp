#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include "html.hpp"

using namespace std;


/**
 * @brief lambda func to accumulate to string new lines with th
 * @param html - your current string
 * @param numb - required number for adding
 */
auto str_add_th = [](string html, int numb) {
    html += "\t\t<th>";
    html += to_string(numb);
    html += "</th>\n";
    return html;
};

/**
 * @brief lambda func to accumulate to string new lines with td
 * @param html - your current string
 * @param numb - required number for adding
 */
auto str_add_td = [](string html, int numb) {
    html += "\t\t<td>";
    html += to_string(numb);
    html += "</td>\n";
    return html;
};

/**
 * @brief convert matrix to html-string
 * 
 * @param array - your current matrix
 * @param count_lines - count of lines in your matrix
 * @param count_columns - count of columns in your matrix
 * @return string - matrix in html format
 */
string matrix_to_html(const int** array, size_t count_lines, size_t count_columns) {
    return matrix_to_html(array, count_lines, count_columns, NULL);
}
/**
 * @brief convert matrix to html-string
 * 
 * @param array - your current matrix
 * @param count_lines - count of lines in your matrix
 * @param count_columns - count of columns in your matrix
 * @param style - style of matrix in html required for adding
 * @return string - matrix in html format
 */
string matrix_to_html(const int** array, size_t count_lines, size_t count_columns, const char* style) {
    if (array == nullptr)
        throw std::logic_error("Incorrect Input!");
    int check = 0;
    string html;
    html += "<!DOCTYPE html>\n";
    html += "<html>\n";
    html += "<head>\n";
    html += "<style>\n";
    if (style != nullptr) {
        html += style;
        html += "\n";
    }
    html += "table, th, td {\n";
    html += "\tborder:1px solid black;\n";
    html += "}\n";
    html += "</style>\n";
    html += "</head>\n";
    html += "<body>\n";
    html += "\n";
    html += "<table>\n";
    if (count_lines > 0)
        for (int i = 0; i < 1; i++) {
            html += "\t<tr>\n";
            for (int j = 0; j < count_columns; j++) {
                html += "\t\t<th>";
                html += to_string(array[i][j]);
                html += "</th>\n";
            }
            html += "\t</tr>\n";
        }
    for (int i = 1; i < count_lines; i++) {
        html += "\t<tr>\n";
        for (int j = 0; j < count_columns; j++) {
            html += "\t\t<td>";
            html += to_string(array[i][j]);
            html += "</td>\n";
        }
        html += "\t</tr>\n";
    }
    html += "</table>\n";
    html += "\n";
    html += "</body>\n";
    html += "</html>\n";
    return html;
}
/**
 * @brief convert matrix to html-string
 * 
 * @param array - your current matrix
 * @return string - matrix in html format
 */
string matrix_to_html(std::vector<std::vector<int>> array) {
    return matrix_to_html(array, "");
}
/**
 * @brief convert matrix to html-string
 * 
 * @param array - your current matrix
 * @param style - style of matrix in html required for adding
 * @return string - matrix in html format
 */
string matrix_to_html(std::vector<std::vector<int>> array, std::string style) {
    int check = 0;
    string html;
    html += "<!DOCTYPE html>\n";
    html += "<html>\n";
    html += "<head>\n";
    html += "<style>\n";
    if (!style.empty()) {
        html += style;
        html += "\n";
    }
    html += "table, th, td {\n";
    html += "\tborder:1px solid black;\n";
    html += "}\n";
    html += "</style>\n";
    html += "</head>\n";
    html += "<body>\n";
    html += "\n";
    html += "<table>\n";
    
    if (array.size() > 0)
        for (int i = 0; i < 1; i++) {
            html += "\t<tr>\n";
            html += std::accumulate(array[i].begin(), array[i].end(), std::string(""), str_add_th);
            html += "\t</tr>\n";
        }
    for (int i = 1; i < array.size(); i++) {
        html += "\t<tr>\n";
        html += std::accumulate(array[i].begin(), array[i].end(), std::string(""), str_add_td);
        html += "\t</tr>\n";
    }
    html += "</table>\n";
    html += "\n";
    html += "</body>\n";
    html += "</html>\n";
    return html;
}