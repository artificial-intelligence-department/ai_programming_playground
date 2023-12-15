#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

void findMaxSum(int** M, int rows, int cols);

int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    
    cout << "Enter the number of columns: ";
    cin >> cols;
    
    cout << "Enter Matrix: ";
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "Array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }

    findMaxSum(matrix, rows, cols);

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}


void findMaxSum(int** M, int rows, int cols) {
    if (rows < 3 || cols < 3) {
        cout << "The matrix is smaller than 3x3." << endl;
        return;
    }

    int maxSum = INT_MIN;
    int finalLeft, finalRight, finalTop, finalBottom;

    for (int top = 0; top <= rows - 3; ++top) { // rows - 3 and cols-3 to ensure matrix is never smaller than 3x3
        for (int left = 0; left <= cols - 3; ++left) {
            int sum = 0; // Initialize sum for each 3x3 submatrix

            for (int i = top; i < top + 3; ++i) {
                for (int j = left; j < left + 3; ++j) {
                    sum += M[i][j];
                }
            }

            // Compare the sum with the maximum sum so far
            if (sum > maxSum) {
                maxSum = sum;
                finalTop = top;
                finalBottom = top + 2;  // 3 rows
                finalLeft = left;
                finalRight = left + 2;  // 3 columns
            }
        }
    }

    cout << "\nMax sum is: " << maxSum << endl;

    cout << "\nMaximum sum subarray:" << endl;
    for (int i = finalTop; i <= finalBottom; ++i) {
        for (int j = finalLeft; j <= finalRight; ++j) {
            cout << setw(4) << M[i][j] << " ";
        }
        cout << endl;
    }
}
