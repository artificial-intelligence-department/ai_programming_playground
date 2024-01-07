#include <iostream>
using namespace std;
const int NUM_ROWS = 6;
const int NUM_COLS = 4;
int** deleteRow(int** matrix, int rowToDelete) {
    if (rowToDelete < 0 || rowToDelete >= NUM_ROWS) {
        cout << "Invalid row index\n";
        return matrix; 
    }

    for (int i = rowToDelete; i < NUM_ROWS - 1; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
            matrix[i][j] = matrix[i + 1][j];
        }
    }

    for (int j = 0; j < NUM_COLS; ++j) {
        matrix[NUM_ROWS - 1][j] = 0;
    }

    return matrix;
}
int** deleteRowsInRange(int** matrix, int A, int B) {
    for (int i = A; i <= B; ++i) {
        matrix = deleteRow(matrix, A);
    }
    return matrix;
}
void printMatrix(int** matrix) {
    for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
            cout << matrix[i][j] << '\t';
        }
        cout << '\n';
    }
}
int main() {
    int A = 1, B = 3;
    if (A > B) {
        return 1;
    }
    int** matrix = new int*[NUM_ROWS];
    for (int i = 0; i < NUM_ROWS; ++i)
        matrix[i] = new int[NUM_COLS];

    int s = 0;
    for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
            matrix[i][j] = ++s;
        }
    }
    cout << "Initial matrix:\n";
    printMatrix(matrix);
    cout << "Delete " << A << "-" << B << " rows" << endl;
    matrix = deleteRowsInRange(matrix, A, B);
    cout << "Result matrix:\n";
    printMatrix(matrix);
    for (int i = 0; i < NUM_ROWS; ++i)
        delete[] matrix[i];
    delete[] matrix;
    return 0;
}
