#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> attacksfigures(char chessboard[8][8], int x, int y);

vector<char> attacksfigures(char chessboard[8][8], int x, int y)
{
    vector<char> result;

//пішак
    if (x - 2 >= 0 && x - 2 < 8 && y >= 0 && y < 8 && chessboard[x - 2][y] == 'P')
    {
        result.push_back('P');
    }
    else if (x - 2 >= 0 && x - 2 < 8 && y - 2 >= 0 && y - 2 < 8 && chessboard[x - 2][y - 2] == 'P')
    {
        result.push_back('P');
    }

//тура
for (int i = 0; i < 8; i++) {
    if (chessboard[i][y - 1] == 'R' || chessboard[x - 1][i] == 'R') {
        result.push_back('R');
    }
}

//cлон
    for (int i = 1; x - i >= 1 && y - i >= 1; ++i)
    {
        if (chessboard[x - i - 1][y - i - 1] == 'B')
        {
            result.push_back('B');
            break;
        }
    }
    for (int i = 1; x - i >= 1 && y + i <= 8; ++i)
    {
        if (chessboard[x - i - 1][y + i - 1] == 'B')
        {
            result.push_back('B');
            break;
        }
    }
    for (int i = 1; x + i <= 8 && y - i >= 1; ++i)
    {
        if (chessboard[x + i - 1][y - i - 1] == 'B')
        {
            result.push_back('B');
            break;
        }
    }
    for (int i = 1; x + i <= 8 && y + i <= 8; ++i)
    {
        if (chessboard[x + i - 1][y + i - 1] == 'B')
        {
            result.push_back('B');
            break;
        }
    }

// королева
 for (int i = 0; i < 8; ++i)
    {
        if (chessboard[i][y - 1] == 'Q' || chessboard[x - 1][i] == 'Q')
        {
            result.push_back('Q');
        }
    }
    for (int i = 1; x - i >= 1 && y - i >= 1; ++i)
    {
        if (chessboard[x - 1 - i][y - 1 - i] == 'Q')
        {
            result.push_back('Q');
            break;
        }
    }
    for (int i = 1; x - i >= 1 && y + i <= 8; ++i)
    {
        if (chessboard[x - 1 - i][y - 1 + i] == 'Q')
        {
            result.push_back('Q');
            break;
        }
    }
    for (int i = 1; x + i <= 8 && y - i >= 1; ++i)
    {
        if (chessboard[x - 1 + i][y - 1 - i] == 'Q')
        {
            result.push_back('Q');
            break;
        }
    }
    for (int i = 1; x + i <= 8 && y + i <= 8; ++i)
    {
        if (chessboard[x - 1 + i][y - 1 + i] == 'Q')
        {
            result.push_back('Q');
            break;
        }
    }


//кінь
   int horse_x[] = {2, 2, 1, 1, -2, -2, -1, -1};
    int horse_y[] = {-1, 1, -2, 2, -1, 1, -2, 2};

    for (int i = 0; i < 8; i++)
    {
        int xn = x + horse_x[i];
        int yn = y + horse_y[i];
        if (xn >= 1 && xn <= 8 && yn >= 1 && yn <= 8)
        {
            if (chessboard[xn - 1][yn - 1] == 'N')
            {
                result.push_back('N');
            }
        }
    }

//король
    int directions_k_x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int directions_k_y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i)
    {
        int direction_k_x = x + directions_k_x[i];
        int direction_k_y = y + directions_k_y[i];
        if (direction_k_x >= 1 && direction_k_x <= 8 && direction_k_y >= 1 && direction_k_y <= 8)
        {
            if (chessboard[direction_k_x - 1][direction_k_y - 1] == 'K')
            {
                result.push_back('K');
            }
        }
    }

    return result;
}


int main()
{
    char chessboard[8][8];

    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++) 
        {
            cin >> chessboard[i][j];
        }
    }

    int Q;
    cin >> Q;

    vector<pair<int, int>> location;

    for (int i = 0; i < Q; i++) 
    {
        int x, y;
        cin >> x >> y;
        location.push_back({x, y});
    }

    for (int i = 0; i < Q; i++)
    {
        int x = location[i].first;
        int y = location[i].second;

        vector<char> figures = attacksfigures(chessboard, x, y);

        sort(figures.begin(), figures.end());
        if (chessboard[x - 1][y - 1] != 'O')
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
                    for ( ; i + 1 < figures.size() && figures[i] == figures[i + 1]; i++);
                }
            }
        }
        cout << endl;
    }

    return 0;
}