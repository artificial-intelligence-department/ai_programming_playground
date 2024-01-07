#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    int map[n][m];

    int maxY = (y > m - y) ? y - 1 : m - y;
    int maxX = (x > n - x) ? x - 1 : n - x;

    int peak = maxX + maxY;

    y--;
    x--;
    map[x][y] = peak;

    for (int i = 0; i <= maxX; i++)
    {
        for (int j = 0; j <= maxY; j++)
        {
            if (x - i >= 0 && x - i < n && y - j >= 0 && y - j < m)
                map[x - i][y - j] = peak - i - j;
            if (x + i >= 0 && x + i < n && y + j >= 0 && y + j < m)
                map[x + i][y + j] = peak - i - j;
            if (x + i >= 0 && x + i < n && y - j >= 0 && y - j < m)
                map[x + i][y - j] = peak - i - j;
            if (x - i >= 0 && x - i < n && y + j >= 0 && y + j < m)
                map[x - i][y + j] = peak - i - j;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}