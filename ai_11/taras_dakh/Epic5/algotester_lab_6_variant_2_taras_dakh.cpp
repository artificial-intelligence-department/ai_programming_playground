#include <iostream>
#include <vector>
#include <algorithm>

struct ChessPiece {
    char type;
    int x, y;

    ChessPiece(char t, int xpos, int ypos) : type(t), x(xpos), y(ypos) {}
};

bool isOccupied(int x, int y, const std::vector<ChessPiece>& pieces) {
    return std::any_of(pieces.begin(), pieces.end(), [x, y](const ChessPiece& piece) {
        return piece.x == x && piece.y == y;
    });
}

bool isPawn(int x, int y, const std::vector<ChessPiece>& pieces) {
    return std::any_of(pieces.begin(), pieces.end(), [x, y](const ChessPiece& piece) {
        return piece.type == 'P' && ((x - 1 == piece.x && y - 1 == piece.y) || (x - 1 == piece.x && y + 1 == piece.y));
    });
}

bool isRook(int x, int y, const std::vector<ChessPiece>& pieces) {
    return std::any_of(pieces.begin(), pieces.end(), [x, y](const ChessPiece& piece) {
        return piece.type == 'R' && (x == piece.x || y == piece.y);
    });
}

bool isKnight(int x, int y, const std::vector<ChessPiece>& pieces) {
    int knight_dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int knight_dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; ++i) {
        int nx = x + knight_dx[i];
        int ny = y + knight_dy[i];

        if (std::any_of(pieces.begin(), pieces.end(), [nx, ny](const ChessPiece& piece) {
                return piece.type == 'N' && piece.x == nx && piece.y == ny;
            })) {
            return true;
        }
    }

    return false;
}

bool isBishop(int x, int y, const std::vector<ChessPiece>& pieces) {
    int dx[] = {-1, -1, 1, 1};
    int dy[] = {-1, 1, -1, 1};

    for (int k = 0; k < 4; ++k) {
        for (int j = 1; j < 8; ++j) {
            int nx = x + dx[k] * j;
            int ny = y + dy[k] * j;

            if (std::any_of(pieces.begin(), pieces.end(), [nx, ny](const ChessPiece& piece) {
                    return piece.type == 'B' && piece.x == nx && piece.y == ny;
                })) {
                return true;
            }
        }
    }

    return false;
}

bool isKing(int x, int y, const std::vector<ChessPiece>& pieces) {
    int king_dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int king_dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i) {
        int nx = x + king_dx[i];
        int ny = y + king_dy[i];

        if (std::any_of(pieces.begin(), pieces.end(), [nx, ny](const ChessPiece& piece) {
                return piece.type == 'K' && piece.x == nx && piece.y == ny;
            })) {
            return true;
        }
    }

    return false;
}

bool isQueen(int x, int y, const std::vector<ChessPiece>& pieces) {
    return std::any_of(pieces.begin(), pieces.end(), [x, y](const ChessPiece& piece) {
        return piece.type == 'Q' && (x == piece.x || y == piece.y || std::abs(x - piece.x) == std::abs(y - piece.y));
    });
}

int main() {
    std::vector<ChessPiece> pieces;

    for (int i = 0; i < 8; ++i) {
        std::string row;
        std::cin >> row;
        for (int j = 0; j < 8; ++j) {
            if (row[j] != 'O') {
                pieces.push_back(ChessPiece(row[j], i, j));
            }
        }
    }

    int Q;
    std::cin >> Q;

    std::vector<std::pair<int, int>> queries;
    for (int m = 0; m < Q; m++) {
        int a, b;
        std::cin >> a >> b;
        queries.push_back({a - 1, b - 1});
    }

    for (const auto& query : queries) {
        int x = query.first;
        int y = query.second;
        std::string answer;

        if (isOccupied(x, y, pieces)) {
            std::cout << "X" << std::endl;
        } else {
            for (char figure : "PRNBKQ") {
                switch (figure) {
                    case 'P':
                        if (isPawn(x, y, pieces)) {
                            answer += figure;
                        }
                        break;
                    case 'R':
                        if (isRook(x, y, pieces)) {
                            answer += figure;
                        }
                        break;
                    case 'N':
                        if (isKnight(x, y, pieces)) {
                            answer += figure;
                        }
                        break;
                    case 'B':
                        if (isBishop(x, y, pieces)) {
                            answer += figure;
                        }
                        break;
                    case 'K':
                        if (isKing(x, y, pieces)) {
                            answer += figure;
                        }
                        break;
                    case 'Q':
                        if (isQueen(x, y, pieces)) {
                            answer += figure;
                        }
                        break;
                }
            }

            if (answer.empty()) {
                std::cout << "O" << std::endl;
            } else {
                std::sort(answer.begin(), answer.end());
                std::cout << answer << std::endl;
            }
        }
    }

    return 0;
}