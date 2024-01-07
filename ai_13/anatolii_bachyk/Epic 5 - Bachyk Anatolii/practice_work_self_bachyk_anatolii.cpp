#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    // Зчитуємо матрицю
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x1, y1, x2, y2, h, w;
            cin >> x1 >> y1 >> x2 >> y2 >> h >> w;

            // Поміняти місцями підматриці
            vector<vector<int>> temp(h, vector<int>(w));
            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) {
                    temp[i][j] = matrix[x1 + i - 1][y1 + j - 1];
                    matrix[x1 + i - 1][y1 + j - 1] = matrix[x2 + i - 1][y2 + j - 1];
                    matrix[x2 + i - 1][y2 + j - 1] = temp[i][j];
                }
            }
        } else if (t == 2) {
            int x, y;
            cin >> x >> y;

            // Вивести значення a[x][y]
            cout << matrix[x - 1][y - 1] << endl;
        }
    }

    return 0;
}