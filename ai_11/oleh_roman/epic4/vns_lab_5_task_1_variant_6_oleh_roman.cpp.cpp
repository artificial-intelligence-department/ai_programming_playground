#include <iostream>

using namespace std;
const int MAX_ROWS = 3;
const int MAX_COLS = 3;

void findSaddlePoints(int matrix[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            int element = matrix[i][j];
            bool MaxColsMinRow = true;
            bool MinColsMaxRow = true;
            for (int k = 0; k < MAX_COLS; k++) {
                if (element > matrix[i][k]) {
                    MaxColsMinRow = false;
                    break;
                }
            }
            for (int k = 0; k < MAX_COLS; k++) {
                if (element < matrix[i][k]) {
                    MinColsMaxRow = false;
                    break;
                }
            }
            for (int k = 0; k < MAX_ROWS; k++) {
                if (element < matrix[k][j]) {
                    MaxColsMinRow = false;
                    break;
                }
            }
            for (int k = 0; k < MAX_ROWS; k++) {
                if (element > matrix[k][j]) {
                    MinColsMaxRow = false;
                    break;
                }
            }

            if (MaxColsMinRow) {
                cout << "Saddle Point at (" << i + 1 << ", " << j + 1 << "): " << element << endl;
            }
            if (MinColsMaxRow) {
                cout << "Saddle Point at (" << i + 1 << ", " << j + 1 << "): " << element << endl;
            }
        }
    }
}

int main() {
    int matrix[MAX_ROWS][MAX_COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    findSaddlePoints(matrix);

    return 0;
}
