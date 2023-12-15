#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
const char FILE_NAME[] = "output.txt";

// Крок 1: Створення та заповнення матриці
float** createAndFillMatrix() {
    float** matrix = new float*[10];

    for (int i = 0; i < 10; i++) {
        matrix[i] = new float[10];
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // Ваша математична функція
            matrix[i][j] = pow(cos(atan(1.0 / rand())), 2);
        }
    }

    return matrix;
}


// Перевантажена функція Кроку 2 для типу int
void sortMatrixColumns(int** matrix) {
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10 - 1; i++) {
            for (int k = 0; k < 10 - i - 1; k++) {
                if (matrix[k][j] > matrix[k + 1][j]) {
                    swap(matrix[k][j], matrix[k + 1][j]);
                }
            }
        }
    }
}

// Крок 2: Сортування матриці за стовпцями
void sortMatrixColumns(float** matrix) {
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10 - 1; i++) {
            for (int k = 0; k < 10 - i - 1; k++) {
                if (matrix[k][j] > matrix[k + 1][j]) {
                    swap(matrix[k][j], matrix[k + 1][j]);
                }
            }
        }
    }
}

// Крок 3: Обчислення сум та створення статичного масиву
int* calculateSumsAndCreateArray(float** matrix) {
    int* sumsArray = new int[10];

    for (int j = 0; j < 10; j++) {
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            int randomRowIndex = rand() % 10;
            sum += static_cast<int>(matrix[randomRowIndex][j]);
        }
        sumsArray[j] = sum;
    }

    return sumsArray;
}

// Крок 4: Запис значень у файл
bool writeArrayToFile(int* sumsArray) {
    ofstream outFile(FILE_NAME);

    if (!outFile.is_open()) {
        cerr << "Error opening file for writing." << std::endl;
        return false;
    }

    for (int i = 0; i < 10; i++) {
        outFile << sumsArray[i] << " ";
    }

    outFile.close();
    return true;
}

// Крок 5: Обчислення добутку елементів у файлі
int calculateProductFromFile() {
    ifstream inFile(FILE_NAME);

    if (!inFile.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return -1;
    }

    int product = 1;
    int value;

    while (inFile >> value) {
        product *= value;
    }

    inFile.close();
    return product;
}

// Крок 6: Видалення файлу
void deleteFile() {
    if (remove(FILE_NAME) == 0) {
        cout << "File deleted successfully." << endl;
    } else {
        cerr << "Error deleting file." << endl;
    }
}

// Крок 7: Головна функція
int main() {

    // Крок 1
    float** matrix = createAndFillMatrix();

    // Крок 2
    sortMatrixColumns(matrix);

    // Крок 3
    int* sumsArray = calculateSumsAndCreateArray(matrix);

    // Крок 4
    if (writeArrayToFile(sumsArray)) {
        cout << "Array written to file successfully." << endl;

        // Крок 5
        int product = calculateProductFromFile();
        if (product != -1) {
            cout << "Product of array elements in the file: " << product << endl;
        }

        // Крок 6
        deleteFile();
    }

    // Вивільнення пам'яті
    for (int i = 0; i < 10; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] sumsArray;

    return 0;
}
