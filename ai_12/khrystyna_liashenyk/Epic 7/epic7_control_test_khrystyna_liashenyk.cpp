#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;
const int MY_CONSTANT = 920;
const string FILENAME = "output.txt";

// Функція для створення матриці розміром 10x10
float** createMatrix() {
    float** matrix = new float*[10];
    for (int i = 0; i < 10; ++i) {
        matrix[i] = new float[10];
        for (int j = 0; j < 10; ++j) {
            if (MY_CONSTANT % 2 == 0) {
                matrix[i][j] = sin(MY_CONSTANT) * (i + 1) * (j + 1); /*математична функція */;
            } 
        }
    }
    return matrix;
}

// Функція сортування стовпців матриці по зростанню
void sortColumns(float** matrix) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k < 10 - j - 1; ++k) {
                if (matrix[k][i] > matrix[k + 1][i]) {
                    swap(matrix[k][i], matrix[k + 1][i]);
                }
            }
        }
    }
}

// Функція для обчислення сум та створення нового статичного масиву
int* calculateSums(float** matrix) {
    int* sums = new int[10];
    srand(time(0));

    for (int i = 0; i < 10; ++i) {
        int sum = 0;
        for (int j = 0; j < 3; ++j) {
            int randomRow = rand() % 10;
            sum += static_cast<int>(matrix[randomRow][i]);
        }
        sums[i] = sum;
    }
    return sums;
}

// Функція для запису значень статичного масиву у файл
bool writeToFile(int* array) {
    ofstream file(FILENAME);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return false;
    }

    for (int i = 0; i < 10; ++i) {
        file << array[i] << " ";
    }
    file.close();
    return true;
}

// Функція для обчислення добутку елементів у файлі та видалення файлу
int calculateProductFromFile() {
    ifstream file(FILENAME);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return -1;
    }

    int product = 1;
    int value;
    while (file >> value) {
        product *= value;
    }
    file.close();

    cout << "Product of values in file: " << product << endl;
    return product;
}

// Функція для видалення файлу
bool deleteFile() {
    if (remove(FILENAME.c_str()) != 0) {
        cerr << "Error deleting file." << endl;
        return false;
    }

    cout << "File " << FILENAME << " deleted successfully." << endl;
    return true;
}

int main() {
    cout << "Step 1: Creating matrix..." << endl;
    float** matrix = createMatrix();

    cout << "Matrix:" << endl;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Step 2: Sorting columns..." << endl;
    sortColumns(matrix);

    cout << "Sorted Matrix:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Step 3: Calculating sums..." << endl;
    int* sums = calculateSums(matrix);

    cout << "Sums:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << sums[i] << " ";
    }
    cout << endl;

    cout << "Step 4: Writing sums to file..." << endl;
    bool writeSuccess = writeToFile(sums);

    int product = calculateProductFromFile();
    deleteFile();

    // Очищення пам'яті для матриці та статичного масиву
    for (int i = 0; i < 10; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] sums;

    return 0;
}
