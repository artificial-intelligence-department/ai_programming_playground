#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<vector<char>> chessboard(8, vector<char>(8));
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            cin >> chessboard[i][j];
        }
    }
    int Q, x, y;
    cin >> Q;

    vector<vector<char>> attackingF(Q, vector<char>());
    vector<char> attRow;
    vector<int> size;

    for(int q = 0; q < Q; ++q)
    {
        cin >> x >> y;
        x -= 1;
        y -= 1;

        attRow.clear();
        for (int i = 0; i < 8; ++i)
        {
            char o = 'O';
            if (chessboard[x][y] != o)
            {
                attRow.push_back('X');
                break;
            }
            for (int j = 0; j < 8; ++j)
            {
            char chessman = chessboard[i][j];
            switch (chessman)
            {
            case 'P':
            if (((x - i == 1) && (abs(y - j) == 1)))
            {
                attRow.push_back(chessman);
            }
            break;
            case 'R':
            if ((i == x) || (j == y))
            {
                attRow.push_back(chessman);
            }
            break;
            case 'N':
            if ((abs(x - i) == 2) && (abs(y - j) == 1) || (abs(x - i) == 1) && (abs(y - j) == 2))
            {
                attRow.push_back(chessman);
            }
            break;
            case 'B':
            if ((abs(x - i) == abs(y - j)))
            {
                attRow.push_back(chessman);
            }
            break;
            case 'K':
            if (((abs(x - i) == 1) && y == j) || ((abs(y - j) == 1) && x == i) || ((abs(x - i) == 1) && (abs(y - j) == 1)))
            {
                attRow.push_back(chessman);
            }
            break;
            case 'Q':
            if ((i == x) || (j == y) || (abs(x - i) == abs(y - j)))
            {
                attRow.push_back(chessman);
            }
            break;
            }
            }
        }

        if (attRow.empty()) 
        {
            attRow.push_back('O');
        } 

        sort(attRow.begin(), attRow.end());
        auto last = unique(attRow.begin(), attRow.end());
        attRow.erase(last, attRow.end());

        size.push_back(attRow.size());

        for (int n = 0; n < attRow.size(); ++n)
        {
            attackingF[q].push_back(attRow[n]);
        }
    }
    
    for (int i = 0; i < Q; ++i)
    {
        for (int j = 0; j < size[i]; ++j)
        {
            cout << attackingF[i][j];
        }
        cout << endl;
    }

    return 0;
}