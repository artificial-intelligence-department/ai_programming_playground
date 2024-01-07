#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

bool isValidCoordinate(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

bool pawn(int x, int y, vector<string> board)
{
    bool isPawn = false;
    if (isValidCoordinate(x - 1, y - 1) && (board[x - 1][y - 1] == 'P' || isValidCoordinate(x - 1, y + 1) && board[x - 1][y + 1] == 'P'))
    {
        isPawn = true;
    }
    return isPawn;
}

bool rook(int x, int y, vector<string> board)
{
    bool isRook = false;
    for (int f = 0; f < 8; f++)
    {
        if (board[x][f] == 'R' || board[f][y] == 'R')
        {
            isRook = true;
        }
    }
    return isRook;
}

bool knight(int x, int y, vector<string> board)
{
    bool isKnight = false;
    if (isValidCoordinate(x + 2, y - 1) && (board[x + 2][y - 1] == 'N' || isValidCoordinate(x + 2, y + 1) && board[x + 2][y + 1] == 'N' || isValidCoordinate(x - 1, y + 2) && board[x - 1][y + 2] == 'N'))
    {
        isKnight = true;
    }
    else if (isValidCoordinate(x - 2, y - 1) && board[x - 2][y - 1] == 'N')
    {
        isKnight = true;
    }
    else if (isValidCoordinate(x - 2, y + 1) && board[x - 2][y + 1] == 'N')
    {
        isKnight = true;
    }
    else if (isValidCoordinate(x + 1, y - 2) && board[x + 1][y - 2] == 'N')
    {
        isKnight = true;
    }
    else if (isValidCoordinate(x + 1, y + 2) && board[x + 1][y + 2] == 'N')
    {
        isKnight = true;
    }
    else if (isValidCoordinate(x - 1, y - 2) && board[x - 1][y - 2] == 'N')
    {
        isKnight = true;
    }
    return isKnight;
}

bool bishop(int x, int y, vector<string> board)
{
    bool isBishop = false;
    for (int f = 0; f < 8; f++)
    {
        if (isValidCoordinate(x + f, y + f) && (board[x + f][y + f] == 'B' ||
            (isValidCoordinate(x + f, y - f) && board[x + f][y - f] == 'B') ||
            (isValidCoordinate(x - f, y + f) && board[x - f][y + f] == 'B') ||
            (isValidCoordinate(x - f, y - f) && board[x - f][y - f] == 'B')))
        {
            isBishop = true;
        }
    }
    return isBishop;
}

bool king(int x, int y, vector<string> board)
{
    bool isKing = false;
    if (isValidCoordinate(x + 1, y + 1) && (board[x + 1][y + 1] == 'K' || isValidCoordinate(x + 1, y) && board[x + 1][y] == 'K' ||
        (isValidCoordinate(x + 1, y - 1) && board[x + 1][y - 1] == 'K') || isValidCoordinate(x, y + 1) && board[x][y + 1] == 'K' ||
        (isValidCoordinate(x, y - 1) && board[x][y - 1] == 'K') || (isValidCoordinate(x - 1, y + 1) && board[x - 1][y + 1] == 'K') ||
        (isValidCoordinate(x - 1, y) && board[x - 1][y] == 'K') || (isValidCoordinate(x - 1, y - 1) && board[x - 1][y - 1] == 'K')))
    {
        isKing = true;
    }
    return isKing;
}

bool queen(int x, int y, vector<string> board)
{
    bool isQueen = false;
    for (int u = 0; u < 8; u++)
    {
        if (isValidCoordinate(x + u, y + u) && (board[x + u][y + u] == 'Q' ||
            (isValidCoordinate(x + u, y - u) && board[x + u][y - u] == 'Q') ||
            (isValidCoordinate(x - u, y + u) && board[x - u][y + u] == 'Q') ||
            (isValidCoordinate(x - u, y - u) && board[x - u][y - u] == 'Q') ||
            (isValidCoordinate(x, u) && board[x][u] == 'Q') ||
            (isValidCoordinate(u, y) && board[u][y] == 'Q')))
        {
            isQueen = true;
        }
    }
    return isQueen;
}

int main()
{
    vector<string> board(8);

    for (int i = 0; i < 8; i++)
    {
        getline(cin, board[i]);
    }

    int Q;
    cin >> Q;

    int** array = new int* [Q];
    for (int i = 0; i < Q; i++)
    {
        array[i] = new int[2];
        cin >> array[i][0] >> array[i][1];
    }
    for (int i = 0; i < Q; i++)
    {
        int x = array[i][0] - 1;
        int y = array[i][1] - 1;
        set<char> answer;
        int k = 0;

        if (isValidCoordinate(x, y) && board[x][y] != 'O')
        {
            cout << 'X' << endl;
            continue;
        }

        if (isValidCoordinate(x, y) && pawn(x, y, board))
        {
            answer.insert('P');
            k++;
        }
        if (isValidCoordinate(x, y) && rook(x, y, board))
        {
            answer.insert('R');
            k++;
        }
        if (isValidCoordinate(x, y) && knight(x, y, board))
        {
            answer.insert('N');
            k++;
        }
        if (isValidCoordinate(x, y) && bishop(x, y, board))
        {
            answer.insert('B');
            k++;
        }
        if (isValidCoordinate(x, y) && king(x, y, board))
        {
            answer.insert('K');
            k++;
        }
        if (isValidCoordinate(x, y) && queen(x, y, board))
        {
            answer.insert('Q');
            k++;
        }
        if (k == 0 && isValidCoordinate(x, y) && board[x][y] == 'O')
        {
            cout << 'O' << endl;
            continue;
        }
        for (char i : answer)
        {
            cout << i;
        }
        cout << endl;
        answer.clear();
    }

    for (int i = 0; i < Q; i++)
    {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
