#include <iostream>

using namespace std;

const int rows = 4;
const int cols = 4;

void printMatrix(int matrix[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
       cout << endl;
    }
}
void deleteRow(int matrix[rows][cols], int rowIndex) {
    for (int j = 0; j < cols; ++j) {
        matrix[rowIndex][j] = 0;
    }
}
void deleteRowsInRange(int matrix[rows][cols], int A, int B) {
    for (int i = A; i <= B; ++i) {
        deleteRow(matrix, i);
    }
}
int main() {
    int matrix[rows][cols] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    cout << "Matrix:" << endl;
    printMatrix(matrix);

    int A, B;
    cout << "Enter the A: ";
    cin >> A;
    cout << "Enter the B: ";
    cin >> B;
    deleteRowsInRange(matrix, A, B);
    cout << "\nMatrix after deleting rows from A to B:" << endl;
    printMatrix(matrix);

    return 0;
}