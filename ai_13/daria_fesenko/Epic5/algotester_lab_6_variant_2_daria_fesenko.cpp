#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;


const int boardSize = 8;
enum Figure { empty, rook, pawn, knight, bishop, king, queen };
bitset<6> hasFigure[boardSize][boardSize];
bool canMoveInDirection(int x, int y, const string board[], int dx, int dy, char figure) {
    int i = x + dx;
    int j = y + dy;

    while (i >= 0 && i < boardSize && j >= 0 && j < boardSize) {
        if (board[i][j] == figure) {
            return true;
        }

        i += dx;
        j += dy;
    }

    return false;
}

bool canMoveInDirections(int x, int y, const string board[], int dx[], int dy[], int n, char figure) {
    int i = 0;

    while (i < n) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize && board[nx][ny] == figure) {
            return true;
        }

        i++;
    }

    return false;
}

bool canMovePawn(int x, int y, const string board[]) {
    return (x - 1 >= 0 && (y - 1 >= 0 && board[x - 1][y - 1] == 'P' || y + 1 < boardSize && board[x - 1][y + 1] == 'P'));
}

bool canMoveRook(int x, int y, const string board[]) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
        if (canMoveInDirection(x, y, board, dx[i], dy[i], 'R')) {
            return true;
        }
    }

    return false;
}

bool canMoveKnight(int x, int y, const string board[]) {
    int knight_dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int knight_dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; ++i) {
        int nx = x + knight_dx[i];
        int ny = y + knight_dy[i];

        if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize && board[nx][ny] == 'N') {
            return true;
        }
    }

    return false;
}

bool canMoveBishop(int x, int y, const string board[]) {
    int dx[] = {-1, -1, 1, 1};
    int dy[] = {-1, 1, -1, 1};

    for (int i = 0; i < 4; ++i) {
        if (canMoveInDirection(x, y, board, dx[i], dy[i], 'B')) {
            return true;
        }
    }

    return false;
}

bool canMoveKing(int x, int y, const string board[]) {
    int king_dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int king_dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i) {
        int nx = x + king_dx[i];
        int ny = y + king_dy[i];

        if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize && board[nx][ny] == 'K') {
            return true;
        }
    }

    return false;
}
bool canMoveQueen(int x, int y, const string board[]) {
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i) {
        if (canMoveInDirection(x, y, board, dx[i], dy[i], 'Q')) {
            return true;
        }
    }

    return false;
}
string processQuery(int x, int y, const string board[]) {
    char figure = board[x][y];
    if (figure != 'O') {
        return "X";
    } else {
        string answer;
        const string figures = "BKNPQR"; 
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

vector<string> processQueries(const vector<string>& board, const vector<pair<int, int>>& queries) {
    vector<string> results;

    for (const auto& query : queries) {
        int x = query.first;
        int y = query.second;
        results.push_back(processQuery(x, y, board.data()));
    }

    return results;
}

int main() {
    vector<string> board(boardSize);
    for (int i = 0; i < boardSize; i++) {
        cin >> board[i];
    }

    int Q;
    cin >> Q;

    vector<pair<int, int>> queries;
    for (int m = 0; m < Q; m++) {
        int a, b;
        cin >> a >> b;
        queries.push_back({a - 1, b - 1});
    }

    vector<string> results = processQueries(board, queries);

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}




