#include <iostream>
using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    int map[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            map[i][j] = 0;
        }
    }

    int maxX;
    if(x > n-x)
    {
        maxX = x-1;
    } else {
        maxX = n-x;
    }

    int maxY;
    if(y > m-y)
    {
        maxY = y-1;
    } else {
        maxY = m-y;
    }

    int max = maxX + maxY;
    x--;
    y--;


    map[x][y] = max;

    int elem = max;
    for(int i=1; i<m; i++)
    {
        elem--;

        if(y+i < m)
        {
            map[x][y+i] = elem;
        }
        if(y-i >= 0)
        {
            map[x][y-i] = elem;
        }
    }

    for(int i=0; i<m; i++)
    {
        elem = map[x][i];
        for(int j=1; j<n; j++)
        {
            elem--;

            if(x+j < n)
            {
                map[x+j][i] = elem;
            }
            if(x-j >= 0)
            {
                map[x-j][i] = elem;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}
