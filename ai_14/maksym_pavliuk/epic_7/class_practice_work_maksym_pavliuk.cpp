#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const char* FILE_NAME = "output.txt";

// Функція для створення та повернення матриці
float** createFilledMatrix() {
    // Виділення пам'яті для матриці
    float** matrix = new float*[10];
    for (int i = 0; i < 10; ++i) {
        matrix[i] = new float[10];
    }

    // Ініціалізація генератора випадкових чисел
    srand(time(0));

    // Заповнення матриці випадковими числами від 0 до 10 з плаваючою комою
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            // Випадкове число від 0 до 10 з плаваючою комою
            matrix[i][j] = static_cast<float>(rand()) / RAND_MAX * 10.0f;
        }
    }

    return matrix;
}

// Функція для виведення матриці на екран
void printMatrix(float** matrix) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

// Функція для звільнення виділеної пам'яті
void deleteMatrix(float** matrix) {
    for (int i = 0; i < 10; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Функція для сортування матриці по спаданню
void SortMatrix(float** matrix) {
    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < 9; ++i) {
            for (int k = 0; k < 9 - i; ++k) {
                if (matrix[k][j] < matrix[k + 1][j]) {
                    // Обмін елементів
                    float temp = matrix[k][j];
                    matrix[k][j] = matrix[k + 1][j];
                    matrix[k + 1][j] = temp;
                }
            }
        }
    }
}

// Функція для розрахунку 10 сум та створення нового цілочисельного масиву
void calculateSums(float** matrix, int* resultArray) {
    srand(time(0));

    for (int j = 0; j < 10; ++j) {
        int sum = 0;
        int numElements = (rand() % 2) + 3;

        for (int i = 0; i < numElements; ++i) {
            int randomRow = rand() % 10;
            sum += static_cast<int>(matrix[randomRow][j]); // Додаємо всі елементи
        }

        // Відкидаємо дробову частину тільки після додавання всіх елементів
        resultArray[j] = sum;
    }
}

// Функція для запису значень статичного масиву у файл
bool writeArrayToFile(int* resultArray, const char* filename) {
    ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (int i = 0; i < 10; ++i) {
            outputFile << resultArray[i] << " ";
        }

        outputFile.close();
        return true; // Запис відбувся успішно
    } else {
        return false; // Помилка при відкритті файлу
    }
}

// Функція для видалення файлу
void deleteFile(const char* filename) {
    if (remove(filename) == 0) {
        cout << "File deleted successfully." << endl;
    } else {
        cerr << "Error deleting file." << endl;
    }
}

// Функція для відкриття файлу, обчислення добутку і виведення результату
float processFileAndCalculateProduct() {
    ifstream inputFile(FILE_NAME);

    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << FILE_NAME << endl;
        return 0.0f;
    }

    float product = 1.0f;
    float value;

    while (inputFile >> value) {
        product *= value;
    }

    inputFile.close();

    // Виведення результату у консоль
    cout << "Product of elements in the file: " << product << endl;

    return product;
}

int main() {
    float** myMatrix = createFilledMatrix();
    int pr_code = 848;

    cout << "Original Matrix:" << endl;
    printMatrix(myMatrix);
    cout << "\n";

    SortMatrix(myMatrix);

    cout << "Matrix after sorting columns in descending order:" << endl;
    printMatrix(myMatrix);
    cout << "\n";

    int resultArray[10];
    calculateSums(myMatrix, resultArray);

    cout << "Result Array:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << resultArray[i] << " ";
    }
    cout << "\n";

    // Запис статичного масиву у файл
    if (writeArrayToFile(resultArray, FILE_NAME)) {
        cout << "Array successfully written to file." << endl;
    } else {
        cout << "Error writing to file." << endl;
    }

    // Обробка файлу та рахування добутку
    float product = processFileAndCalculateProduct();

    // Видалення файлу
    deleteFile(FILE_NAME);

    deleteMatrix(myMatrix);

    return 0;
}