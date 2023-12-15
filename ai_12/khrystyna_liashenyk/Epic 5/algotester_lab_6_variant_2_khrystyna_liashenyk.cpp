#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool canMovePawn(int x, int y, const string board[]) {
    if ((x-1>=0 && y-1>=0 && board[x-1][y-1]=='P')||(x-1>=0 && y+1<8 && board[x-1][y+1]=='P')) {
        return true;
    }
    return false;
}

bool canMoveRook(int x, int y, const string board[]) {
   for (int i = x - 1; i >= 0; --i) {
        if (board[i][y] == 'R') {
             return true;  
    } 
}
for (int i = x + 1; i < 8; ++i) {
        if (board[i][y] == 'R' ) {
             return true;
    } 
}

for (int j = y - 1; j >= 0; --j) {
   
        if (board[x][j] == 'R' ){
            return true;   
    } 
}

for (int j = y + 1; j < 8; ++j) {
        if (board[x][j] == 'R' ) {
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
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && (board[nx][ny] == 'N')) {
                return true;
            }
        }
    return false;
}

bool canMoveBishop(int x, int y, const string board[]) {
    int dx[] = {-1, -1, 1, 1};
        int dy[] = {-1, 1, -1, 1};
        for (int k = 0; k < 4; ++k) {
            for (int j = 1; j < 8; ++j) {
                int nx = x + dx[k] * j;
                int ny = y + dy[k] * j;
                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                    if (board[nx][ny] == 'B' ) {
                        return true;
                    }
                } 
            }
        }

    return false;
}


bool canMoveKing(int x, int y, const string board[]){
     int king_dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int king_dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < 8; ++i) {
            int nx = x + king_dx[i];
            int ny = y + king_dy[i];
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && (board[nx][ny] == 'K' )) {
               return true;
            }
        }
    return false;
}

bool canMoveQueen(int x, int y, const string board[]){
   for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 'Q') {
           return true;
    }
}
for (int i = x - 1, j = y + 1; i >= 0 && j < 8; --i, ++j) {
        if (board[i][j] == 'Q') {
             return true; 
    }
}
for (int i = x + 1, j = y - 1; i < 8 && j >= 0; ++i, --j) {
        if (board[i][j] == 'Q') {
            return true;
    }
}
for (int i = x + 1, j = y + 1; i < 8 && j < 8; ++i, ++j) {
        if (board[i][j] == 'Q') {
            return true;
    }
}
for (int i = x - 1; i >= 0; --i) {
        if (board[i][y] == 'Q') {
            return true; 
    }  
}
for (int i = x + 1; i < 8; ++i) {
        if (board[i][y] == 'Q') {
             return true;   
    }  
}
for (int j = y - 1; j >= 0; --j) {
        if (board[x][j] == 'Q') {
            return true;  
    }  
}
for (int j = y + 1; j < 8; ++j) {
        if (board[x][j] == 'Q') {
            return true; 
    }
      
}
 return false;
}

int main() {
    string board[20];
    for (int i = 0; i < 8; i++) {
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
    vector<string> answers;
    for (const auto& query : queries) {
        int x = query.first;
        int y = query.second;
        string answer;
        if (board[x][y] != 'O') {
            answers.push_back("X");
        } else {
            string figures = "PRNBKQ";

            for (char figure : figures) {
                switch (figure) {
                    case 'P':
                        if (canMovePawn(x, y, board)) {
                            answer += figure;
                        }
                        break;
                    case 'R':
                        if (canMoveRook(x, y, board)) {
                            answer += figure;
                        }
                        break;
                    case 'N':
                        if (canMoveKnight(x, y, board)) {
                            answer += figure;
                        }
                        break;
                    case 'B':
                        if (canMoveBishop(x, y, board)) {
                            answer += figure;
                        }
                        break;
                    case 'K':
                        if (canMoveKing(x, y, board)) {
                            answer += figure;
                        }
                        break;
                    case 'Q':
                        if (canMoveQueen(x, y, board)) {
                            answer += figure;
                        }
                        break;
                    default:
                        break;
                }
            }

            if (answer.empty()) {
                answers.push_back("O");
            } else {
                sort(answer.begin(), answer.end());
                answers.push_back(answer);
            }
        }
    }

    for (const auto& ans : answers) {
        cout << ans << endl;
    }

    return 0;
}

