#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N, M, x, y;
    cin >> N >> M >> x >> y;

    int map[N][M];
    x -= 1;
    y -= 1;

    int peak_height = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int distance = abs(i - x) + abs(j - y);
            map[i][j] = distance;
            if (distance > peak_height)
            {
                peak_height = distance;
            }
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cout << peak_height - map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}