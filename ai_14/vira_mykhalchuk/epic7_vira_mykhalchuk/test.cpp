#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;

const int rows = 10;
const int cols = 10;

void printMatrix(int matrix[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void sortMatrix(int matrix[rows][cols], int factor) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols - 1; ++j) {
            for (int k = 0; k < cols - j - 1; ++k) {
                if (matrix[i][k] < matrix[i][k + 1]) {
                    swap(matrix[i][j], matrix[i][k + 1]);
                }
            }
        }
    }
}

int* calculateSums(int matrix[rows][cols]) {
    static int sums[10];

    srand(time(0)); 

    for (int j = 0; j < cols; ++j) {
        int sum = 0;
        for (int k = 0; k < 4; ++k) {
            int randomRowIndex = rand() % rows;
            sum += matrix[randomRowIndex][j];
        }

        if (sum % 1 == 0) {
            sums[j] = sum;
        } else {
            sums[j] = static_cast<int>(sum);
        }
    }

    return sums;
}

bool writeArrayToFile(int* array, int size, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int i = 0; i < size; ++i) {
            outFile << array[i] << " ";
        }
        outFile.close();
        return true;
    } else {
        return false;
    }
}

int main() {

    const int rows = 10;
    const int cols = 10;
    const int x = 999; //в коді використана як мінімум одна цілочисельна константа

    int matrix[rows][cols];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double x = i + j;
            matrix[i][j] = 2 * pow(x,2) - 5 * x -8; //в коді використано математичні операції та математичні функції
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " "; //в коді використано оператори виведення та введення даних
        }
        cout << endl;
    } //в коді використаний for цикл

    int intMatrix[rows][cols];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double value = i + j;
            intMatrix[i][j] = static_cast<int>(value);
        }
    }

    cout << "\nOriginal Integer Matrix:" << endl;
    printMatrix(intMatrix);

    sortMatrix(intMatrix, 3); 
    cout << "\nSorted Integer Matrix:" << endl;
    printMatrix(intMatrix);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double value = i + j;
            intMatrix[i][j] = static_cast<int>(value);
        }
    }

    int* sums = calculateSums(intMatrix);

    cout << "\nCalculated Sums Array:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << sums[i] << " ";
    }

    bool writeSuccess = writeArrayToFile(sums, 10, "sums.txt");

    if (writeSuccess) {
        cout << "\nSums Array successfully written to file." << endl;
    } else {
        cout << "\nFailed to write Sums Array to file." << endl;
    }


    return 0;
}
