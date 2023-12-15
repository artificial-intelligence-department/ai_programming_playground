#include <iostream>
#include <vector>
using namespace std;

double** createMatrix() {
    double** matrix = new double*[10];
    for (int i = 0; i < 10; ++i) {
        matrix[i] = new double[10];
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = i * j + i;
        }
    }
    return matrix;
} // створення матриці 10 на 10 зі значеннями, які обраховуються математичної функцією

double** newFunction(double** matrix) {
    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < 9; ++i) {
            for (int k = 0; k < 9 - i; ++k) {
                if (matrix[k][j] > matrix[k + 1][j]) {
                    double temp = matrix[k][j];
                    matrix[k][j] = matrix[k + 1][j];
                    matrix[k + 1][j] = temp;
                }
            }
        }
    }
    return matrix;
} // функція сортує стовпці по зростанню за методом бульбашки

int** newFunction(int** matrix2, int A) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrix2[i][j] = i * j + i;
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrix2[i][j] = i * j + i;
        }
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k < 9 - j; ++k) {
                if (matrix2[k][j] < matrix2[k + 1][j]) {
                    int temp = matrix2[k][j];
                    matrix2[k][j] = matrix2[k + 1][j];
                    matrix2[k + 1][j] = temp;
                }
            }
        }
    }
    return matrix2;
} // функція сортує рядуи по спаданню за методом бульбашки

int calculateSuma(int* column, int size) {
    int suma = 0;
    int count = 0;
    while (count < 4) {
        int randomIndex = rand() % size;
        suma += column[randomIndex];
        ++count;
    } 
    return suma;
} // функція рахує суму рандомних 4 елементів і повертає її значення

int main() {
    int A=974;
    int* column;
    int k;
    double** matrix = createMatrix();
    newFunction(matrix);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++i) {
            cout << matrix[i][j];
    }
    }
    k = calculateSuma(column, 5);
    cout << k;
    return 0;
}
