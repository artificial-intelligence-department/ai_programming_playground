#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

const int MATRIX_SIZE = 10;
const char FILE_NAME[] = "output.txt";

// Функція для генерації випадкового числа в межах [0, 100]
int getRandomNumber() {
    return rand() % 101;
}

// Функція для генерації матриці з випадкових чисел
void generateMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            matrix[i][j] = getRandomNumber(); // 7 в коді використаний двовимірний масив 
        }
    }
}

// Функція для обчислення сум 3-4 випадкових елементів кожного стовпця та створення масиву сум
int* calculateColumnSums(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    static int sums[10]; 

    for (int j = 0; j < MATRIX_SIZE; ++j) {
        int sum = 0; // 1 в коді використана як мінімум одна цілочисельна змінна
        for (int i = 0; i < std::min(4, MATRIX_SIZE); ++i) { // 10 в коді використаний for цикл 
            sum += matrix[i][j];
        }
        sums[j] = sum; // 6 в коді використаний одновимірний масив
    }

    return sums;
}

// Функція для запису сум в файл
bool writeSumsToFile(int sums[10]) {
    std::ofstream outputFile(FILE_NAME);
    if (!outputFile.is_open()) {       // 16 в коді використано функції роботи з файлами, для того, щоб записати у файл
        std::cerr << "Error opening file for writing." << std::endl;
        return false;
    }

    for (int i = 0; i < 10; ++i) {
        outputFile << sums[i] << std::endl;
    }

    outputFile.close();
    return true;
}

// Функція для обчислення добутку елементів файлу
int calculateProductFromFile() {
    std::ifstream inputFile(FILE_NAME);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file for reading." << std::endl;
        return -1;
    }

    int product = 1;
    int value;

    while (inputFile >> value) { // 9 в коді використаний while цикл
        product *= value;
    }

    inputFile.close();
    return product;
}

// Функція для видалення файлу
void deleteFile() {
    if (remove(FILE_NAME) == 0) { // 5 в коді використані умовні оператори та розгалуження
        std::cout << "File " << FILE_NAME << " deleted successfully." << std::endl;
    } else {
        std::cerr << "Error deleting file." << std::endl;
    }
}

int main() {
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    generateMatrix(matrix);

    // Виведення початкової матриці
    std::cout << "Original Matrix:" << std::endl;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int* sums = calculateColumnSums(matrix);

    // Виведення сум стовпців
    std::cout << "Column Sums:" << std::endl;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        std::cout << sums[i] << " ";
    }
    std::cout << std::endl;

    // Запис сум в файл
    if (writeSumsToFile(sums)) {
        std::cout << "Sums written to file successfully." << std::endl;

        // Обчислення добутку елементів з файлу
        int product = calculateProductFromFile();

        if (product != -1) {
            std::cout << "Product of sums from file: " << product << std::endl; // 21 в коді використано оператори виведення та введення даних
        }

        // Видалення файлу
        deleteFile();
    }

    return 0;
}
