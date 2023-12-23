#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N, M, x, y, diff = 0, min = 0;
    cin >> N >> M;
    cin >> x >> y;
    int mountain[N][M];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            mountain[i][j] = 0 - (abs(i - (x - 1)) + abs(j - (y - 1)));

            if (mountain[i][j] < min)
            {
                min = mountain[i][j];
                diff = 0 - min;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cout << mountain[i][j] + diff << " ";
        }
        cout << endl;
    }

    return 0;
}