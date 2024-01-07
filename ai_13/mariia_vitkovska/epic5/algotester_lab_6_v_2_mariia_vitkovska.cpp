#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

class Square {
public:
    uint8_t x;
    uint8_t y;

    Square(uint8_t x, uint8_t y) {
        if (x >= 8 || y >= 8) {
            std::cout << "Invalid square, x=" << x << ", y=" << y;
            exit(1);
        }
        this->x = x;
        this->y = y;
    }
};

class Chessboard {
private:
    vector<vector<char>> board;
public:
    Chessboard() : board(8, vector<char>(8, 'O')) {}

    char getPiece(const Square& square) const {
        return board[square.y][square.x];
    }

    void setPiece(const Square& square, char piece) {
        board[square.y][square.x] = piece;
    }

    bool attacks(const Square& target, const Square& attacker) const {
        uint8_t diffXAbs = std::abs(target.x - attacker.x);
        uint8_t diffYAbs = std::abs(target.y - attacker.y);

        if (diffXAbs + diffYAbs == 0) {
            std::cout << "Asked if a square attacks itself, x=" << target.x << ", y=" << target.y;
            exit(1);
        }

        switch (getPiece(attacker)) {
            case 'O':
                return false;
            case 'P':
                return target.y == attacker.y + 1 && diffXAbs == 1;
            case 'R':
                return target.y == attacker.y || target.x == attacker.x;
            case 'N':
                return diffXAbs + diffYAbs == 3 && (diffXAbs == 1 || diffYAbs == 1);
            case 'B':
                return diffXAbs == diffYAbs;
            case 'K':
                return std::max(diffXAbs, diffYAbs) == 1;
            case 'Q':
                return diffXAbs == diffYAbs || target.y == attacker.y || target.x == attacker.x;
            default:
                std::cout << "Invalid attacker piece: " << getPiece(attacker);
                exit(1);
        }
    }
};

int main() {
    Chessboard chessboard;

    cout << "Enter the chessboard state (8 rows):" << endl;
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            char piece;
            cin >> piece;
            chessboard.setPiece(Square(x, y), piece);
        }
    }
    int i;
    std::cin >> i;

    while (i-- > 0) {
        int x, y;
        std::cin >> y >> x;
        Square target(x - 1, y - 1);

        if (chessboard.getPiece(target) != 'O') {
            std::cout << 'X' << std::endl;
            continue;
        }

        std::vector<char> attackers;
        for (int squareX = 0; squareX < 8; squareX++) {
            for (int squareY = 0; squareY < 8; squareY++) {
                Square attacker(squareX, squareY);
                if (chessboard.getPiece(attacker) != 'O' && chessboard.attacks(target, attacker)) {
                    attackers.push_back(chessboard.getPiece(attacker));
                }
            }
        }

        if (attackers.empty()) {
            std::cout << 'O' << std::endl;
        } else {
            std::sort(attackers.begin(), attackers.end());
            attackers.erase(std::unique(attackers.begin(), attackers.end()), attackers.end());
            for (char attacker: attackers) {
                std::cout << attacker;
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
