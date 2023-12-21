#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

bool pawn(int x, int y, vector<string> board)
{
    bool pawn = false;
    if ((y > 0 && x > 0) && (board[x - 1][y - 1] == 'P' || (x > 0 && board[x - 1][y + 1] == 'P')))
    {
        pawn = true;
    }
    return pawn;
}

bool rook(int x, int y, vector<string> board)
{
    bool rook = false;
    for (int f = 0; f < 8; f++)
    {
        if (board[x][f] == 'R' || board[f][y] == 'R')
        {
            rook = true;
        }
    }
    return rook;
}

bool knight(int x, int y, vector<string> board)
{
    bool knight = false;
    if (x > 0 && y > 1){
        if (board[x + 2][y - 1] == 'N' || board[x + 2][y + 1] == 'N'|| board[x - 1][y + 2] == 'N'){
            knight = true;
        }
    }else if(x > 0 && y > 1){
        if ((x > 1 && y > 0) && (board[x - 2][y - 1] == 'N')) {
            knight = true;
        }     
    }else if(x > 1 && y > 1){
        if (board[x - 2][y + 1] == 'N') {
            knight = true;
        }     
    }else if(x > 0 && y > 1){
        if (board[x + 1][y - 2] == 'N') {
            knight = true;
        }    
    }else if(x > 0 && y > 1){
        if (board[x + 1][y + 2] == 'N'){
            knight = true;
        }
    }else if(x > 0 && y > 1){
        if(board[x - 1][y - 2] == 'N'){
            knight = true;
        }
    }
    return knight;
}

bool bishop(int x, int y, vector<string> board)
{
    bool bishop = false;
    for (int f = 0; f < 8; f++)
    {
        if(x+f <=7 && y+f <=7){
            if (board[x + f][y + f] == 'B' ||
            (y >= f && board[x + f][y - f] == 'B') ||
            (x >= f && board[x - f][y + f] == 'B') ||
            ((x >= f && y >= f) && board[x - f][y - f] == 'B'))
            {
                bishop = true;
            }
        }
    }
    return bishop;
}

bool king(int x, int y, vector<string> board)
{
    bool king = false;
    if ((board[x + 1][y + 1] == 'K' || board[x + 1][y] == 'K' ||
         (y > 0 && board[x + 1][y - 1] == 'K') || board[x][y + 1] == 'K' ||
         (y > 0 && board[x][y - 1] == 'K') || (x > 0 && board[x - 1][y + 1] == 'K') ||
         (x > 0 && board[x - 1][y] == 'K') || ((x > 0 && y > 0) && board[x - 1][y - 1] == 'K')))
    {
        king = true;
    }
    return king;
}

bool queen(int x, int y, vector<string> board)
{
    bool queen = false;
    for (int u = 0; u < 8; u++)
        if(x+u <=7 && y+u <=7){
            if ((board[x + u][y + u] == 'Q' ||
            y >= u && board[x + u][y - u] == 'Q' ||
            x >= u && board[x - u][y + u] == 'Q' ||
            (x >= u && y >= u) && board[x - u][y - u] == 'Q' ||
                board[x][u] == 'Q' ||
                board[u][y] == 'Q'))
            {
                queen = true;
            }
        }
    return queen;
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

    int **array = new int *[Q];
    for (int i = 0; i < Q; i++)
    {
        array[i] = new int[2];
        cin >> array[i][0] >> array[i][1];
    }
    for (int i = 0; i < Q; i++)
    {
        int x = array[i][0]-1;
        int y = array[i][1]-1;
        set<char> answer;
        int k = 0;

        if (board[x][y] != 'O')
        {
            cout << 'X' << endl;
            continue;
        }

        if (pawn(x, y, board))
        {
            answer.insert('P');
            k++;
        }
        if (rook(x, y, board))
        {
            answer.insert('R');
            k++;
        }
        if (knight(x, y, board))
        {
            answer.insert('N');
            k++;
        }
        if (bishop(x, y, board))
        {
            answer.insert('B');
            k++;
        }
        if (king(x, y, board))
        {
            answer.insert('K');
            k++;
        }
        if (queen(x, y, board))
        {
            answer.insert('Q');
            k++;
        }
        if (k == 0 && board[x][y] == 'O')
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
