#include <iostream>

using namespace std;

int countElementsGreaterThanSelected(const int matrix[3][3], int selectedRowIndex) {
    int selectedColIndex = selectedRowIndex;
    int selectedElement = matrix[selectedRowIndex][selectedColIndex];
    int count = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (matrix[i][j] > selectedElement) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int matrix[3][3];

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "Enter a value for the element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    int selectedRowIndex;
    cout << "Enter the row index of the selected element of the main diagonal (from 0 to 2): ";
    cin >> selectedRowIndex;

    if (selectedRowIndex < 0 || selectedRowIndex >= 3) {
        cerr << "Incorrect index of the row" << endl;
        return 1;
    }

    int result = countElementsGreaterThanSelected(matrix, selectedRowIndex);
    cout << "Number of elements that are bigger than selected element: " << result << endl;

    return 0;
}
