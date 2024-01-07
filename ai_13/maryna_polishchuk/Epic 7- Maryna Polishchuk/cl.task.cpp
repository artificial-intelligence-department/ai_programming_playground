#include <iostream>
#include <cmath>
#include <cctype>

// в коді використаний двовимірний масив, це вимагає завдання 
void createMatrix(double matrix[10][10], int a, double b, float c, const int d) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = a * i + b * j + d - c;
        }
    }
}

void printMatrix(const double matrix[10][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Перевантажені функції для сортування
void sort(double matrix[10][10], int start, int end, bool sortByRows) {
    for (int i = start; i < end; ++i) {
        for (int j = start; j < end - 1; ++j) {
            for (int k = start; k < end - j - 1; ++k) {
                if (sortByRows ? (int)matrix[i][k] < (int)matrix[i][k + 1] : (int)matrix[k][j] > (int)matrix[k + 1][j]) {
                    double temp = matrix[sortByRows ? i : k][sortByRows ? k : j];
                    matrix[sortByRows ? i : k][sortByRows ? k : j] = matrix[sortByRows ? i : k + 1][sortByRows ? k + 1 : j];
                    matrix[sortByRows ? i : k + 1][sortByRows ? k + 1 : j] = temp;
                }
            }
        }
    }
}

// Перевантажені функції для сортування
void sort(double matrix[10][10], bool sortByRows) {
    sort(matrix, 0, 10, sortByRows);
}

int main() {
    double myMatrix[10][10];

     // в коді використана як мінімум одна цілочисельна змінна
    // в коді використана як мінімум одна дійсна змінна
    // в коді використана як мінімум одна дійсний з подвійною точністю змінна
    // в коді використана як мінімум одна цілочисельна константа, 
    //ми їх використовуємо при обчисленні елементів двовимірного масиву
    int a = 3;
    double b = 5.3;
    float c = 3.4;
    const int d = 1002;

    createMatrix(myMatrix, a, b, c, d);
    printMatrix(myMatrix);

    char input;
    std::cout << "Enter 'c' to sort columns, 'r' to sort rows: ";
    std::cin >> input;

    //	в коді використані умовні оператори та розгалуження
    if (input == 'c') {
        sort(myMatrix, false);
    } else if (input == 'r') {
        sort(myMatrix, true);
    } else {
        std::cout << "Invalid input. Please enter 'c' or 'r'." << std::endl;
        return 1;
    }

    std::cout << "\nSorted Matrix:" << std::endl;
    printMatrix(myMatrix);

    return 0;
}
