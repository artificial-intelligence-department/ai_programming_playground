#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

const int pull_request_number = 70;  // Замініть на свій номер пулл реквесту

// Крок 1
void fillMatrix(double matrix[10][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = sin(i * j * pull_request_number);  // Замість sin можна використовувати іншу математичну функцію
        }
    }
}

void fillMatrix(int matrix[10][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = abs(cos(i * j * pull_request_number));  // Замість abs можна використовувати іншу математичну функцію
        }
    }
}

// Крок 2
void sortMatrix(double matrix[10][10], double pull_request_value) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k < 9 - j; ++k) {
                if (matrix[k][i] > matrix[k + 1][i]) {
                    std::swap(matrix[k][i], matrix[k + 1][i]);
                }
            }
        }
    }
}

void sortMatrix(int matrix[10][10], int pull_request_value) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k < 9 - j; ++k) {
                if (matrix[i][k] < matrix[i][k + 1]) {
                    std::swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }
}

// Крок 3
void calculateSums(double matrix[10][10]) {
    int sums[10];
    srand(time(0));

    for (int i = 0; i < 10; ++i) {
        sums[i] = 0;
        for (int j = 0; j < 4; ++j) {
            int randomIndex = rand() % 10;
            sums[i] += matrix[randomIndex][i];
        }

        // Якщо сума має дробову частину, вона відкидається
        sums[i] = static_cast<int>(sums[i]);
    }

    // Крок 4
    writeToFile(sums);

    // Крок 5
    calculateProduct();
}

// Крок 4
void writeToFile(int sums[10]) {
    std::ofstream outFile("result_file.txt");

    for (int i = 0; i < 10; ++i) {
        outFile << sums[i] << std::endl;
    }

    outFile.close();
}

// Крок 5
void calculateProduct() {
    std::ifstream inFile("result_file.txt");
    int product = 1;
    int value;

    while (inFile >> value) {
        product *= value;
    }

    // Виведення результату в консоль
    std::cout << "Product: " << product << std::endl;

    inFile.close();
}

// Крок 6
void deleteFile() {
    if (remove("result_file.txt") != 0) {
        perror("Error deleting file");
    } else {
        std::cout << "File deleted successfully" << std::endl;
    }
}

// Головна функція
int main() {
    double doubleMatrix[10][10];
    int intMatrix[10][10];

    // Визначення типу матриці (з числами з плаваючою крапкою або цілими числами)
    if (pull_request_number % 2 == 0) {
        fillMatrix(doubleMatrix);
        sortMatrix(doubleMatrix, pull_request_number * 1.234);  // Замініть 1.234 на ваше значення з плаваючою крапкою
    } else {
        fillMatrix(intMatrix);
        sortMatrix(intMatrix, pull_request_number * 1.234);
    }

    // Крок 2
    // Для варіанту (a) можна використовувати sortMatrix(doubleMatrix, pull_request_number * 1.234);
    // Для варіанту (b) можна використовувати sortMatrix(intMatrix, pull_request_number * 1.234);

    // Крок 3, 4 та 5
    calculateSums(doubleMatrix);

    // Крок 6
    deleteFile();

    return 0;
}