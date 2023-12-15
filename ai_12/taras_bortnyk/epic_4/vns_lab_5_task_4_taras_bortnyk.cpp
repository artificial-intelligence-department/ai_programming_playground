#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int rows = 2;
const int cols = 2;


double dotProduct(const double a[], const double b[], int size) {
    double result = 0.0;
    for (int i = 0; i < size; ++i) {
        result += a[i] * b[i];
    }
    return result;
}


void generateRandomMatrix(double matrix[][cols]) {
    srand((time(0)));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 2;
        }
    }
}


void printMatrix(const double matrix[][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


bool isOrthogonal(const double matrix[][cols]) {
    
    if (dotProduct(matrix[0], matrix[1], cols) != 0.0) {
        return false;
    }

    
    for (int i = 0; i < rows; ++i) {
        if (dotProduct(matrix[i], matrix[i], cols) != 1.0) {
            return false;
        }
    }

    
    return true;
}

int main() {
    
    double matrix[rows][cols];
    generateRandomMatrix(matrix);

    
    cout << "Generated Matrix:" << endl;
    printMatrix(matrix);

    
    if (isOrthogonal(matrix)) {
        cout << "The matrix is orthonormal." << endl;
    } else {
        cout << "The matrix is not orthonormal." << endl;
    }

    return 0;
}