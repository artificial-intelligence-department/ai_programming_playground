#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int pull_request_number = 911;
const char filename[] = "result_file.txt";

// Крок 2
int matrix[10][10];

void createMatrix() {
    srand(pull_request_number);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = rand() % 100 + 1;
        }
    }
}

// Крок 3
template <typename T>
void sortMatrix(T value) {
    if constexpr (is_same<T, int>::value) {
        for (int i = 0; i < 10; ++i) {
            sort(begin(matrix[i]), end(matrix[i]), greater<int>());
        }
    } else if constexpr (is_same<T, double>::value) {
        for (int j = 0; j < 10; ++j) {
            for (int i = 0; i < 9; ++i) {
                for (int k = 0; k < 9 - i; ++k) {
                    if (matrix[k][j] > matrix[k + 1][j]) {
                        swap(matrix[k][j], matrix[k + 1][j]);
                    }
                }
            }
        }
    }
}

// Крок 4
int sumsArray[10];

void calculateSums(double value) {
    for (int j = 0; j < 10; ++j) {
        int columnElements[4];
        for (int i = 0; i < 4; ++i) {
            int randomRowIndex = rand() % 10;
            columnElements[i] = matrix[randomRowIndex][j];
        }
        double columnSum = 0;
        for (int i = 0; i < 4; ++i) {
            columnSum += columnElements[i];
        }
        sumsArray[j] = static_cast<int>(columnSum);
    }
}

// Крок 5
bool writeToFile() {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < 10; ++i) {
            file << sumsArray[i] << endl;
        }
        file.close();
        return true;
    } else {
        cerr << "Unable to open file: " << filename << endl;
        return false;
    }
}

// Крок 6
int calculateProductFromFile() {
    ifstream file(filename);
    if (file.is_open()) {
        int product = 1;
        int value;
        while (file >> value) {
            product *= value;
        }
        file.close();
        cout << "Product of elements in the file: " << product << endl;
        return product;
    } else {
        cerr << "Unable to open file: " << filename << endl;
        return -1;
    }
}

// Крок 7
void deleteFile() {
    if (remove(filename) == 0) {
        cout << "File " << filename << " deleted successfully." << endl;
    } else {
        cerr << "Unable to delete file: " << filename << endl;
    }
}

// Головна функція
int main() {
    // Крок 1 (замість глобальної константи)
    int modified_pull_request_number = 911;

    createMatrix();
    sortMatrix(modified_pull_request_number);
    calculateSums(modified_pull_request_number * 2.5);
    bool writeResult = writeToFile();
    int productResult = calculateProductFromFile();
    deleteFile();

    return 0;
}
