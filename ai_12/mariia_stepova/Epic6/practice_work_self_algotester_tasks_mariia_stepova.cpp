#include <iostream>

void multiplyMatrices(int** A, int** B, int** C, int n, int m, int q) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < q; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < m; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    using namespace std;

    int n, m, q;
    cout << "Введіть розмірність матриці A (n m): ";
    cin >> n >> m;

    cout << "Введіть розмірність матриці B (m q): ";
    cin >> m >> q;

    int** A = new int*[n];
    int** B = new int*[m];
    int** C = new int*[n];

    for (int i = 0; i < n; ++i) {
        A[i] = new int[m];
        C[i] = new int[q];
        for (int j = 0; j < m; ++j) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        B[i] = new int[q];
        for (int j = 0; j < q; ++j) {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }

    multiplyMatrices(A, B, C, n, m, q);

    cout << "Матриця A:" << endl;
    printMatrix(A, n, m);

    cout << "Матриця B:" << endl;
    printMatrix(B, m, q);

    cout << "Результат множення матриць A та B:" << endl;
    printMatrix(C, n, q);

    // Звільнення пам'яті
    for (int i = 0; i < n; ++i) {
        delete[] A[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}