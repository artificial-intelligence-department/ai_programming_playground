#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct ChessPiece {
    char type; 
    int x, y; 

    ChessPiece(char t, int xpos, int ypos) : type(t), x(xpos), y(ypos) {}
};

bool Pawn(int x, int y, const vector<ChessPiece>& pieces) {
    for (const auto& piece : pieces) {
        if (piece.type == 'P' && ((x - 1 == piece.x && y - 1 == piece.y) || (x - 1 == piece.x && y + 1 == piece.y))) {
            return true;
        }
    }
    return false;
}

bool Rook(int x, int y, const vector<ChessPiece>& pieces) {
    for (const auto& piece : pieces) {
        if (piece.type == 'R' && (x == piece.x || y == piece.y)) {
            return true;
        }
    }
    return false;
}

bool Knight(int x, int y, const vector<ChessPiece>& pieces) {
    int knight_dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int knight_dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    for (int i = 0; i < 8; ++i) {
        int nx = x + knight_dx[i];
        int ny = y + knight_dy[i];
        for (const auto& piece : pieces) {
            if (nx == piece.x && ny == piece.y && piece.type == 'N') {
                return true;
            }
        }
    }
    return false;
}

bool Bishop(int x, int y, const vector<ChessPiece>& pieces) {
    int dx[] = {-1, -1, 1, 1};
    int dy[] = {-1, 1, -1, 1};
    for (int k = 0; k < 4; ++k) {
        for (int j = 1; j < 8; ++j) {
            int nx = x + dx[k] * j;
            int ny = y + dy[k] * j;
            for (const auto& piece : pieces) {
                if (nx == piece.x && ny == piece.y && piece.type == 'B') {
                    return true;
                }
            }
        }
    }
    return false;
}

bool King(int x, int y, const vector<ChessPiece>& pieces) {
    int king_dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int king_dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < 8; ++i) {
        int nx = x + king_dx[i];
        int ny = y + king_dy[i];
        for (const auto& piece : pieces) {
            if (nx == piece.x && ny == piece.y && piece.type == 'K') {
                return true;
            }
        }
    }
    return false;
}

bool Queen(int x, int y, const vector<ChessPiece>& pieces) {
    for (const auto& piece : pieces) {
        if (piece.type == 'Q' && (x == piece.x || y == piece.y || abs(x - piece.x) == abs(y - piece.y))) {
            return true;
        }
    }
    return false;
}
int main() {
    vector<ChessPiece> pieces;

    
    for (int i = 0; i < 8; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < 8; ++j) {
            if (row[j] != 'O') {
                pieces.push_back(ChessPiece(row[j], i, j));
            }
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

    for (const auto& query : queries) {
        int x = query.first;
        int y = query.second;
        string answer;

        bool isOccupied = any_of(pieces.begin(), pieces.end(), [x, y](const ChessPiece& piece) {
            return piece.x == x && piece.y == y;
        });

        if (isOccupied) {
            cout << "X" << endl;
        } else {
            for (char figure : "PRNBKQ") {
                switch (figure) {
                    case 'P':
                        if (Pawn(x, y, pieces)) {
                            answer += figure;
                        }
                        break;
                    case 'R':
                        if (Rook(x, y, pieces)) {
                            answer += figure;
                        }
                        break;
                    case 'N':
                        if (Knight(x, y, pieces)) {
                            answer += figure;
                        }
                        break;
                    case 'B':
                        if (Bishop(x, y, pieces)) {
                            answer += figure;
                        }
                        break;
                    case 'K':
                        if (King(x, y, pieces)) {
                            answer += figure;
                        }
                        break;
                    case 'Q':
                        if (Queen(x, y, pieces)) {
                            answer += figure;
                        }
                        break;
                }
            }

            if (answer.empty()) {
                cout << "O" << endl;
            } else {
                sort(answer.begin(), answer.end());
                cout << answer << endl;
            }
        }
    }

    return 0;
}