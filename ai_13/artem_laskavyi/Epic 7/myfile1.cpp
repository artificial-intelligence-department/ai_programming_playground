#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;

const int rows = 10;
const int cols = 10;

void bubbleSort(int arr[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void bubbleSort(float arr[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void sortMatrixByColumn(float matrix[][cols], int rows, int colIndex) {
    sort(matrix[0] + colIndex, matrix[0] + colIndex + rows);
}

void sortMatrix(float matrix[][cols], int rows, int cols) {
    for (int i = 0; i < cols; ++i) {
        sortMatrixByColumn(matrix, rows, i);
    }
}

void sortMatrixByColumn(int matrix[][cols], int rows, int colIndex) {
    sort(matrix[0] + colIndex, matrix[0] + colIndex + rows);
}

void sortMatrix(int matrix[][cols], int rows, int cols) {
    for (int i = 0; i < cols; ++i) {
        sortMatrixByColumn(matrix, rows, i);
    }
}

void matcr(float matrix[][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = pow(i, j / 10.0);
        }
    }
}

void matcr(int matrix[][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = pow(i, j / 10.0);
        }
    }
}

int* calculateSums(float matrix[][cols], int rows, int cols) {
    static int result[cols];

    for (int i = 0; i < cols; ++i) {
        float sum = 0.0;

        for (int j = 0; j < min(4, rows); ++j) {
            sum += matrix[j][i];
        }

        result[i] = static_cast<int>(sum);
    }

    return result;
}

void writeArrayToFile(const int* array, int size, const string& filename) {
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        outFile << array[i] << "\t";
    }

    outFile.close();
}

int main() {

    const int C = 1008;

    if (C % 2 == 0) {
        int arr[rows][cols];
        matcr(arr);
        sortMatrix(arr, rows, cols);
        calculateSums(arr, rows, cols);
    } else {
        float arr[rows][cols];
        matcr(arr);
        sortMatrix(arr, rows, cols);
        calculateSums(arr, rows, cols);
    }

    return 0;
}
