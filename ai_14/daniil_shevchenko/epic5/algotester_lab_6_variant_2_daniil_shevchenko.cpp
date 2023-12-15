#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string board[20];
    for (int i = 0; i < 8; i++)
    {
        getline(cin, board[i]);

    }
    for (int i = 0; i < 20; i++)
    {
        board[i].resize(20);
    }
    int Q;
    cin >> Q;
    for (int m = 0; m < Q; m++)
    {
        int a;
        int b;
        cin >> a >> b;
        int x = a - 1;
        int y = b - 1;
        string answer;
        answer.resize(15);
        int k = 0;
        if (board[x][y] != 'O')
        {
            cout << 'X';
        }
        else
        {
            //пішка(P)
            bool pishka = false;
            if (((y > 0 && x > 0) && (board[x - 1][y - 1] == 'P')) || (x > 0 && (board[x - 1][y + 1] == 'P')))
            {
                pishka = true;

            }
            if (pishka)
            {
                answer[k] = 'P';
                k++;

            }
            //тура(R)
            bool tura = false;
            for (int f = 0; f < 8; f++)
            {
                if (board[x][f] == 'R' || board[f][y] == 'R')
                {
                    tura = true;
                }
            }
            if (tura)
            {
                answer[k] = 'R';
                k++;

            }
            //кінь(N)
            bool horse = false;
            if (y > 0 && (board[x + 2][y - 1] == 'N') || (board[x + 2][y + 1] == 'N')
                || ((x > 1 && y > 0) && (board[x - 2][y - 1] == 'N'))
                || (x > 1 && board[x - 2][y + 1] == 'N') || (y > 1 && board[x + 1][y - 2] == 'N')
                || (board[x + 1][y + 2] == 'N') || ((x > 0 && y > 1) && board[x - 1][y - 2] == 'N')
                || (x > 0 && board[x - 1][y + 2] == 'N'))
            {
                horse = true;
            }
            if (horse)
            {
                answer[k] = 'N';
                k++;

            }
            //офіцер(B)
            bool oficer = false;
            for (int f = 0; f < 8; f++)
            {
                if (board[x + f][y + f] == 'B' || (y >= f && board[x + f][y - f] == 'B') || (x >= f && board[x - f][y + f] == 'B') || ((x >= f && y >= f) && board[x - f][y - f] == 'B'))
                {
                    oficer = true;
                }
            }
            if (oficer)
            {
                answer[k] = 'B';
                k++;

            }
            //король(K)
            bool king = false;
            if ((board[x + 1][y + 1] == 'K') || (board[x + 1][y] == 'K') ||
                (y > 0 && board[x + 1][y - 1] == 'K') || (board[x][y + 1] == 'K') ||
                (y > 0 && board[x][y - 1] == 'K') || (x > 0 && board[x - 1][y + 1] == 'K') ||
                (x > 0 && board[x - 1][y] == 'K') || ((x > 0 && y > 0) && board[x - 1][y - 1] == 'K'))
            {
                king = true;
            }
            if (king)
            {
                answer[k] = 'K';
                k++;

            }
            //королева(Q)
            bool queen = false;
            for (int u = 0; u < 8; u++)
                if ((board[x + u][y + u] == 'Q') || (y >= u && board[x + u][y - u] == 'Q') || (x >= u && board[x - u][y + u] == 'Q') || ((x >= u && y >= u) && board[x - u][y - u] == 'Q') || (board[x][u] == 'Q') || (board[u][y] == 'Q'))
                {
                    queen = true;
                }
            if (queen)
            {
                answer[k] = 'Q';
                k++;
            }
        }
        if (k == 0 && board[x][y] == 'O')
        {
            cout << 'O';
        }
        else
        {
            answer.resize(k);
            sort(answer.begin(), answer.end());
            cout << answer;
        }
        cout << endl;
    }
}

