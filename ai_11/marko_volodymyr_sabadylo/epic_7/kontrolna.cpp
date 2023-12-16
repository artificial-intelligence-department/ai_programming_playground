#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int CONSTANT = 979;
const char FILENAME[] = "output.txt";

void GenerateMatrix(float matrix[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = static_cast<float>(CONSTANT / 2 + i * j);
        }
    }
}

void GenerateMatrix(int matrix[10][10]) {
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = CONSTANT * (i + 1) * (j + 1);
        }
    }
}

void SortMatrix(float matrix[10][10], float value) {
    // Bubble sort columns
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 9; i++) {
            if (matrix[i][j] > matrix[i + 1][j]) {
                for (int k = 0; k < 10; k++) {
                    swap(matrix[i][k], matrix[i + 1][k]);
                }
            }
        }
    }
}

void SortMatrix(int matrix[10][10], int value) {
    // Bubble sort rows
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (matrix[i][j] < matrix[i][j + 1]) {
                for (int k = 0; k < 10; k++) {
                    swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }
}

int* CalculateSums(int matrix[10][10], float multiplier) {
    static int sums[10];
    srand(static_cast<unsigned>(time(nullptr)));

    for (int j = 0; j < 10; j++) {
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            int randomindex = rand() % 10;
            sum += matrix[randomindex][j];
        }

        sums[j] = static_cast<int>(sum * multiplier);
    }
    return sums;
}

bool SaveSumsToFile(int sums[10]) {
    ofstream file(FILENAME);
    if (file.is_open()) {
        for (int i = 0; i < 10; i++) {
            file << sums[i] << " ";
        }
        file.close();
        return true;
    }
    return false;
}

int CalculateProductFromFile() {
    int product = 1;
    ifstream file(FILENAME);
    if (file.is_open()) {
        int value;
        while (file >> value) {
            product *= value;
        }
        file.close();
    }
    return product;
}

void DeleteFile() {
    if (remove(FILENAME) == 0) {
        cout << "File deleted successfully.\n";
    } else {
        cout << "Error deleting the file.\n";
    }
}

int main() {
    float floatMatrix[10][10];
    int intMatrix[10][10];

    GenerateMatrix(floatMatrix);
    SortMatrix(floatMatrix, 1.0);

    GenerateMatrix(intMatrix);
    SortMatrix(intMatrix, 1);

    int* sumsFloat = CalculateSums(floatMatrix, 2.5);
    SaveSumsToFile(sumsFloat);

    int* sumsInt = CalculateSums(intMatrix, 1.0);
    SaveSumsToFile(sumsInt);

    int product = CalculateProductFromFile();
    cout << "Product of sums from file: " << product << "\n";

    DeleteFile();

    return 0;
}