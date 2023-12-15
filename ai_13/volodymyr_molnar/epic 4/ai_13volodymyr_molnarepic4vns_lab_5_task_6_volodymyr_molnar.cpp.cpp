#include <iostream>
#include <vector>

using namespace std;

void findSaddlePoints(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int current = matrix[i][j];

            bool isSaddlePoint = true;
            for (int k = 0; k < cols; ++k)
                if (current > matrix[i][k]) {
                    isSaddlePoint = false;
                    break;
                }
            for (int k = 0; k < rows; ++k)
                if (current < matrix[k][j]) {
                    isSaddlePoint = false;
                    break;
                }
            if (isSaddlePoint)
                cout << "Saddle Point at (" << i << ", " << j << "): " << current << endl;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {6, 4, 6},
        {5, 2, 5},
        {0, 1, 7}
    };
    findSaddlePoints(matrix);

    return 0;
}
