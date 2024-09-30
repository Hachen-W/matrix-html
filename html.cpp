#include <iostream>
#include <vector>
#include <string>


using namespace std;

string matrix_to_html(const int** array, size_t count_lines, size_t count_columns) {
    if (array == nullptr)
        throw std::logic_error("Incorrect Input!");
    int check = 0;
    string html;
    html += "<!DOCTYPE html>\n";
    html += "<html>\n";
    html += "<head>\n";
    html += "<style>\n";
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
string matrix_to_html(std::vector<std::vector<int>> array) {
    int check = 0;
    string html;
    html += "<!DOCTYPE html>\n";
    html += "<html>\n";
    html += "<head>\n";
    html += "<style>\n";
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
            for (int j = 0; j < array[i].size(); j++) {
                html += "\t\t<th>";
                html += to_string(array[i][j]);
                html += "</th>\n";
            }
            html += "\t</tr>\n";
        }
    for (int i = 1; i < array.size(); i++) {
        html += "\t<tr>\n";
        for (int j = 0; j < array[i].size(); j++) {
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
            for (int j = 0; j < array[i].size(); j++) {
                html += "\t\t<th>";
                html += to_string(array[i][j]);
                html += "</th>\n";
            }
            html += "\t</tr>\n";
        }
    for (int i = 1; i < array.size(); i++) {
        html += "\t<tr>\n";
        for (int j = 0; j < array[i].size(); j++) {
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