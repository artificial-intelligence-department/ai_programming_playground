#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const int n = 3;
    const int m = 4;
    int  x, y, i, j, k;
    cin >> x >> y;
    int a[n][m];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = 0;
        }
    }
    k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (abs(i - (x - 1)) + abs(j - (y - 1)) > k) {
                k = abs(i - (x - 1)) + abs(j - (y - 1));
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = k - (abs(i - (x - 1)) + abs(j - (y - 1)));
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}