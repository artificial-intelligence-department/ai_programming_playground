#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N, M, x, y;
    cin >> N >> M >> x >> y;

    vector<vector<int>> matrix(N, vector<int>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            matrix[i][j] = abs(i - (x - 1)) + abs(j - (y - 1));
        }
    }

    int max_val = *max_element(matrix[0].begin(), matrix[0].end());
    for (const auto &row : matrix) {
        max_val = max(max_val, *max_element(row.begin(), row.end()));
    }

    for (const auto &row : matrix) {
        for (const auto &element : row) {
            cout << abs(element - max_val) << " ";
        }
        cout << endl;
    }

    return 0;
}

