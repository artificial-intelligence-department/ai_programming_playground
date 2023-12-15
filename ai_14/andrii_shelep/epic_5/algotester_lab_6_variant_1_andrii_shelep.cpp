#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cond_Q(int x, int y, char board[8][8]);
bool cond_N(int x, int y, char board[8][8]);
bool cond_R(int x, int y, char board[8][8]);
bool cond_B(int x, int y, char board[8][8]);
bool cond_P(int x, int y, char board[8][8]);
bool cond_K(int x, int y, char board[8][8]);

int main(){
    char board[8][8];
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> board[i][j];
        }
    }
    int req, x, y;
    cin >> req;
    for(int i = 0; i < req; i++){
        cin >> x >> y;
        x--;
        y--;
        if(board[x][y]!='O'){
            cout << "X" << endl;
        } else{
            string figures="";
            if(cond_Q(x, y, board)){
                figures += "Q";
            }
            if(cond_N(x, y, board)){
                figures+="N";
            }
            if(cond_R(x, y, board)){
                figures+="R";
            }
            if(cond_B(x, y, board)){
                figures+="B";
            }
            if(cond_P(x, y, board)){
                figures+="P";
            }
            if(cond_K(x, y, board)){
                figures+="K";
            }
            if(!cond_Q(x, y, board) && !cond_N(x, y, board) && !cond_R(x, y, board) && !cond_B(x, y, board) && !cond_P(x, y, board) && !cond_K(x, y, board))
                figures+="O";
            
            sort(figures.begin(), figures.end());
            cout << figures << endl;
        }
    }
    return 0;
}

bool cond_Q(int x, int y, char board[8][8]){
    //по діагоналях
    for(int i = x+1, j = y+1; i < 8 && j<8; i++, j++){
        if(board[i][j]=='Q')
            return true;
    }
    for(int i = x-1, j = y-1; i>= 0 && j>=0; i--, j--){
        if(board[i][j]=='Q')
            return true;
    }
    for(int i = x-1, j = y+1; i >= 0 && j<8; i--, j++){
        if(board[i][j]=='Q')
            return true;
    }
    for(int i = x+1, j = y-1; i < 8 && j>=0; i++, j--){
        if(board[i][j]=='Q')
            return true;
    }
    //по вертикалі
    for(int i = 0, j = y; i < 8; i++){
        if(board[i][j]=='Q')
            return true;
    }
    //по горизонталі
    for(int i = x, j = 0; j<8; j++){
        if(board[i][j]=='Q')
            return true;
    }
    return false;
}
bool cond_N(int x, int y, char board[8][8]){
    if((x-1>=0 && y-2>=0 && board[x-1][y-2]=='N') ||
        (x-2>=0 && y-1>=0 && board[x-2][y-1]=='N') ||
        (x-2>=0 && y+1<8 && board[x-2][y+1]=='N') ||
        (x-1>=0 && y+2<8 && board[x-1][y+2]=='N') ||
        (x+1<8 && y+2<8 && board[x+1][y+2]=='N') ||
        (x+2<8 && y+1<8 && board[x+2][y+1]=='N') ||
        (x+2<8 && y-1>=0 && board[x+2][y-1]=='N') ||
        (x+1<8 && y-2>=0 && board[x+1][y-2]=='N')){
            return true;
        }
    return false;
};
bool cond_R(int x, int y, char board[8][8]){
    //по вертикалі
    for(int i = 0, j = y; i < 8; i++){
        if(board[i][j]=='R')
            return true;
    }
    //по горизонталі
    for(int i = x, j = 0; j<8; j++){
        if(board[i][j]=='R')
            return true;
    }
    return false;
}
bool cond_B(int x, int y, char board[8][8]){
    //по діагоналях
    for(int i = x+1, j = y+1; i < 8 && j<8; i++, j++){
        if(board[i][j]=='B')
            return true;
    }
    for(int i = x-1, j = y-1; i>= 0 && j>=0; i--, j--){
        if(board[i][j]=='B')
            return true;
    }
    for(int i = x-1, j = y+1; i >= 0 && j<8; i--, j++){
        if(board[i][j]=='B')
            return true;
    }
    for(int i = x+1, j = y-1; i < 8 && j>=0; i++, j--){
        if(board[i][j]=='B')
            return true;
    }
    return false;
}
bool cond_P(int x, int y, char board[8][8]){
    if(x-1>=0 && y-1>=0 && board[x-1][y-1]=='P')
        return true;
    if(x-1>=0 && y+1<8 && board[x-1][y+1]=='P')
        return true;
    return false;
}
bool cond_K(int x, int y, char board[8][8]){
    //if(x-1>=0){
        if(x-1 >= 0 && y-1>=0 && board[x-1][y-1]=='K')
            return true;
        if(x-1 >= 0 && board[x-1][y]=='K')
            return true;
        if(x-1 >= 0 && y+1<8 && board[x-1][y+1]=='K')
            return true;
    //}
    if(y-1>=0 && board[x][y-1]=='K')
        return true;
    if(y+1<8 && board[x][y+1]=='K')
        return true;
    //if(x+1<8){
        if(x+1<8 && y-1>=0 && board[x+1][y-1]=='K')
            return true;
        if(x+1<8 && board[x+1][y]=='K')
            return true;
        if(x+1<8 && y+1<8 && board[x+1][y+1]=='K')
            return true;
    //}
    return false;
}