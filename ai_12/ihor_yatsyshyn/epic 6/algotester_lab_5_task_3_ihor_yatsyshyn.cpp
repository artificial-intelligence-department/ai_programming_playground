#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
    int n, m, x, y;

    cin >> n >> m;
    cin >> x >> y;

    int mountain[n][m];
    int peak = max(x - 1, n - x) + max(y - 1, m - y);

    x--;
    y--;

    mountain[x][y] = peak;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (x - i >= 0 && x - i < n && y - j >= 0 && y - j < m)
            {
                mountain[x - i][y - j] = max(0, peak - (i + j));
            }

            if (x + i >= 0 && x + i < n && y + j >= 0 && y + j < m)
            {
                mountain[x + i][y + j] = max(0, peak - (i + j));
            }

            if (x - i >= 0 && x - i < n && y + j >= 0 && y + j < m)
            {
                mountain[x - i][y + j] = max(0, peak - (i + j));
            }

            if (x + i >= 0 && x + i < n && y - j >= 0 && y - j < m)
            {
                mountain[x + i][y - j] = max(0, peak - (i + j));
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mountain[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
