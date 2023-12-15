#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

const int BOARD_SIZE = 8;

enum Figure { EMPTY, PAWN, ROOK, KNIGHT, BISHOP, KING, QUEEN };


bitset<6> hasFigure[BOARD_SIZE][BOARD_SIZE];

bool canMoveInDirection(int x, int y, const string board[], int dx, int dy, char figure) {
    // Функція перевіряє, чи може фігура рухатись у певному напрямку
    for (int i = x + dx, j = y + dy; i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE; i += dx, j += dy) {
        if (board[i][j] == figure) {
            return true;
        }
    }
    return false;
}

bool canMoveInDirections(int x, int y, const string board[], int dx[], int dy[], int n, char figure) {
    // Функція перевіряє, чи може фігура рухатись у будь-якому з декількох напрямків
    for (int i = 0; i < n; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && board[nx][ny] == figure) {
            return true;
        }
    }
    return false;
}

bool canMovePawn(int x, int y, const string board[]) {
    // Функція перевіряє, чи може пішак рухатись
    if ((x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] == 'P') || (x - 1 >= 0 && y + 1 < BOARD_SIZE && board[x - 1][y + 1] == 'P')) {
        return true;
    }
    return false;
}

bool canMoveRook(int x, int y, const string board[]) {
    // Функція перевіряє, чи може тура рухатись
    return canMoveInDirection(x, y, board, -1, 0, 'R') ||
           canMoveInDirection(x, y, board, 1, 0, 'R') ||
           canMoveInDirection(x, y, board, 0, -1, 'R') ||
           canMoveInDirection(x, y, board, 0, 1, 'R');
}

bool canMoveKnight(int x, int y, const string board[]) {
    // Функція перевіряє, чи може конь рухатись
    int knight_dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int knight_dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    return canMoveInDirections(x, y, board, knight_dx, knight_dy, 8, 'N');
}

bool canMoveBishop(int x, int y, const string board[]) {
    // Функція перевіряє, чи може слон рухатись
    return canMoveInDirection(x, y, board, -1, -1, 'B') ||
           canMoveInDirection(x, y, board, -1, 1, 'B') ||
           canMoveInDirection(x, y, board, 1, -1, 'B') ||
           canMoveInDirection(x, y, board, 1, 1, 'B');
}

bool canMoveKing(int x, int y, const string board[]) {
    // Функція перевіряє, чи може король рухатись
    int king_dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int king_dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    return canMoveInDirections(x, y, board, king_dx, king_dy, 8, 'K');
}

bool canMoveQueen(int x, int y, const string board[]) {
    // Функція перевіряє, чи може ферзь рухатись
    return canMoveInDirection(x, y, board, -1, -1, 'Q') ||
           canMoveInDirection(x, y, board, -1, 1, 'Q') ||
           canMoveInDirection(x, y, board, 1, -1, 'Q') ||
           canMoveInDirection(x, y, board, 1, 1, 'Q') ||
           canMoveInDirection(x, y, board, -1, 0, 'Q') ||
           canMoveInDirection(x, y, board, 1, 0, 'Q') ||
           canMoveInDirection(x, y, board, 0, -1, 'Q') ||
           canMoveInDirection(x, y, board, 0, 1, 'Q');
}

string processQuery(int x, int y, const string board[]) {
    // Функція обробляє запит та повертає відповідь
    char figure = board[x][y];
    if (figure != 'O') {
        return "X";
    } else {
        string answer;
        const string figures = "BKNPQR"; // Змінено порядок фігур для зручності
        for (char figure : figures) {
            switch (figure) {
                case 'B':
                    if (canMoveBishop(x, y, board)) answer += figure;
                    break;
                case 'K':
                    if (canMoveKing(x, y, board)) answer += figure;
                    break;
                case 'N':
                    if (canMoveKnight(x, y, board)) answer += figure;
                    break;
                case 'P':
                    if (canMovePawn(x, y, board)) answer += figure;
                    break;
                case 'Q':
                    if (canMoveQueen(x, y, board)) answer += figure;
                    break;
                case 'R':
                    if (canMoveRook(x, y, board)) answer += figure;
                    break;
                default:
                    break;
            }
        }

        return answer.empty() ? "O" : answer;
    }
}

int main() {
    // Основна функція для вводу та обробки запитів
    string board[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        cin >> board[i];
        for (int j = 0; j < BOARD_SIZE; j++) {
            hasFigure[i][j] = (board[i][j] != '.');
        }
    }

    int Q;
    cin >> Q;
    vector<pair<int, int>> queries;
    for (int m = 0; m < Q; m++) {
        int a, b;
        cin >> a >> b;
        queries.push_back({a - 1, b - 1});
    }

    for (const auto &query : queries) {
        int x = query.first;
        int y = query.second;
        string answer = processQuery(x, y, board);
        cout << answer << endl;
    }

    return 0;
}
