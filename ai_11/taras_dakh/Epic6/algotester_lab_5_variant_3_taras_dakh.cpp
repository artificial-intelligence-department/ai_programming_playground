#include <iostream>
#include <vector>

using namespace std;

int computeCellValue(int size_n, int size_m, int x, int y, int i, int j) {
    int xmax = (x <= size_n / 2) ? 1 : size_n;
    int ymax = (y <= size_m / 2) ? 1 : size_m;

    int max_value = (size_n - 1) + (size_m - 1) - (abs(x - xmax) + abs(y - ymax));

    return max_value - (abs(x - (i + 1)) + abs(y - (j + 1)));
}

void printMap(const vector<vector<int>>& map) {
    for (const auto& row : map) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << "\n";
    }
}

int main() {
    while (true) {
        int size_n, size_m, x, y;
        cin >> size_n >> size_m >> x >> y;

        vector<vector<int>> map(size_n, vector<int>(size_m, 0));

        for (int i = 0; i < size_n; i++) {
            for (int j = 0; j < size_m; j++) {
                map[i][j] = computeCellValue(size_n, size_m, x, y, i, j);
            }
        }

        printMap(map);

        char answer;
        cin >> answer;
        if (answer != 'y') {
            break;
        }
    }

    return 0;
}
