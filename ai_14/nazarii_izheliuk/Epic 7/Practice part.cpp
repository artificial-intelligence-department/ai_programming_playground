#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include<fstream>

using namespace std;
const int github = 952; //в коді використана як мінімум одна цілочисельна константа
const char* FILENAME = "952.txt"; //в коді використана як мінімум одна константа

double** generateMatrix() {
    int rows = 10;
    int cols = 10;

    double** matrix = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new double[cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = sin(j) + i; // в коді використано математичні операції та математичні функц
        }
    }
    return matrix;
}

void printMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

double** fillArrayWithRandomElementSums(double** matrix) {
    int rows = 10;
    int cols = 10;

    double** newArray = new double*[cols];
    for (int i = 0; i < cols; ++i) {
        newArray[i] = new double[1];
        newArray[i][0] = 0;
    }

    for (int j = 0; j < cols; ++j) { // в коді використаний for цикл
        double sum = 0.0;
        for (int i = 0; i < 4; ++i) {
            int selectedRow = rand() % rows;
            sum += matrix[selectedRow][j];
        }

        int intPart = static_cast<int>(sum);
        newArray[j][0] = intPart;
    }

    return newArray;
}

void bubbleSortColumn(double** matrix, int rows, int cols) {  // в коді використано параметри та аргументи функції
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows - 1; ++j) {
            for (int k = 0; k < rows - j - 1; ++k) {
                if (matrix[k][i] > matrix[k + 1][i]) {
                    double temp = matrix[k][i];
                    matrix[k][i] = matrix[k + 1][i];
                    matrix[k + 1][i] = temp;
                }
            }
        }
    }
}

void writeArrayToFile(double** newArray, int cols, const char* filename) { //в коді використано функції роботи з файлами, для того, щоб записати у файл
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int i = 0; i < cols; ++i) {
            outFile << newArray[i][0] << endl;
        }
        outFile.close();
        cout << "Results have been written to " << filename << endl;
    } else {
        cerr << "Unable to open file " << filename << endl;
    }
}

double calculateProductFromFile(const char* filename) { //в коді використано функції роботи з файлами, для того, щоб зчитати з файлу
    ifstream inFile(filename);
    double product = 1.0; // Ініціалізація добутку

    if (inFile.is_open()) { //в коді використані умовні оператори та розгалуження

        double num;
        while (inFile >> num) { // в коді використаний while цикл
            product *= num;
        }
        inFile.close();
        return product;
    } else {
        cerr << "Unable to open file " << filename << endl;
        return 0.0; // Повертаємо 0 у разі помилки
    }
}

void deleteFile(const char* filename) {
    if (remove(filename) != 0) {
        cerr << "Error deleting file: " << filename << endl;
    } else {
        cout << "File deleted successfully: " << filename << endl;
    }
}

int main() {
    double** result = generateMatrix(); //в коді використана як мінімум одна дійсна змінна
    int rows = 10;  // в коді використана як мінімум одна цілочисельна змінна
    int cols = 10;  // в коді використана як мінімум одна цілочисельна змінна

    cout << "Original Matrix:" << endl;
    printMatrix(result, rows, cols);

    bubbleSortColumn(result, rows, cols);

    cout << "Matrix after sorting columns:" << endl; // в коді використано оператори виведення та введення даних
    printMatrix(result, rows, cols);

    cout << "Sums of randomly selected elements in each column (without decimal part):" << endl;
    double** sumsArray = fillArrayWithRandomElementSums(result);

    for (int i = 0; i < cols; ++i) {
        cout << "Sum of column " << i << ": " << sumsArray[i][0] << endl;
    }

    writeArrayToFile(sumsArray, cols, FILENAME);

    double product = calculateProductFromFile(FILENAME);

    cout << product << endl;
    deleteFile(FILENAME);
    return 0;
}
