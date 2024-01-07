#include <iostream>

using namespace std;

int main()
{
    int n, m, x, y, max = 0;

    cin >> n >> m >> x >> y;

    x--;
    y--;

    int map[n][m];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            map[i][j] = abs(x-i) + abs(y-j);

            if(max < map[i][j])
            {
                max = map[i][j];
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << max - map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
