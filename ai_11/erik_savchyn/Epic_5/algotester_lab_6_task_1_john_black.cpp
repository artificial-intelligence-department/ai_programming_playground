#include <iostream>
using namespace std;

bool isValidMove(int y, int x) {
    return 1 <= x && x <= 8 && 1 <= y && y <= 8;
}

bool checkX(char board[8][8], int y, int x) {
    if (board[y-1][x-1] == 'O') {
        return false;
    } else {
        return true;
    }
}

bool checkB(char board[8][8], int y, int x) {
    int directions[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    for (int i = 0; i < 4; i++) {
        int newY = y + directions[i][0];
        int newX = x + directions[i][1];

        while (isValidMove(newY, newX)) {
            if (board[newY-1][newX-1] == 'B') {
                return true;
            }
            newY += directions[i][0];
            newX += directions[i][1];
        }
    }
    return false;
}

bool checkK(char board[8][8], int y, int x) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (isValidMove(y + i, x + j) && board[y-1 + i][x-1 + j] == 'K') {
                return true;
            }
        }
    }
    return false;
}

bool checkN(char board[8][8], int y, int x) {
    int moves[8][2] = {{-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {-2, 1}, {-2, -1}, {2, 1}, {2, -1}};

    for (int i = 0; i < 8; i++) {
        int newY = y + moves[i][0];
        int newX = x + moves[i][1];

        if (isValidMove(newY, newX) && board[newY-1][newX-1] == 'N') {
            return true;
        }
    }
    return false;
}

bool checkP(char board[8][8], int y, int x) {
    if (isValidMove(y - 1, x - 1) && board[y - 2][x - 2] == 'P') {
        return true;
    }
    if (isValidMove(y - 1, x + 1) && board[y-2][x] == 'P') {
        return true;
    } else return false;
}

bool checkQ(char board[8][8], int y, int x) {
    for (int i = 0; i < 8; i++) {
        if (board[y-1][i] == 'Q' || board[i][x-1] == 'Q') {
            return true;
        }
    }
    int directions[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    for (int i = 0; i < 4; i++) {
        int newY = y + directions[i][0];
        int newX = x + directions[i][1];

        while (isValidMove(newY, newX)) {
            if (board[newY-1][newX-1] == 'Q') {
                return true;
            }
            newY += directions[i][0];
            newX += directions[i][1];
        }
    }
    return false;
}

bool checkR(char board[8][8], int y, int x) {
    for (int i = 0; i < 8; i++) {
        if (board[y-1][i] == 'R' || board[i][x-1] == 'R') {
            return true;
        }
    }
    return false;
}

int main() {
    const int boardSize = 8;
    char board[boardSize][boardSize];
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            cin >> board[i][j];
        }
    }
    int reqSize;
    cin >> reqSize;
    
    int req[reqSize][2];
    for (int i = 0; i < reqSize; i++) {
        cin >> req[i][0];
        cin >> req[i][1];
    }

    for (int i = 0; i < reqSize; i++) {
        if (checkX(board, req[i][0], req[i][1])) {
            cout << "X" << endl;
            continue;
        }
        if (checkB(board, req[i][0], req[i][1])) {
            cout << "B";
        }
        if (checkK(board, req[i][0], req[i][1])) {
            cout << "K";
        }
        if (checkN(board, req[i][0], req[i][1])) {
            cout << "N";
        }
        if (checkP(board, req[i][0], req[i][1])) {
            cout << "P";
        }
        if (checkQ(board, req[i][0], req[i][1])) {
            cout << "Q";
        }
        if (checkR(board, req[i][0], req[i][1])) {
            cout << "R";
        }
        if (checkB(board, req[i][0], req[i][1]) ||
            checkK(board, req[i][0], req[i][1]) || 
            checkN(board, req[i][0], req[i][1]) || 
            checkP(board, req[i][0], req[i][1]) || 
            checkQ(board, req[i][0], req[i][1]) || 
            checkR(board, req[i][0], req[i][1])) 
        {
            cout << endl;
            continue;
        } else cout << "O" << endl;
    }
    return 0;
}
