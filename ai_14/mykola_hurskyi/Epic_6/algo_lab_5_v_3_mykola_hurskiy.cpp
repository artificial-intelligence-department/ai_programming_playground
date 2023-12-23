#include <iostream>
#include <algorithm>

using namespace std;

void calculateAndPrintMatrix(int rows, int cols, int inputRow, int inputCol) {
    int peakRow = inputRow - 1;
    int peakCol = inputCol - 1;

    int resultMatrix[rows][cols];

    int maxHeight = max({(cols - inputCol) + (rows - inputRow), (cols - inputCol) + peakRow, peakRow + peakCol, peakCol + (rows - inputRow)});

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            resultMatrix[i][j] = maxHeight - abs(inputRow - 1 - i) - abs(inputCol - 1 - j);
            cout << resultMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    int inputRow, inputCol;

    cin >> rows >> cols;
    cin >> inputRow >> inputCol;

    calculateAndPrintMatrix(rows, cols, inputRow, inputCol);

    return 0;
}
