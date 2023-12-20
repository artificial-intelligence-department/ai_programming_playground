#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculate(int i, int j, int x, int y) {
    return abs(i - x) + abs(j - y);
}

int main() {
    int N, M, x, y;
    std::cin >> N >> M >> x >> y;
    --x;
    --y;

    vector<vector<int>> map(N, vector<int>(M, 0));

    for (auto& row : map) {
        for (int& val : row) {
            val = calculate(&row - &map[0], &val - &row[0], x, y);
        }
    }

    int peak = 0;
    for (const auto& row : map) {
        for (const int& val : row) {
            peak = max(peak, val);
        }
    }

    for (const auto& row : map) {
        for (const int& val : row) {
            cout << peak - val << ' ';
        }
        cout << endl;
    }

    return 0;
}
