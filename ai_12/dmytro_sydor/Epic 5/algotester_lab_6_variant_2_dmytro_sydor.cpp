#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int boardSize = 8;

string getAttackFigures(const string board[boardSize], int row, int col)
{
    string attackFigures = "";
    int counter = 0;

    // Pawn
    if (row > 0)
    {
        if (col > 0 && board[row - 1][col - 1] == 'P')
        {
            attackFigures += 'P';
            counter++;
        }
        if (col < boardSize - 1 && board[row - 1][col + 1] == 'P')
        {
            attackFigures += 'P';
            counter++;
        }
    }

    // Rook
    for (int i = 0; i < boardSize; i++)
    {
        if (board[row][i] == 'R' || board[i][col] == 'R')
        {
            attackFigures += 'R';
            counter++;
        }
    }

    // Knight
    if (row > 1)
    {
        if (col > 0 && board[row - 2][col - 1] == 'N')
        {
            attackFigures += 'N';
            counter++;
        }
        if (col < boardSize - 1 && board[row - 2][col + 1] == 'N')
        {
            attackFigures += 'N';
            counter++;
        }
    }
    if (row < boardSize - 2)
    {
        if (col > 0 && board[row + 2][col - 1] == 'N')
        {
            attackFigures += 'N';
            counter++;
        }
        if (col < boardSize - 1 && board[row + 2][col + 1] == 'N')
        {
            attackFigures += 'N';
            counter++;
        }
    }
    if (col > 1)
    {
        if (row > 0 && board[row - 1][col - 2] == 'N')
        {
            attackFigures += 'N';
            counter++;
        }
        if (row < boardSize - 1 && board[row + 1][col - 2] == 'N')
        {
            attackFigures += 'N';
            counter++;
        }
    }
    if (col < boardSize - 2)
    {
        if (row > 0 && board[row - 1][col + 2] == 'N')
        {
            attackFigures += 'N';
            counter++;
        }
        if (row < boardSize - 1 && board[row + 1][col + 2] == 'N')
        {
            attackFigures += 'N';
            counter++;
        }
    }

    // Bishop
    for (int i = 0; i < boardSize; i++)
    {
        if (row + i < boardSize && col + i < boardSize && board[row + i][col + i] == 'B')
        {
            attackFigures += 'B';
            counter++;
        }
        if (col >= i && row + i < boardSize && board[row + i][col - i] == 'B')
        {
            attackFigures += 'B';
            counter++;
        }
        if (row >= i && col + i < boardSize && board[row - i][col + i] == 'B')
        {
            attackFigures += 'B';
            counter++;
        }
        if (row >= i && col >= i && board[row - i][col - i] == 'B')
        {
            attackFigures += 'B';
            counter++;
        }
    }

    // King
    if (col > 0 && board[row][col - 1] == 'K')
    {
        attackFigures += 'K';
        counter++;
    }
    if (col < boardSize - 1 && board[row][col + 1] == 'K')
    {
        attackFigures += 'K';
        counter++;
    }
    if (row > 0 && col > 0 && board[row - 1][col - 1] == 'K')
    {
        attackFigures += 'K';
        counter++;
    }
    if (row > 0 && board[row - 1][col] == 'K')
    {
        attackFigures += 'K';
        counter++;
    }
    if (row > 0 && col < boardSize - 1 && board[row - 1][col + 1] == 'K')
    {
        attackFigures += 'K';
        counter++;
    }
    if (row < boardSize - 1 && board[row + 1][col] == 'K')
    {
        attackFigures += 'K';
        counter++;
    }
    if (row < boardSize - 1 && col < boardSize - 1 && board[row + 1][col + 1] == 'K')
    {
        attackFigures += 'K';
        counter++;
    }
    if (row < boardSize - 1 && col > 0 && board[row + 1][col - 1] == 'K')
    {
        attackFigures += 'K';
        counter++;
    }

    // Queen
    for (int i = 0; i < boardSize; i++)
    {
        if (row + i < boardSize && col + i < boardSize && board[row + i][col + i] == 'Q')
        {
            attackFigures += 'Q';
            counter++;
        }
        if (col >= i && row + i < boardSize && board[row + i][col - i] == 'Q')
        {
            attackFigures += 'Q';
            counter++;
        }
        if (row >= i && col + i < boardSize && board[row - i][col + i] == 'Q')
        {
            attackFigures += 'Q';
            counter++;
        }
        if (row >= i && col >= i && board[row - i][col - i] == 'Q')
        {
            attackFigures += 'Q';
            counter++;
        }
        if (board[row][i] == 'Q')
        {
            attackFigures += 'Q';
            counter++;
        }
        if (board[i][col] == 'Q')
        {
            attackFigures += 'Q';
            counter++;
        }
    }

    if (counter == 0)
    {
        return "O";
    }
    else
    {
        sort(attackFigures.begin(), attackFigures.end());
        auto newEnd = unique(attackFigures.begin(), attackFigures.end());
        attackFigures.resize(distance(attackFigures.begin(), newEnd));
        return attackFigures;
    }
}

string processQuery(const string board[boardSize], int row, int col)
{
    row -= 1;
    col -= 1;
    if (board[row][col] != 'O')
    {
        return "X";
    }
    return getAttackFigures(board, row, col);
}

int main()
{
    string board[boardSize];
    int Q;

    for (int i = 0; i < boardSize; ++i)
    {
        getline(cin, board[i]);
    }

    cin >> Q;

    vector<string> results;
    for (int i = 0; i < Q; i++)
    {
        int row, col;
        cin >> row >> col;
        results.push_back(processQuery(board, row, col));
    }

    for (const string &result : results)
    {
        cout << result << endl;
    }

    return 0;
}
