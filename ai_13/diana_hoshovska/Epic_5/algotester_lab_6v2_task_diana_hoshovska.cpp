#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    string row[18]; //дошка
    int Qn;
    for (int i = 0; i < 8; i++){
        cin >> row[i]; //стан рядків
    }

    cin >> Qn;
    for (int i = 0; i < Qn; i++){
        string result;
        int x=0, y=0, n = 0;
        cin >> x >> y;
        x-=1; y-=1;
        result.resize(18);
        if (row[x][y] != 'O'){
            cout << 'X';
        }
        else{
            bool 
            P = false,
            R = false,
            N = false,
            B = false,
            K = false,
            Q = false;

            //pawn
            if((((x-1>=0 && y-1>=0) && x > 0 && y > 0) && row[x-1][y-1] == 'P') 
            || ((x-1>=0 && y+1 < 8) && x > 0 && (row[x-1][y+1]) == 'P')){
                P = true;
            }

            //rook
            for (int j = 0; j < 8; j++){
                if (row[x][j] == 'R' || row[j][y] == 'R' ){
                    R = true;
                }
            }

            //horse
            if ((x+2 < 8 && y-1>=0) && y > 0 && (row[x+2][y-1] == 'N')
            || ((x+1 < 8 && y-2>=0) && y > 1 && row[x+1][y-2] == 'N') 
            || ((x-2 >= 0 && y+1 < 8) && x > 1 && row[x-2][y+1] == 'N') 
            || ((x-1 >=0 && y+2<8) && x > 0 && row[x-1][y+2] == 'N')
            || ((x+2 < 8 && y+1 < 8) && row[x+2][y+1] == 'N') 
            || ((x+1 < 8 && y+2 < 8) && row[x+1][y+2] == 'N')
            || ((x-2 >=0 && y-1>=0) && (x > 1 && y > 0) && row[x-2][y-1] == 'N')
            || ((x-1 >=0 && y-2>=0) && (x > 0 && y > 1) && row[x-1][y-2] == 'N') ){
                N = true;
            }

            //officer
            for (int j = 0; j < 8; j++) {
                if ((x+j<8 && y+j<8 && row[x + j][y + j] == 'B') ||
                (x-j>=0 && y+j<8 && row[x - j][y + j] == 'B') ||
                (x+j<8 && y-j>=0 && row[x + j][y - j] == 'B') ||
                (x-j>=0 && y-j>=0 && row[x - j][y - j] == 'B')) {
                    B = true;
                }
            }

            //king
            if ((y+1 < 8) && (row[x][y+1] == 'K')
            || ((x+1 < 8) && row[x+1][y] == 'K')
            || ((x+1 < 8 && y+1 < 8) && row[x+1][y+1] == 'K')
            || ((x-1 >=0 && y+1 < 8) && (x>0) && row[x-1][y+1] == 'K')
            || ((x-1 >=0) && (x>0) && row[x-1][y] == 'K')
            || ((x+1 < 8 && y-1 >= 0) && (y>0) && row[x+1][y-1] == 'K')
            || ((y-1 >= 0) && (y>0) && row[x][y-1] == 'K')
            || ((x-1 >=0 && y-1 >=0) && (x>0 && y>0) && row[x-1][y-1] == 'K') ){
                K = true;
            }


            // queen
            for (int j = 0; j < 8; j++) {
            if (row[x][j] == 'Q' ||
            row[j][y] == 'Q' ||
            (x + j < 8 && y + j < 8 && row[x + j][y + j] == 'Q') ||
            (x - j >= 0 && y + j < 8 && row[x - j][y + j] == 'Q') ||
            (x + j < 8 && y - j >= 0 && row[x + j][y - j] == 'Q') ||
            (x - j >= 0 && y - j >= 0 && row[x - j][y - j] == 'Q')) {
            Q = true;
        }
        }
            if(P){
                result[n] = 'P';
                n++;
            }
            if(R){
                result[n] = 'R';
                n++;
            }
            if(N){
                result[n] = 'N';
                n++;
            }
            if(B){
                result[n] = 'B';
                n++;
            }
            if(K){
                result[n] = 'K';
                n++;
            }
            if(Q){
                result[n] = 'Q';
                n++;
            }
        }
        if(n == 0 && row[x][y] == 'O'){
            cout << 'O';
        }
        else{
            result.resize(n);
            sort(result.begin(), result.end());
            cout << result;
        }
        cout << endl;
    }
}