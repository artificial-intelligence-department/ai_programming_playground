#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Крок 1
constexpr int pull_request_number = 152;

// Крок 1a
float** generateFloatMatrix() {
    float** matrix = new float*[10];
    for (int i = 0; i < 10; ++i) {
        matrix[i] = new float[10];
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = static_cast<float>(i * 10 + j + pull_request_number);
        }
    }
    return matrix;
}

// Крок 1b
int** generateIntMatrix() {
    int** matrix = new int*[10];
    for (int i = 0; i < 10; ++i) {
        matrix[i] = new int[10];
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = i * 10 + j + pull_request_number;
        }
    }
    return matrix;
}

// Крок 2
template <typename T>
void printMatrix(T** matrix) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Крок 3
template <typename T>
void sortMatrix(T** matrix, int pull_request_value) {
    // Сортування стовпців за зростанням
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10 - 1; ++j) {
            for (int k = 0; k < 10 - j - 1; ++k) {
                if (matrix[k][i] > matrix[k + 1][i]) {
                    swap(matrix[k][i], matrix[k + 1][i]);
                }
            }
        }
    }

    // Сортування рядків за спаданням
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10 - 1; ++j) {
            for (int k = 0; k < 10 - j - 1; ++k) {
                if (matrix[i][k] < matrix[i][k + 1]) {
                    swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }
}

// Крок 4
int* calculateSums(float** matrix) {
    int* sums = new int[10];

    for (int i = 0; i < 10; ++i) {
        int sum = 0;
        for (int j = 0; j < 4; ++j) {
            int randomIndex = rand() % 10;
            sum += matrix[randomIndex][i];
        }
        sums[i] = sum;
    }

    return sums;
}

int* calculateSums(int** matrix) {
    int* sums = new int[10];

    for (int i = 0; i < 10; ++i) {
        int sum = 0;
        for (int j = 0; j < 3; ++j) {
            int randomIndex = rand() % 10;
            sum += matrix[i][randomIndex];
        }
        sums[i] = sum;
    }

    return sums;
}

// Крок 5
bool writeToFile(int* array) {
    ofstream outFile("output.txt");
    if (!outFile.is_open()) {
        return false;
    }

    for (int i = 0; i < 10; ++i) {
        outFile << array[i] << " ";
    }

    outFile.close();
    return true;
}

// Крок 6
int calculateProductFromFile() {
    ifstream inFile("output.txt");
    if (!inFile.is_open()) {
        return -1; // Помилка відкриття файлу
    }

    int product = 1;
    int value;

    while (inFile >> value) {
        product *= value;
    }

    inFile.close();

    cout << "Добуток елементів з файлу: " << product << endl;

    return product;
}

// Крок 7
void deleteFile() {
    if (remove("output.txt") != 0) {
        cout << "Помилка видалення файлу" << endl;
    } else {
        cout << "Файл успішно видалено" << endl;
    }
}

int main() {
    // Крок 1
    if (pull_request_number % 2 == 0) {
        // Крок 1a
        float** floatMatrix = generateFloatMatrix();
        printMatrix(floatMatrix);

        // Крок 2
        sortMatrix(floatMatrix, pull_request_number);

        // Крок 3a
        float pull_request_value;
        cout << "Введіть значення для pull_request_value: ";
        cin >> pull_request_value;

        // Крок 4
        int* sums = calculateSums(floatMatrix);

        // Крок 5
        bool writeSuccess = writeToFile(sums);
        cout << "Запис до файлу успішний: " << boolalpha << writeSuccess << endl;

        // Крок 6
        calculateProductFromFile();

        // Крок 7
        deleteFile();

        // Очищення пам'яті
        for (int i = 0; i < 10; ++i) {
            delete[] floatMatrix[i];
        }
        delete[] floatMatrix;
    } else {
        // Крок 1b
        int** intMatrix = generateIntMatrix();
        printMatrix(intMatrix);

        // Крок 2
        sortMatrix(intMatrix, pull_request_number);

        // Крок 3b
        int pull_request_value;
        cout << "Введіть значення для pull_request_value: ";
        cin >> pull_request_value;

        // Крок 4
        int* sums = calculateSums(intMatrix);

        // Крок 5
        bool writeSuccess = writeToFile(sums);
        cout << "Запис до файлу успішний: " << boolalpha << writeSuccess << endl;

        // Крок 6
        calculateProductFromFile();

        // Крок 7
        deleteFile();

        // Очищення пам'яті
        for (int i = 0; i < 10; ++i) {
            delete[] intMatrix[i];
        }
        delete[] intMatrix;
    }

    return 0;
}
