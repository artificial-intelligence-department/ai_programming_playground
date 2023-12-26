#include <iostream>
#include <vector>
using namespace std;

void bishop(int &y, int &x, char desk[8][8], vector<char> &result) {
    int dir1[4][2] = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    for (int i = 0; i < 4; ++i) {
        for (int j = 1; y + j * dir1[i][0] >= 0 && y + j * dir1[i][0] < 8 && x + j * dir1[i][1] >= 0 && x + j * dir1[i][1] < 8; ++j) {
            if (desk[y + j * dir1[i][0]][x + j * dir1[i][1]] == 'B') {
                result.push_back('B');
                return;
            }
        }
    }
}

void king(int &y, int &x, char desk[8][8], vector<char> &result) {
    int dir2[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    for (int i = 0; i < 8; ++i) {
        int ny = y + dir2[i][0], nx = x + dir2[i][1];
        if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && desk[ny][nx] == 'K') {
            result.push_back('K');
            break;
        }
    }
}

void queen(int &y, int &x, char desk[8][8], vector<char> &result) {
    int dir4[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    for (int i = 0; i < 4; ++i) {
        for (int j = 1; y + j * dir4[i][0] >= 0 && y + j * dir4[i][0] < 8 && x + j * dir4[i][1] >= 0 && x + j * dir4[i][1] < 8; ++j) {
            if (desk[y + j * dir4[i][0]][x + j * dir4[i][1]] == 'Q') {
                result.push_back('Q');
                return;
            }
        }
    }
    for (int j = 0; j < 8; ++j) {
        if ((y >= 0 && y < 8 && desk[y][j] == 'Q') || (j >= 0 && j < 8 && desk[j][x] == 'Q')) {
            result.push_back('Q');
            return;
        }
    }
}

void rook(int &y, int &x, char desk[8][8], vector<char> &result) {
    int dir5[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int i = 0; i < 4; ++i) {
        for (int j = 1; y + j * dir5[i][0] >= 0 && y + j * dir5[i][0] < 8 && x + j * dir5[i][1] >= 0 && x + j * dir5[i][1] < 8; ++j) {
            if (desk[y + j * dir5[i][0]][x + j * dir5[i][1]] == 'R') {
                result.push_back('R');
                return;
            }
        }
    }
}

void CheckFigureOnSquare(int y, int x, char desk[8][8], vector<char> &result) {
    bishop(y, x, desk, result);
    king(y, x, desk, result);
    int dir3[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    for (int i = 0; i < 8; ++i) {
        int ny = y + dir3[i][0], nx = x + dir3[i][1];
        if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && desk[ny][nx] == 'N') {
            result.push_back('N');
            break;
        }
    }
    if ((y - 1 >= 0 && x + 1 < 8 && desk[y - 1][x + 1] == 'P') || (y - 1 >= 0 && x - 1 >= 0 && desk[y - 1][x - 1] == 'P'))
        result.push_back('P');
    queen(y, x, desk, result);
    rook(y, x, desk, result);
}

int main() {
    char desk[8][8];
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            cin >> desk[i][j];

    int q;
    cin >> q;
    int inputs[q][2];
    for (int i = 0; i < q; ++i)
        for (int j = 0; j < 2; ++j)
            cin >> inputs[i][j];

    for (int i = 0; i < q; ++i) {
        int y = inputs[i][0] - 1, x = inputs[i][1] - 1;
        vector<char> result;

        if (desk[y][x] != 'O') cout << 'X' << endl;
        else {
            CheckFigureOnSquare(y, x, desk, result);

            if (result.empty()) cout << "O";
            else for (char a : result) cout << a;
            cout << endl;
        }
    }

    return 0;
}


