#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    char cave[N][M];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> cave[i][j];
        }
    }

    int count = 0;
    do
    {
        count = 0;

        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = 0; j < M; j++)
            {
                if (cave[i][j] == 'S')
                {
                    if (i < N - 1 && cave[i + 1][j] == 'O' && cave[i + 1][j] != 'X')
                    {
                        cave[i][j] = 'O';
                        cave[i + 1][j] = 'S';
                        count++;
                    }
                }
            }
        }

    } while (count != 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << cave[i][j];
        }
        cout << endl;
    }

    return 0;
}
