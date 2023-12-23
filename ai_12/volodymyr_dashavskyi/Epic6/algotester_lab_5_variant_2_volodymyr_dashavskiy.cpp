#include <iostream>
#include <vector>

using namespace std;

void simulateEarthquake(vector<vector<char>> &cave, int N, int M)
{
    for (int i = N - 2; i >= 0; i--)
    {
        for (int j = 0; j < M; j++)
        {
            if (cave[i][j] == 'S' && cave[i + 1][j] == 'O')
            {
                int k = i + 1;
                while (k + 1 < N && cave[k + 1][j] == 'O')
                {
                    k++;
                }
                swap(cave[i][j], cave[k][j]);
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<char>> cave(N, vector<char>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char cell;
            cin >> cell;

            if (cell != 'O' && cell != 'X' && cell != 'S')
            {
                cerr << "Error: Invalid input. Please enter only 'O', 'X', or 'S'." << endl;
                return 0;
            }

            cave[i][j] = cell;
        }
    }

    simulateEarthquake(cave, N, M);

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
