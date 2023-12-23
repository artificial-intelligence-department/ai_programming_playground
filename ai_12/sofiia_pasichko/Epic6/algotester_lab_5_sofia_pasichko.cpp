#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void setHeight(int x, int y, int N, int M, vector<vector<int>>& peak) {
    int maxHeight = 0;
    x--;
    y--;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            peak[i][j] = abs(x - i) + abs(y - j);
            maxHeight = max(maxHeight, peak[i][j]);
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            peak[i][j] = maxHeight - peak[i][j];
        }
    }
}

int main() {
    int N, M, x, y;
    cin >> N >> M;
    cin >> x >> y;

    vector<vector<int>> peak(N, vector<int>(M, 0));

    setHeight(x, y, N, M, peak);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << peak[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}