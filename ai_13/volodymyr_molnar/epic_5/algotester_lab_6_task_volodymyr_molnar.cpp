#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
enum ChessPiece { NONE, PAWN, ROOK, KNIGHT, BISHOP, KING, QUEEN };
bitset<6> hasChessPiece[8][8];
string vpisannia(int x, int y, const string board[]);

bool Move(int x, int y, const string board[], int dx[], int dy[], int n, char piece);
bool Move(int x, int y, const string board[], int dx, int dy, char piece);
bool isRookCanMove(int x, int y, const string board[]);
bool isQueenCanMove(int x, int y, const string board[]);
bool isKinCanMove(int x, int y, const string board[]);
bool isPawnCanMove(int x, int y, const string board[]);
bool isBishopCanMove(int x, int y, const string board[]);
bool isKingCanMove(int x, int y, const string board[]);

int main() {
    string board[8];
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
        for (int j = 0; j < 8; j++)
            hasChessPiece[i][j] = (board[i][j] != '.');
    }

    int Q;
    cin >> Q;
    vector<pair<int, int>> queries;
    for (int m = 0; m < Q; m++) {
        int a, b;
        cin >> a;
        cin >> b;
        queries.push_back({a - 1, b - 1});
    }

    for (const auto &query : queries) {
        int y = query.second;
        int x = query.first;
        string answer = vpisannia(x, y, board);
        cout << answer << endl;
    }
    return 0;
}
bool isKingCanMove(int x, int y, const string board[]) {
    int y1[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    int x1[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    return Move(x, y, board, x1, y1, 8, 'K');
}
bool isBishopCanMove(int x, int y, const string board[]) {
    return Move(x, y, board, -1, -1, 'B') ||
        Move(x, y, board, -1, 1, 'B') ||
        Move(x, y, board, 1, -1, 'B') ||
        Move(x, y, board, 1, 1, 'B');
}

bool Move(int x, int y, const string board[], int dx, int dy, char type) {
    for (int i = x + dx, j = y + dy; i >= 0 && 
        i < 8 && j >= 0 && j < 8; i += dx, j += dy)
        if (board[i][j] == type)
            return true;
    return false;
}
bool isRookCanMove(int x, int y, const string board[]) {
    return Move(x, y, board, -1, 0, 'R') ||
        Move(x, y, board, 1, 0, 'R') ||
        Move(x, y, board, 0, -1, 'R') ||
        Move(x, y, board, 0, 1, 'R');
}
bool Move(int x, int y, const string board[], int dx[], int dy[], int n, char type) {
    for (int i = 0; i < n; ++i) {
        int  x1 = x + dx[i];
        int y1 = y + dy[i];
        if (x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8 && board[x1][y1] == type)
            return true;
    }
    return false;
}
bool isQueenCanMove(int x, int y, const string board[]) {
    return Move(x, y, board, -1, -1, 'Q') ||
        Move(x, y, board, 1, 0, 'Q') ||
        Move(x, y, board, 0, -1, 'Q') ||
        Move(x, y, board, 1, 1, 'Q') ||
        Move(x, y, board, -1, 0, 'Q') ||
        Move(x, y, board, -1, 1, 'Q') ||
        Move(x, y, board, 1, -1, 'Q') ||
        Move(x, y, board, 0, 1, 'Q');
}
bool isKinCanMove(int x, int y, const string board[]) {
    int x1[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    int y1[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    return Move(x, y, board, x1, y1, 8, 'N');
}
bool isPawnCanMove(int x, int y, const string board[]) {
    if ((x - 1 >= 0 && y + 1 < 8 && board[x - 1][y + 1] == 'P') ||
        (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] == 'P'))
        return true;
    return false;
}
string vpisannia(int x, int y, const string board[]) {
    char piece = board[x][y];
    if (piece != 'O') 
        return "X";
    else {
        string res;
        string type = "BKNPQR";
        for (char type : type) {
            switch (type) {
            case 'P':
                if (isPawnCanMove(x, y, board)) res += type;
                break;
            case 'B':
                if (isBishopCanMove(x, y, board)) res += type;
                break;
            case 'K':
                if (isKingCanMove(x, y, board)) res += type;
                break;
            case 'Q':
                if (isQueenCanMove(x, y, board)) res += type;
                break;
            case 'N':
                if (isKinCanMove(x, y, board)) res += type;
                break;
            case 'R':
                if (isRookCanMove(x, y, board)) res += type;
                break;
            default:
                break;
            }
        }
        return res.empty() ? "O" : res;
    }
}