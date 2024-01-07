#include <iostream>

using namespace std;

int main() {
    int n, m, y;
    cin >> n >> m; 
    char board[n][m];
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--) 
        {
            int k = j;
            while (board[k][i] == 'S' && k + 1 < n && board[k + 1][i] == 'O') 
            {
                board[k + 1][i] = 'S';
                board[k][i] = 'O';
                k++;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }

    return 0;
}
