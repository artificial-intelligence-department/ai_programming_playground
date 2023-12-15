#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    int n = 8;
    vector<vector<char>> vec_chess_board (n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vec_chess_board[i][j];
        }
    }

    map<char, vector<vector<int>>> map_chess_board;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map_chess_board[vec_chess_board[i][j]].push_back({i, j});
        }
    }

    int m; cin >> m;
    for (int k = 0; k < m; k++) {
        set<char> letters;
        int x, y; cin >> x; x--; cin >> y; y--;

        if (vec_chess_board[x][y] != 'O') {
            cout << 'X' << '\n';
        } else {

            // Pawn
            if (map_chess_board.find('P') != map_chess_board.end()) {
                for (int i = 0; i < map_chess_board['P'].size(); i++) {
                    if (map_chess_board['P'][i][0] + 1 == x && abs(map_chess_board['P'][i][1] - y) == 1) {
                        letters.insert('P');
                    }
                }
            }

            // Rook
            if (map_chess_board.find('R') != map_chess_board.end()) {
                for (int i = 0; i < map_chess_board['R'].size(); i++) {
                    if (map_chess_board['R'][i][0] == x  || map_chess_board['R'][i][1] == y) {
                        letters.insert('R');
                    }
                }
            }

            // Knight
            if (map_chess_board.find('N') != map_chess_board.end()) {
                for (int i = 0; i < map_chess_board['N'].size(); i++) {
                    int dx = abs(map_chess_board['N'][i][0] - x);
                    int dy = abs(map_chess_board['N'][i][1] - y);
                    if (dx == 1 && dy == 2 ||  dx == 2 && dy == 1) {
                        letters.insert('N');
                    }
                }
            }

            // Bishop
            if (map_chess_board.find('B') != map_chess_board.end()) {
                for (int i = 0; i < map_chess_board['B'].size(); i++) {
                    if (abs(map_chess_board['B'][i][0] - x) == abs(map_chess_board['B'][i][1] - y)) {
                        letters.insert('B');
                    }
                }
            }

            // King
            if (map_chess_board.find('K') != map_chess_board.end()) {
                for (int i = 0; i < map_chess_board['K'].size(); i++) {
                    if (abs(map_chess_board['K'][i][0] - x) <= 1 && abs(map_chess_board['K'][i][1] - y) <= 1) {
                        letters.insert('K');
                    }
                }
            }

            // Queen
            if (map_chess_board.find('Q') != map_chess_board.end()) {
                for (int i = 0; i < map_chess_board['Q'].size(); i++) {
                    if (abs(map_chess_board['Q'][i][0] - x) == abs(map_chess_board['Q'][i][1] - y) ||
                        map_chess_board['Q'][i][0] == x || map_chess_board['Q'][i][1] == y) {
                        letters.insert('Q');
                    }
                }
            }

            if (letters.empty()) {
                cout << 'O' << '\n';
            }
            else
                for (auto ch : letters) {
                    cout << ch;
                }
                cout << endl;

        }
    }

    return 0;
}