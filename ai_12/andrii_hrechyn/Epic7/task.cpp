#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>

using namespace std;

const int numberofpr = 963;
const char* filename = "result.txt";

template <typename T, typename Func>
void fill_matrix_with_function(T matrix[10][10], Func func);

void sort_matrix_columns(double matrix[10][10], double multiplier);
void sort_matrix_rows(int matrix[10][10], int pr_multiplier);

template <typename T>
void calculate_sums(const T matrix[10][10], double multiplier, int res_array[10]);

bool write_to_file(const int res_array[10]);
void calculate_data_from_file();
void removefile();

void generatingmatrix() {
    if (numberofpr % 2 == 0) {
        double matrix[10][10];
        fill_matrix_with_function(matrix, [](int i, int j) {
            return sin(i * j * 0.1);
        });
        sort_matrix_columns(matrix, numberofpr * 2.5);
    } else {
        int matrix[10][10];
        fill_matrix_with_function(matrix, [](int i, int j) {
            return i * i + j * j;
        });
        sort_matrix_rows(matrix, numberofpr);
    }
}

template <typename T, typename Func>
void fill_matrix_with_function(T matrix[10][10], Func func) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = func(i, j);
        }
    }
}

void sort_matrix_columns(double matrix[10][10], double multiplier) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 9 - j; k++) {
                if (matrix[k][i] > matrix[k + 1][i]) {
                    swap(matrix[k][i], matrix[k + 1][i]);
                }
            }
        }
    }

    int res_array[10];

    calculate_sums(matrix, multiplier, res_array);

    bool write_res = write_to_file(res_array);

    if (write_res) {
        calculate_data_from_file();
    }

    removefile();
}

void sort_matrix_rows(int matrix[10][10], int pr_multiplier) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 9 - j; k++) {
                if (matrix[i][k] < matrix[i][k + 1]) {
                    swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }

    int res_array[10];
    calculate_sums(matrix, pr_multiplier, res_array);

    bool write_res = write_to_file(res_array);

    if (write_res) {
        calculate_data_from_file();
    }
    removefile();
}

template <typename T>
void calculate_sums(const T matrix[10][10], double multiplier, int res_array[10]) {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < 10; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            int random_index = rand() % 10;
            sum += static_cast<int>(matrix[random_index][i]);
        }
        res_array[i] = static_cast<int>(sum * multiplier);
    }
}

bool write_to_file(const int res_array[10]) {
    ofstream outputfile(filename);

    if (outputfile.is_open()) {
        for (int i = 0; i < 10; i++) {
            outputfile << res_array[i] << ' ';
        }
        outputfile.close();
        return true;
    } else {
        return false;
    }
}

void calculate_data_from_file() {
    ifstream inputfile(filename);
    if (inputfile.is_open()) {
        int product = 1;
        int value;

        while (inputfile >> value) {
            product *= value;
        }

        inputfile.close();

        cout << "Product of values: " << product << endl;
    }
}

void removefile() {
    if (remove(filename) == 0) {
        cout << "File is deleted" << endl;
    } else {
        cout << "Error" << endl;
    }
}

int main() {
    generatingmatrix();
    return 0;
}
