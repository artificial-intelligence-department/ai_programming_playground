#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int peak_row, peak_col;
    cin >> peak_row >> peak_col;

    int** heights = new int*[rows];

    for (int i = 0; i < rows; i++) {
        heights[i] = new int[cols]();
    }

    int min_height = -abs(peak_row - 1) - abs(peak_col - 1);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            heights[i][j] = -abs(peak_row - 1 - i) - abs(peak_col - 1 - j);
            if (min_height > heights[i][j]) {
                min_height = heights[i][j];
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            heights[i][j] -= min_height;
            cout << heights[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] heights[i];
    }
    delete[] heights;

    return 0;
}
