#include <iostream>
#include <vector>
#include <set>
using namespace std;

constexpr int BOARD_SIZE = 8;

// Function to check if the given offset is within the board boundaries
bool isValidOffset(int x, int y, int offsetX, int offsetY) {
    return x + offsetX >= 0 && x + offsetX < BOARD_SIZE && y + offsetY >= 0 && y + offsetY < BOARD_SIZE;
}

// Functions to check if there is a token in different directions
bool hasDiagonalToken(char token, const vector<string>& board, int x, int y) {
    for (int i = 1; i < BOARD_SIZE; ++i) {
        // Check for token in left top diagonal part
        if (isValidOffset(x, y, -i, -i) && board[x - i][y - i] == token)
            return true;

        // Check for token in right top diagonal part
        if (isValidOffset(x, y, -i, i) && board[x - i][y + i] == token)
            return true;

        // Check for token in left bottom diagonal part
        if (isValidOffset(x, y, i, -i) && board[x + i][y - i] == token)
            return true;

        // Check for token in right bottom diagonal part
        if (isValidOffset(x, y, i, i) && board[x + i][y + i] == token)
            return true;
    }
    return false;
}

bool hasHorizontalToken(char token, const vector<string>& board, int x, int y) {
    for (int i = 1; i < BOARD_SIZE; ++i) {
        // Check for token in left part
        if (isValidOffset(x, y, 0, -i) && board[x][y - i] == token)
            return true;

        // Check for token in right part
        if (isValidOffset(x, y, 0, i) && board[x][y + i] == token)
            return true;
    }
    return false;
}

bool hasVerticalToken(char token, const vector<string>& board, int x, int y) {
    for (int i = 1; i < BOARD_SIZE; ++i) {
        // Check for token in top part
        if (isValidOffset(x, y, -i, 0) && board[x - i][y] == token)
            return true;

        // Check for token in bottom part
        if (isValidOffset(x, y, i, 0) && board[x + i][y] == token)
            return true;
    }
    return false;
}

// Functions to check if each chess piece is attacking a certain position
bool isBishopAttacking(const vector<string>& board, int x, int y) {
    return hasDiagonalToken('B', board, x, y);
}

bool isRookAttacking(const vector<string>& board, int x, int y) {
    return hasHorizontalToken('R', board, x, y) || hasVerticalToken('R', board, x, y);
}

bool isQueenAttacking(const vector<string>& board, int x, int y) {
    return hasDiagonalToken('Q', board, x, y) || hasHorizontalToken('Q', board, x, y) || hasVerticalToken('Q', board, x, y);
}

bool isPawnAttacking(const vector<string>& board, int x, int y) {
    return (isValidOffset(x, y, -1, -1) && board[x - 1][y - 1] == 'P') ||
           (isValidOffset(x, y, -1, 1) && board[x - 1][y + 1] == 'P');
}

bool isKingAttacking(const vector<string>& board, int x, int y) {
    for (int offsetX = -1; offsetX <= 1; ++offsetX) {
        for (int offsetY = -1; offsetY <= 1; ++offsetY) {
            if (isValidOffset(x, y, offsetX, offsetY) && board[x + offsetX][y + offsetY] == 'K') {
                return true;
            }
        }
    }
    return false;
}

bool isKnightAttacking(const vector<string>& board, int x, int y) {
    for (int offsetX = -2; offsetX <= 2; offsetX += 4) {
        for (int offsetY = -1; offsetY <= 1; offsetY += 2) {
            if ((isValidOffset(x, y, offsetX, offsetY) && board[x + offsetX][y + offsetY] == 'N') ||
                (isValidOffset(x, y, offsetY, offsetX) && board[x + offsetY][y + offsetX] == 'N')) {
                return true;
            }
        }
    }
    return false;
}

// Function to get the set of attacking pieces at a given position
set<char> getAttackingPieces(const vector<string>& board, int x, int y) {
    set<char> result;

    // If the position is not empty, return 'X'
    if (board[x][y] != 'O') {
        result.insert('X');
        return result;
    }

    // Check each type of attacking piece and add to the result set
    if (isPawnAttacking(board, x, y)) result.insert('P');
    if (isRookAttacking(board, x, y)) result.insert('R');
    if (isKnightAttacking(board, x, y)) result.insert('N');
    if (isBishopAttacking(board, x, y)) result.insert('B');
    if (isKingAttacking(board, x, y)) result.insert('K');
    if (isQueenAttacking(board, x, y)) result.insert('Q');

    // If no attacking piece is found, return 'O'
    if (result.empty()) result.insert('O');

    return result;
}

// Main function
int main() {
    // Input the chessboard configuration
    vector<string> chessBoard(BOARD_SIZE);
    for (string& row : chessBoard) cin >> row;

    // Input the number of queries
    int queryCount;
    cin >> queryCount;

    int queryX, queryY;
    set<char> result;
    for (int i = 0; i < queryCount; ++i) {
        // Input the position for each query
        cin >> queryX >> queryY;
        result = getAttackingPieces(chessBoard, queryX - 1, queryY - 1);

        // Output the result set for each query
        for (char piece : result) cout << piece;
        cout << endl;
    }

    return 0;
}
