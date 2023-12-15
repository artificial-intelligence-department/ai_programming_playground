#include <iostream>
using namespace std;

const int row = 10;
const int col = 10;
const int CONST = 1020;//В коді використана як мінімум одна цілочисельна змінна
//В коді використана як мінімум одна цілочисельна константа
float matrix[row][col];//В коді використана як мінімум одна дійсна змінна
//В коді використаний двовимірний масив
void floatmatrix() {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            matrix[i][j] = (i + j) * CONST;//В коді використано математичні операції та математичні функції
        }
    }
}

void sortcol(float matrix[row][col], int value) {
    for (int cols = 0; cols < col; ++cols) { //В коді використаний for цикл
        for (int i = 0; i < row - 1; ++i) {
            for (int j = 0; j < row - i - 1; ++j) {
                if (matrix[j][cols] > matrix[j + 1][cols]) {//В коді використані умовні оператори та розгалуження
                    float temp = matrix[j][cols];
                    matrix[j][cols] = matrix[j + 1][cols];
                    matrix[j + 1][cols] = temp;
                }
            }
        }
    }
}

void sortrow(float matrix[row][col], int value) {
    for (int rows = 0; rows < row; ++rows) {
        for (int i = 0; i < col - 1; ++i) {
            for (int j = 0; j < col - i - 1; ++j) {
                if (matrix[rows][j] < matrix[rows][j + 1]) {
                    float temp = matrix[rows][j];
                    matrix[rows][j] = matrix[rows][j + 1];
                    matrix[rows][j + 1] = temp;
                }
            }
        }
    }
}

int main() {
    floatmatrix();
    cout << "Початкова матриця: " << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    sortcol(matrix, CONST);
    cout << "\nМатриця зі стовпцями, відсотрованими за зростанням: " << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    sortrow(matrix, CONST);
    cout << "\nМатриця з рядками, відсортованими за спаданням: " << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
