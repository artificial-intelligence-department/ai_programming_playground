#include <iostream>
#include <algorithm>

using namespace std;

bool checkOrder(const int* sequence, int size) {
    return is_sorted(sequence, sequence + size);
}

void sortSequence(int* sequence, int size) {
    sort(sequence, sequence + size);
}

int main() { 
    const int ROWS = 3;
    const int COLS = 5;
    int matrix[ROWS][COLS] = {
        {3, 5, 7, 9, 11},
        {6, 4, 2, 0, -2},
        {1, 4, 3, 4, 5}
    };

    for (int i = 0; i < ROWS; ++i) {
        if (!checkOrder(matrix[i], COLS)) {
            sortSequence(matrix[i], COLS);
        }
    }

    cout << "Sorted two-dimensional array:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
