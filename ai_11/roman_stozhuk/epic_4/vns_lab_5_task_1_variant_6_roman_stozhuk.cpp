#include <iostream>

bool saddle_point(int input, int *column, int *row, int size) {
    int c_min = INT_MAX, c_max = INT_MIN, r_min = INT_MAX, r_max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (column[i] > c_max) {c_max = column[i];}
        if (column[i] < c_min) {c_min = column[i];}
        if (row[i] > r_max) {r_max = row[i];}
        if (row[i] < r_min) {r_min = row[i];}
    }
    if ((c_min == input && r_max == input) || (c_max == input && r_min == input)) {return true;}
    else {return false;}
}

int main() {
    std::cout << "Enter size of your matrix: ";
    int size;
    std::cin >> size;
    std::cout << "Enter your matrix:\n";
    int **rows = new int*[size];
    for (int r = 0; r < size; r++) {
        rows[r] = new int[size];
        for (int c = 0; c < size; c++ ) {
                std::cin >> rows[r][c];
        }
    }
    std::cout << "Saddle points: ";
    int *cur_col = new int[size];
    int *cur_row = new int[size];
    for (int r = 0; r < size; r++ ) {
        for (int c = 0; c < size; c++ ) {
            for (int temp = 0; temp < size; temp++) {
                cur_row[temp] = rows[r][temp];
                cur_col[temp] = rows[temp][c];
            }
            if(saddle_point(rows[r][c], cur_col, cur_row, size)) {std::cout << rows[r][c] << " "; }
        }
    }
    return 0;
}