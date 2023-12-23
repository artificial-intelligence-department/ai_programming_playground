#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

const int SIZE = 10;
const int PR_NUMBER = 928; // в коді використана як мінімум одна цілочисельна константа

bool writeArrayToFile(const int arr[SIZE], const string& filename);
unsigned long long calculateProductFromFile(const string& filename);


void createMatrix(double arr[][SIZE]) {
    // 1 в коді використана як мінімум одна цілочисельна змінна
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            arr[i][j] = pow(i + 1, 1.1) - j; 
            // 15 в коді використано математичні операції та математичні функції
        }
    }
}

// Функція для сортування стовпців матриці методом бульбашки
void bubbleSortColumns(double arr[][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE - i - 1; j++) {
                if (arr[j][col] > arr[j + 1][col]) {
                    swap(arr[j][col], arr[j + 1][col]);  // в коді використані умовні оператори та розгалуження
                }
            }
        }
    }
}


void calculateSums(const double arr[][SIZE], int sums[SIZE]) {
    srand(time(0));
    // 10 в коді використаний for цикл 
    for (int col = 0; col < SIZE; col++) {
        double sum = 0.0;
        for (int k = 0; k < 3; k++) { 
            sum += arr[rand() % SIZE][col];
        }
        sums[col] = static_cast<int>(sum); 
    }
}
bool deleteFile(const string& filename) {
    if (remove(filename.c_str()) == 0) {
        cout << "File deleted: " << filename << endl;
        return true;
    } else {
        cerr << "Error deleting file: " << filename << endl;
        return false;
    }
}

int main() {
    //6 в коді використаний одновимірний масив 
    //7 в коді використаний двовимірний масив 
    double matrix[SIZE][SIZE];
    int sums[SIZE];

    createMatrix(matrix);
    bubbleSortColumns(matrix);

    calculateSums(matrix, sums);
    const string FileName = "sums.txt";
    if (writeArrayToFile(sums, FileName)) {
        cout << "Sums were successfully written to file." << endl;
    } else {
        cout << "Error writing sums to file." << endl;
    }
    calculateProductFromFile(FileName);
    deleteFile(FileName);

    return 0;
}

bool writeArrayToFile(const int arr[SIZE], const string& filename) {
    ofstream file(filename);
    // 16 в коді використано функції роботи з файлами, для того, щоб записати у файл
    if (!file.is_open()) {
        cerr << "Eror opening file";
        return false;
    }

    for (int i = 0; i < SIZE; i++) {
        file << arr[i] << endl;
    }

    file.close();
    return true;
}
unsigned long long calculateProductFromFile(const string& filename) {
    ifstream file("sums.txt");
    if (!file) {
        cerr << "Unable to open file" << endl;
        return -1;
    }

    int value;
    unsigned long long product = 1;
    while (file >> value) {
        product *= value;
    }

    cout << "Product of elements in file: " << product << endl;
    return product;
}