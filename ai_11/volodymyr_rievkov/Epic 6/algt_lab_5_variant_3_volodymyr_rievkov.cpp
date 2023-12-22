#include <iostream>
#include <algorithm>
using namespace std;

const int border = 1000;

bool check_number(int number, int border)
{
    return(number >= 1 && number <= border);
}

int main(){
    int N, M, x, y;
    cin >> N >> M;
    if(!check_number(N, border) || !check_number(M, border))
    {
        return 0;
    }
    cin >> x >> y;
    if(!check_number(x, N) || !check_number(y, M))
    {
        return 0;
    }
    int matrix[N][M];
    int max_value = max(x - 1, N - x) + max(y - 1, M - y);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = x - 1; i < N; i++)
    {
        for (int j = y - 1; j < M; j++)
        {
            matrix[i][j] = max_value - (j - (y - 1)) - (i - (x - 1));
        }
    }

    for (int i = x - 1; i >= 0; i--)
    {
        for (int j = y - 1; j < M; j++)
        {
            matrix[i][j] = max_value - (j - (y - 1)) - (x - 1 - i);
        }
    }

    for (int i = x - 1; i >= 0; i--)
    {
        for (int j = y - 1; j >= 0; j--)
        {
            matrix[i][j] = max_value - (y - 1 - j) - (x - 1 - i);
        }
    }

    for (int i =  x - 1; i < N; i++)
    {
        for (int j = y - 1; j >= 0; j--)
        {
            matrix[i][j] = max_value - (y - 1 - j) - (i - (x - 1));
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}