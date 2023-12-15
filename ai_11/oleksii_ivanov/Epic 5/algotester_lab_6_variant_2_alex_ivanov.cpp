#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool diagonalToken(char token, const vector<string>& board, int x, int y);
bool horizontalToken(char token, const vector<string>& board, int x, int y);
bool verticalToken(char token, const vector<string>& board, int x, int y);

bool isBishopAttacking(const vector<string>& board, int x, int y);
bool isRookAttacking(const vector<string>& board, int x, int y);
bool isQueenAttacking(const vector<string>& board, int x, int y);
bool isPawnAttacking(const vector<string>& board, int x, int y);
bool isKingAttacking(const vector<string>& board, int x, int y);
bool isKnightAttacking(const vector<string>& board, int x, int y);

bool checkOffsets(int x, int y, int m, int p);

set<char> attacking(const vector<string>& board, int x, int y);

constexpr int SIZE = 8;

int main() {
    vector<string> v(SIZE);
    for(string& s : v) cin >> s;

    int Q;
    cin >> Q;

    int x, y;
    set<char> result;
    for(int i = 0; i < Q; i++) {
        cin >> x >> y;

        result = attacking(v, x - 1, y - 1);

        for (char c : result) cout << c;
        cout << endl;
    }

    return 0;
}

bool checkOffsets(int x, int y, int m, int p) {
    return x + m >= 0 && x + m <= 7 && y + p >= 0 && y + p <= 7;
}

bool diagonalToken(char token, const vector<string>& board, int x, int y) {
    for (int i = 1; i < SIZE; ++i) {
        // Check for token in left top diagonal part
        if (x - i >= 0 && y - i >= 0 && (board[x - i][y - i] == token))
            return true;

        // Check for token in right top diagonal part
        if (x - i >= 0 && y + i < SIZE && (board[x - i][y + i] == token))
            return true;

        // Check for token in left bottom diagonal part
        if (x + i < SIZE && y - i >= 0 && (board[x + i][y - i] == token))
            return true;

        // Check for token in right bottom diagonal part
        if (x + i < SIZE && y + i < SIZE && (board[x + i][y + i] == token))
            return true;
    }

    return false;
}
bool horizontalToken(char token, const vector<string>& board, int x, int y) {
    for (int i = 0; i < SIZE; ++i) {
        // Check for token in left part
        if (y - i >= 0 && (board[x][y - i] == token))
            return true;

        // Check for token in right part
        if (y + i < SIZE && (board[x][y + i] == token))
            return true;
    }

    return false;
}
bool verticalToken(char token, const vector<string>& board, int x, int y) {
    for (int i = 0; i < SIZE; ++i) {
        // Check for token in top part
        if (x - i >= 0 && (board[x - i][y] == token))
            return true;

        // Check for token in bottom part
        if (x + i < SIZE && (board[x + i][y] == token))
            return true;
    }

    return false;
}

bool isBishopAttacking(const vector<string>& board, int x, int y) {
    return diagonalToken('B', board, x, y);
}
bool isRookAttacking(const vector<string>& board, int x, int y) {
    return horizontalToken('R', board, x, y) || verticalToken('R', board, x, y);
}
bool isQueenAttacking(const vector<string>& board, int x, int y) {
    return diagonalToken('Q', board, x, y) ||
           horizontalToken('Q', board, x, y) ||
           verticalToken('Q', board, x, y);
}
bool isPawnAttacking(const vector<string>& board, int x, int y) {
    return (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] == 'P') ||
           (x - 1 >= 0 && y + 1 < SIZE && board[x - 1][y + 1] == 'P');
}
bool isKingAttacking(const vector<string>& board, int x, int y) {
    for (int m = -1; m <= 1; m++)
        for (int p = -1; p <= 1; p++)
            if (checkOffsets(x, y, m, p) && board[x + m][y + p] == 'K')
                return true;

    return false;
}
bool isKnightAttacking(const vector<string>& board, int x, int y) {
    for (int m = -2; m <= 2; m += 4)
        for (int p = -1; p <= 1; p += 2)
            if ((checkOffsets(x, y, m, p) && board[x + m][y + p] == 'N') ||
                (checkOffsets(x, y, p, m) && board[x + p][y + m] == 'N'))
                return true;

    return false;
}

set<char> attacking(const vector<string>& board, int x, int y) {
    set<char> result;

    // If is not empty, return 'X'
    if (board[x][y] != 'O') {
        result.insert('X');
        return result;
    }

    if (isPawnAttacking(board, x, y))
        result.insert('P');

    if (isRookAttacking(board, x, y))
        result.insert('R');

    if (isKnightAttacking(board, x, y))
        result.insert('N');

    if (isBishopAttacking(board, x, y))
        result.insert('B');

    if (isKingAttacking(board, x, y))
        result.insert('K');

    if (isQueenAttacking(board, x, y))
        result.insert('Q');

    if (result.empty())
        result.insert('O');

    return result;
}