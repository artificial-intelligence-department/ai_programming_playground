#include <iostream>
#include <vector>

using namespace std;

void destroyRow(vector<vector<int>>& matrix, int rowIndex) {
    if (rowIndex >= 0 && rowIndex < matrix.size()) {
        matrix.erase(matrix.begin() + rowIndex);
        matrix.push_back(vector<int>(matrix[0].size(), 0));
    }
}

void destroyRowsRange(vector<vector<int>>& matrix, int startRow, int endRow) {
    for (int i = startRow; i <= endRow; ++i) {
        destroyRow(matrix, i);
    }
}

int main() {
    vector<vector<int>> myMatrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    destroyRowsRange(myMatrix, 1, 2);

    for (const auto& row : myMatrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
