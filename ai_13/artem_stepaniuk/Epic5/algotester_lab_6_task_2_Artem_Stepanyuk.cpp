#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

const int boardSize = 8;
enum FigureType { Empty, Rook, Pawn, Knight, Bishop, King, Queen };

struct Figure {
    char symbol;
    FigureType type;

    bool canMove(int x, int y, const vector<string>& board) const {
        
        return true;
    }
};

Figure getFigure(char symbol) {
    switch (symbol) {
        case 'R':
            return {'R', Rook};
        case 'P':
            return {'P', Pawn};
        case 'N':
            return {'N', Knight};
        case 'B':
            return {'B', Bishop};
        case 'K':
            return {'K', King};
        case 'Q':
            return {'Q', Queen};
        default:
            return {'O', Empty};
    }
}

bool canMoveInDirection(int x, int y, const vector<string>& board, int dx, int dy, FigureType figureType) {
    int i = x + dx;
    int j = y + dy;

    while (i >= 0 && i < boardSize && j >= 0 && j < boardSize) {
        if (getFigure(board[i][j]).type == figureType) {
            return true;
        }

        i += dx;
        j += dy;
    }

    return false;
}

bool canMoveInDirections(int x, int y, const vector<string>& board, int dx[], int dy[], int n, FigureType figureType) {
    int i = 0;

    while (i < n) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize && getFigure(board[nx][ny]).type == figureType) {
            return true;
        }

        i++;
    }

    return false;
}

bool canMovePawn(int x, int y, const vector<string>& board) {
    return (x - 1 >= 0 && (y - 1 >= 0 && getFigure(board[x - 1][y - 1]).type == Pawn || y + 1 < boardSize && getFigure(board[x - 1][y + 1]).type == Pawn));
}

bool canMoveRook(int x, int y, const vector<string>& board) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
        if (canMoveInDirection(x, y, board, dx[i], dy[i], Rook)) {
            return true;
        }
    }

    return false;
}

bool canMoveKnight(int x, int y, const vector<string>& board) {
    int knight_dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int knight_dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; ++i) {
        int nx = x + knight_dx[i];
        int ny = y + knight_dy[i];

        if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize && getFigure(board[nx][ny]).type == Knight) {
            return true;
        }
    }

    return false;
}

bool canMoveBishop(int x, int y, const vector<string>& board) {
    int dx[] = {-1, -1, 1, 1};
    int dy[] = {-1, 1, -1, 1};

    for (int i = 0; i < 4; ++i) {
        if (canMoveInDirection(x, y, board, dx[i], dy[i], Bishop)) {
            return true;
        }
    }

    return false;
}

bool canMoveKing(int x, int y, const vector<string>& board) {
    int king_dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int king_dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i) {
        int nx = x + king_dx[i];
        int ny = y + king_dy[i];

        if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize && getFigure(board[nx][ny]).type == King) {
            return true;
        }
    }

    return false;
}

bool canMoveQueen(int x, int y, const vector<string>& board) {
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i) {
        if (canMoveInDirection(x, y, board, dx[i], dy[i], Queen)) {
            return true;
        }
    }

    return false;
}

string processQuery(int x, int y, const vector<string>& board) {
    Figure figure = getFigure(board[x][y]);
    if (figure.type != Empty) {
        return "X";
    } else {
        string answer;
        const vector<Figure> figures = {getFigure('B'), getFigure('K'), getFigure('N'), getFigure('P'), getFigure('Q'), getFigure('R')};
        for (const Figure& figure : figures) {
            switch (figure.type) {
                case Bishop:
                    if (canMoveBishop(x, y, board)) answer += figure.symbol;
                    break;
                case King:
                    if (canMoveKing(x, y, board)) answer += figure.symbol;
                    break;
                case Knight:
                    if (canMoveKnight(x, y, board)) answer += figure.symbol;
                    break;
                case Pawn:
                    if (canMovePawn(x, y, board)) answer += figure.symbol;
                    break;
                case Queen:
                    if (canMoveQueen(x, y, board)) answer += figure.symbol;
                    break;
                case Rook:
                    if (canMoveRook(x, y, board)) answer += figure.symbol;
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
        results.push_back(processQuery(x, y, board));
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