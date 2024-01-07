#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

bool bishop(const  char Chess_Field[8][8], int x, int y){
    for (int i = 1; i < 8; ++i) {
        if ((x + i < 8 && y + i < 8 && Chess_Field[x + i][y + i] == 'B') ||
            (x + i < 8 && y - i >= 0 && Chess_Field[x + i][y - i] == 'B') ||
            (x - i >= 0 && y + i < 8 && Chess_Field[x - i][y + i] == 'B') ||
            (x - i >= 0 && y - i >= 0 && Chess_Field[x - i][y - i] == 'B')) {
            return true;
        }
    }
    
    return false;
}

bool queen(const  char Chess_Field[8][8], int x, int y){
    for (int i = 0; i < 8; ++i) {
        if (Chess_Field[x][i] == 'Q' && i != y) {
            return true;
        }
    }
    
    for (int i = 0; i < 8; ++i) {
        if (Chess_Field[i][y] == 'Q' && i != x) {
            return true;
        }
    }
    
    for (int i = 1; i < 8; ++i) {
        if ((x + i < 8 && y + i < 8 && Chess_Field[x + i][y + i] == 'Q') ||
            (x + i < 8 && y - i >= 0 && Chess_Field[x + i][y - i] == 'Q') ||
            (x - i >= 0 && y + i < 8 && Chess_Field[x - i][y + i] == 'Q') ||
            (x - i >= 0 && y - i >= 0 && Chess_Field[x - i][y - i] == 'Q')) {
            return true;
        }
    }
    
    return false;
}

bool rook(const  char Chess_Field[8][8], int x, int y){
    for (int i = 0; i < 8; ++i) {
        if (Chess_Field[x][i] == 'R' && i != y) {
            return true;
        }
    }
    
    for (int i = 0; i < 8; ++i) {
        if (Chess_Field[i][y] == 'R' && i != x) {
            return true;
        }
    }
    
    return false;
}

bool pawn(const  char Chess_Field[8][8], int x, int y){
    if ((x > 0 && y > 0 && Chess_Field[x - 1][y - 1] == 'P')||
        (x > 0 && y < 7 && Chess_Field[x - 1][y + 1] == 'P')) {
        return true;
        }
    
    return false;
}

bool king(const  char Chess_Field[8][8], int x, int y){
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8 && Chess_Field[newX][newY] == 'K') {
            return true;
        }
    }

    return false;
}

bool knight(const  char Chess_Field[8][8], int x, int y){
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int i = 0; i < 8; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8 && Chess_Field[newX][newY] == 'N') {
            return true;
        }
    }

    return false;
}


int main(){
    char Chess_Field[8][8];

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> Chess_Field[i][j];
        }
    }
    

    int Coordinates;

    cin >> Coordinates;

    for(int i = 0; i < Coordinates; i++){
        int x, y;
        cin >> x >> y;
        x = x - 1;
        y = y - 1;
        string answer;
        if(x >= 0 && y <= 7){
            if(Chess_Field[x][y] != 'O'){
                cout << "X" << endl;
            }
            else{answer = "";
                if(knight(Chess_Field, x, y)){
                    answer += 'N';
                }
                if(king(Chess_Field, x, y)){
                    answer += 'K';
                }
                if(pawn(Chess_Field, x, y)){
                    answer += 'P';
                }
                if(rook(Chess_Field, x, y)){
                    answer += 'R';
                }
                if(queen(Chess_Field, x, y)){
                    answer += 'Q';
                }
                if(bishop(Chess_Field, x, y)){
                    answer += 'B';
                }
                if(answer.empty()){
                    answer = 'O';
                }
            }
            sort(answer.begin(), answer.end());
            cout << answer << endl;
        }
    }
    return 0 ;
}
