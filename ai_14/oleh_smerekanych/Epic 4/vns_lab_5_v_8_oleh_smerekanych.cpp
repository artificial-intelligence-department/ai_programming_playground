#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n);
bool isSymmetric(int matrix[MAX_SIZE][MAX_SIZE], int n);

int main() {
    int n;

    cout << "Enter size of matrix: ";
    cin >> n;

    int matrix[MAX_SIZE][MAX_SIZE];

    cout << "Enter elements of matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    if (isSymmetric(matrix, n)) {
        cout << "Matrix is symmetric" << endl;
    } else {
        cout << "Matrix is not symmetric" << endl;
    }

    return 0;
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

bool isSymmetric(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    transposeMatrix(matrix, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false; 
            }
        }
    }

    return true; 
}