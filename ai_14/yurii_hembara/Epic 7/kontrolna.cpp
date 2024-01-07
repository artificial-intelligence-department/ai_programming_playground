#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

const int constant = 900;  // Константа, яка дорівнює 900

const char fileName[] = "output.txt";  // Ім'я файлу для збереження результатів

// Функція для створення та виведення матриці
template <typename T>
T** createAndPrintMatrix(bool isFloat) {
    T** matrix = new T*[10];

    // Заповнення матриці та виведення її на екран
    for (int i = 0; i < 10; ++i) {
        matrix[i] = new T[10];
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = static_cast<T>(i * 10 + j);
            std::cout << std::fixed << std::setprecision(2) << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return matrix;
}

// Функція для сортування стовпців матриці
template <typename T>
void sortColumns(T** matrix) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10 - 1; ++j) {
            for (int k = 0; k < 10 - j - 1; ++k) {
                if (matrix[k][i] > matrix[k + 1][i]) {
                    std::swap(matrix[k][i], matrix[k + 1][i]);
                }
            }
        }
    }
}

// Функція для сортування рядків матриці
template <typename T>
void sortRows(T** matrix) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10 - 1; ++j) {
            for (int k = 0; k < 10 - j - 1; ++k) {
                if (matrix[i][k] < matrix[i][k + 1]) {
                    std::swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }
}

// Функція для обчислення сум та створення масиву цілих чисел
int* calculateSumsAndCreateArray(int** matrix, int multiplier) {
    int* sumsArray = new int[10];
    srand(time(0));

    // Обчислення сум та заповнення масиву
    for (int i = 0; i < 10; ++i) {
        int sum = 0;
        for (int j = 0; j < 3; ++j) {
            int randomIndex = rand() % 10;
            sum += matrix[randomIndex][i];
        }
        sumsArray[i] = sum * multiplier;
    }

    return sumsArray;
}

// Функція для обчислення сум та створення масиву цілих чисел з матриці з числами з плаваючою комою
int* calculateSumsAndCreateArray(float** matrix, int multiplier) {
    int* sumsArray = new int[10];
    srand(time(0));

    // Обчислення сум та заповнення масиву
    for (int i = 0; i < 10; ++i) {
        int sum = 0;
        for (int j = 0; j < 3; ++j) {
            int randomIndex = rand() % 10;
            sum += static_cast<int>(matrix[randomIndex][i]);
        }
        sumsArray[i] = sum * multiplier;
    }

    return sumsArray;
}

// Функція для запису масиву у файл
bool writeArrayToFile(int* array) {
    std::ofstream outFile(fileName);

    if (!outFile.is_open()) {
        std::cerr << "Помилка: Неможливо відкрити файл для запису." << std::endl;
        return false;
    }

    // Запис елементів масиву в файл з числами з плаваючою комою
    for (int i = 0; i < 10; ++i) {
        outFile << std::fixed << std::setprecision(2) << array[i] << " ";
    }

    outFile.close();
    return true;
}

// Функція для обчислення добутку елементів з файлу
int calculateProductFromFile() {
    std::ifstream inFile(fileName);

    if (!inFile.is_open()) {
        std::cerr << "Помилка: Неможливо відкрити файл для читання." << std::endl;
        return 0;
    }

    int product = 1;
    int value;

    // Обчислення добутку елементів з файлу
    while (inFile >> value) {
        product *= value;
    }

    inFile.close();
    return product;
}

// Функція для видалення файлу
void deleteFile() {
    if (remove(fileName) == 0) {
        std::cout << "Файл успішно видалено." << std::endl;
    } else {
        std::cerr << "Помилка: Неможливо видалити файл." << std::endl;
    }
}

int main() {
    if (constant % 2 == 0) {
        float** floatMatrix = createAndPrintMatrix<float>(true);
        sortColumns(floatMatrix);

        int* sumsArray = calculateSumsAndCreateArray(floatMatrix, constant);

        if (writeArrayToFile(sumsArray)) {
            std::cout << "Масив успішно записано у файл." << std::endl;

            int product = calculateProductFromFile();
            std::cout << "Добуток елементів масиву з файлу: " << product << std::endl;
        }

        deleteFile();

        delete[] sumsArray;
    } else {
        int** intMatrix = createAndPrintMatrix<int>(false);
        sortRows(intMatrix);

        int* sumsArray = calculateSumsAndCreateArray(intMatrix, constant);

        if (writeArrayToFile(sumsArray)) {
            std::cout << "Масив успішно записано у файл." << std::endl;

            int product = calculateProductFromFile();
            std::cout << "Добуток елементів масиву з файлу: " << product << std::endl;
        }

        deleteFile();

        delete[] sumsArray;
    }

    return 0;
}
