#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

char Capture(int a, int b, int c, int d) {
    return (a == c && b == d) ? 'X' : 0;
}
char pawn(int a, int b, int c, int d) {
    return Capture(a, b, c, d) ? 'X' : (c - a == 1 && abs(d - b) == 1) ? 'P' : 0;
}
char rook(int a, int b, int c, int d) {
    return Capture(a, b, c, d) ? 'X' : (a == c || b == d) ? 'R' : 0;
}
char bishop(int a, int b, int c, int d) {
    return Capture(a, b, c, d) ? 'X' : (abs(a - c) == abs(b - d)) ? 'B' : 0;
}
char knight(int a, int b, int c, int d) {
    return Capture(a, b, c, d) ? 'X' : (abs(a - c) == 2 && abs(d - b) == 1) || (abs(a - c) == 1 && abs(d - b) == 2) ? 'N' : 0;
}
char queen(int a, int b, int c, int d) {
    return Capture(a, b, c, d) ? 'X' : (a == c || b == d || abs(a - c) == abs(b - d)) ? 'Q' : 0;
}
char king(int a, int b, int c, int d) {
    return Capture(a, b, c, d) ? 'X' : (abs(a - c) <= 1 && abs(b - d) <= 1) ? 'K' : 0;
}
bool BoardEmpty(const std::string& str) {
    return std::all_of(str.begin(), str.end(), [](char c) {
        return c == '.';
    });
}
int main() {
    using namespace std;
    char board[8][8];
    vector<char> sym;
    vector<int> position1;
    vector<int> position2;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
            if (board[i][j] != 'O') {
                sym.push_back(board[i][j]);
                position1.push_back(i + 1);
                position2.push_back(j + 1);
            }
        }
    }
    int n, x, y;
    cin >> n;

    for (int t = 0; t < n; t++) {
        cin >> x >> y;
        string answer;
              
        for (int i = 0; i < sym.size(); i++) {
            char resultChar = 0;

            switch (sym[i]) {
                case 'P':
                    resultChar = pawn(position1[i], position2[i], x, y);
                    break;
                case 'R':
                    resultChar = rook(position1[i], position2[i], x, y);
                    break;
                case 'B':
                    resultChar = bishop(position1[i], position2[i], x, y);
                    break;
                case 'N':
                    resultChar = knight(position1[i], position2[i], x, y);
                    break;
                case 'Q':
                    resultChar = queen(position1[i], position2[i], x, y);
                    break;
                case 'K':
                    resultChar = king(position1[i], position2[i], x, y);
                    break;
            }
            if (resultChar) {
                answer += resultChar;
            }
        }

        if (BoardEmpty(answer)) {
            cout << 'O' << endl;
        } else if (answer.find('X') != string::npos) {
            cout << "X" << endl;
        } else {
            sort(answer.begin(), answer.end());
            auto it = unique(answer.begin(), answer.end());
            answer.erase(it, answer.end());
            cout << answer << endl;
        }
    }

    return 0;
}