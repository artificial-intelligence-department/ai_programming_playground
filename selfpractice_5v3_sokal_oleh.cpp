#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n, m, max1, max2, max3, max4;
    int point, OldX, x, y;

    cin >> n >> m;
    cin >> x >> y;

    vector<vector<int>> arr(n, vector<int>(m, 0));

    point = (x - 1) * m + (y - 1);
    max1 = abs(x - 1) + abs(y - 1);
    max2 = abs(x - 1) + abs(y - m);
    max3 = abs(x - n) + abs(y - 1);
    max4 = abs(x - n) + abs(y - m);

    int max_val = max1;

    if (max2 > max_val) {
        max_val = max2;
    }

    if (max3 > max_val) {
        max_val = max3;
    }

    if (max4 > max_val) {
        max_val = max4;
    }

    arr[x - 1][y - 1] = max_val;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == x && j == y) continue;
            int dist = abs(x - i) + abs(y - j);
            arr[i - 1][j - 1] = max_val - dist;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

