#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> field(n, vector<int>(m, 0));

    int x, y;
    cin >> x >> y;

    int max_x = (x > n - x) ? x - 1 : n - x,
        max_y = (y > m - y) ? y - 1 : m - y;

    int max_h = max_x + max_y;

    field[--x][--y] = max_h;


    for(int i = 0; i <= max_x; i++) {
        for (int j = 0; j <= max_y; j++) {

            if (x - i >= 0 && x - i < n && y - j >= 0 && y - j < m)
                field[x - i][y - j] = max_h - i - j;

            if (x - i >= 0 && x - i < n && y + j >= 0 && y + j < m)
                field[x - i][y + j] = max_h - i - j;

            if (x + i >= 0 && x + i < n && y - j >= 0 && y - j < m)
                field[x + i][y - j] = max_h - i - j;

            if (x + i >= 0 && x + i < n && y + j >= 0 && y + j < m)
                field[x + i][y + j] = max_h - i - j;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
