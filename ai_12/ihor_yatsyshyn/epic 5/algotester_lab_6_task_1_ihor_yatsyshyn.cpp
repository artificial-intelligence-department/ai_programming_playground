#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<char> attacks(char board[8][8], int x, int y);

int main()
{
    char board[8][8];
    int Q;

    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++) 
        {
            cin >> board[i][j];
        }
    }

    cin >> Q;

    vector<pair<int, int>> coordinates;

    for (int i = 0; i < Q; i++) 
    {
        int x, y;
        cin >> x >> y;
        coordinates.push_back({x, y});
    }

    for (int i = 0; i < Q; i++)
    {
        int x = coordinates[i].first;
        int y = coordinates[i].second;

        vector<char> figures = attacks(board, x, y);

        sort(figures.begin(), figures.end());
        if (board[x - 1][y - 1] != 'O')
        {
            cout << "X";
        } 
        else if (figures.empty())
        {
            cout << "O";
        }
        else
        {
            for (int i = 0; i < figures.size(); i++)
            {
                cout << figures[i];
                if (i + 1 < figures.size() && figures[i] == figures[i + 1])
                {
                    while (i + 1 < figures.size() && figures[i] == figures[i + 1])
                    {
                        i++;
                    }
                }
            }
        }
        cout << endl;
    }

    return 0;
}

vector<char> attacks(char board[8][8], int x, int y)
{
    vector<char> result;

    if (x - 2 >= 0 && x - 2 < 8 && y - 2 >= 0 && y - 2 < 8 && board[x - 2][y - 2] == 'P')
    {
        result.push_back('P');
    }
    else if (x - 2 >= 0 && x - 2 < 8 && y >= 0 && y < 8 && board[x - 2][y] == 'P')
    {
        result.push_back('P');
    }
    

    for (int i = 0; i < 8; i++)
    {
        if (board[i][y - 1] == 'R')
        {
            result.push_back('R');
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (board[x - 1][i] == 'R')
        {
            result.push_back('R');
        }
    }

    for (int i = 1; x - i >= 1 && y - i >= 1; ++i)
    {
        if (board[x - i - 1][y - i - 1] == 'B')
        {
            result.push_back('B');
            break;
        }
    }
    for (int i = 1; x - i >= 1 && y + i <= 8; ++i)
    {
        if (board[x - i - 1][y + i - 1] == 'B')
        {
            result.push_back('B');
            break;
        }
    }
    for (int i = 1; x + i <= 8 && y - i >= 1; ++i)
    {
        if (board[x + i - 1][y - i - 1] == 'B')
        {
            result.push_back('B');
            break;
        }
    }
    for (int i = 1; x + i <= 8 && y + i <= 8; ++i)
    {
        if (board[x + i - 1][y + i - 1] == 'B')
        {
            result.push_back('B');
            break;
        }
    }

    for (int i = 0; i < 8; ++i)
    {
        if (board[i][y - 1] == 'Q' || board[x - 1][i] == 'Q')
        {
            result.push_back('Q');
        }
    }
    for (int i = 1; x - i >= 1 && y - i >= 1; ++i)
    {
        if (board[x - 1 - i][y - 1 - i] == 'Q')
        {
            result.push_back('Q');
            break;
        }
    }
    for (int i = 1; x - i >= 1 && y + i <= 8; ++i)
    {
        if (board[x - 1 - i][y - 1 + i] == 'Q')
        {
            result.push_back('Q');
            break;
        }
    }
    for (int i = 1; x + i <= 8 && y - i >= 1; ++i)
    {
        if (board[x - 1 + i][y - 1 - i] == 'Q')
        {
            result.push_back('Q');
            break;
        }
    }
    for (int i = 1; x + i <= 8 && y + i <= 8; ++i)
    {
        if (board[x - 1 + i][y - 1 + i] == 'Q')
        {
            result.push_back('Q');
            break;
        }
    }

    int knight_x[] = {2, 2, 1, 1, -2, -2, -1, -1};
    int knight_y[] = {-1, 1, -2, 2, -1, 1, -2, 2};

    for (int i = 0; i < 8; i++)
    {
        int nx = x + knight_x[i];
        int ny = y + knight_y[i];
        if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8)
        {
            if (board[nx - 1][ny - 1] == 'N')
            {
                result.push_back('N');
            }
        }
    }

    int king_x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int king_y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i)
    {
        int nx = x + king_x[i];
        int ny = y + king_y[i];
        if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8)
        {
            if (board[nx - 1][ny - 1] == 'K')
            {
                result.push_back('K');
            }
        }
    }

    return result;
}