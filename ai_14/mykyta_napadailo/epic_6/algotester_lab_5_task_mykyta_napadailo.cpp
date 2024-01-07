#include <iostream>
using namespace std;

void swap(char &a, char &b)
{
    char tmp = a;
    a = b;
    b = tmp;
}

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
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = 0; j < M; j++)
        {
            if (cave[i][j] == 'S')
            {
                int t = i;
                while (t + 1 < N && cave[t + 1][j] == 'O')
                {
                    swap(cave[t][j], cave[t + 1][j]);
                    t++;
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << cave[i][j];
        }
        cout << endl;
    }
}