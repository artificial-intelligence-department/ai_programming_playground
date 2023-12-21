#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/////////////////////////////////////////////////////////////////////////////

string sort_destroy(string answer) {
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i]==answer[i+1]) {
            answer.erase(answer.begin()+i);
            i--;
        }
    }
    return answer;
}

/////////////////////////////////////////////////////////////////////////////

int main() {

    char board[8][8];
    int q, x, y;
    string foutput;

    for (int i = 0; i < 8; i++) {
        for (int j =0; j < 8; j++) {
        cin >> board[i][j];
        if (board[i][j] == 'O' || board[i][j] == 'P' || board[i][j] == 'R' ||
            board[i][j] == 'N' || board[i][j] == 'B' || board[i][j] == 'K' || board[i][j] == 'Q');
        else return 0;
        }
    }

    string output;

    cin >> q;
    if (q < 1 || q > 64) return 0;

    for (int i = 0; i < q; i++) {

        cin >> x >> y;
        if (x < 1 || x > 8 || y < 1 || y > 8) return 0;
        x -= 1;
        y -= 1;

/////////////////////////////////////////////////////////////////////////////

        if (board[x][y] != 'O') {
            output.push_back('X');
        }



        else {
/////////////////////////////////////////////////////////////////////////////        

        if((x-1>=0 && y-1>=0 && board[x-1][y-1] == 'P') || (x-1>=0 && y+1<=7 && board[x-1][y+1] == 'P')) {
            output.push_back('P');
        }

/////////////////////////////////////////////////////////////////////////////        

        for (int j = 0; j < 8; j++) {   //перевірка на королеву і туру

            if(board[j][y] == 'Q') {
                output.push_back('Q');
            }
            if(board[j][y] == 'R') {
                output.push_back('R');
            }
        }
            
        for (int j = 0; j < 8; j++) { 
            
            if(board[x][j] == 'Q') {
                output.push_back('Q');
            }
            if(board[x][j] == 'R') {
                output.push_back('R');
            }
        }

/////////////////////////////////////////////////////////////////////////////        

        int xx = x;
        int yy = y;

        while (xx < 8 && yy < 8) {
            if (board[xx][yy] == 'Q') {
                output.push_back('Q');
            }
            if (board[xx][yy] == 'B') {
                output.push_back('B');
            }
            xx++; yy++;
        }

        xx = x;
        yy = y;

        while (xx >= 0 && yy >= 0) {
            if (board[xx][yy] == 'Q') {
                output.push_back('Q');
            }
            if (board[xx][yy] == 'B') {
                output.push_back('B');
            }
            xx--; yy--;
        }

        xx = x;
        yy = y;

        while (xx < 8 && yy >= 0) {
            if (board[xx][yy] == 'Q') {
                output.push_back('Q');
            }
            if (board[xx][yy] == 'B') {
                output.push_back('B');
            }
            xx++; yy--;
        }

        xx = x;
        yy = y;

        while (xx >= 0 && yy < 8) {
            if (board[xx][yy] == 'Q') {
                output.push_back('Q');
            }
            if (board[xx][yy] == 'B') {
                output.push_back('B');
            }
            xx--; yy++;
        }

/////////////////////////////////////////////////////////////////////////////        

        int NmoveX[8] = {1, 1, -1, -1, 2, 2, -2, -2};
        int NmoveY[8] = {2, -2, 2, -2, 1, -1, 1, -1};

        for (int j = 0; j < 8; j++) {

            int moveX = x + NmoveX[j];
            int moveY = y + NmoveY[j];
            if (moveX < 8 && moveX >= 0 && moveY < 8 && moveY >= 0) {
                if (board[moveX][moveY] == 'N') {
                    output.push_back('N');
                }
            }
        }

/////////////////////////////////////////////////////////////////////////////

        int KmoveX[8] = {1, 1, 1, -1, -1, -1, 0, 0};
        int KmoveY[8] = {1, 0, -1, 1, 0, -1, 1, -1};

        for (int j = 0; j < 8; j++) {

            int moveX = x + KmoveX[j];
            int moveY = y + KmoveY[j];
            if (moveX < 8 && moveX >= 0 && moveY < 8 && moveY >= 0) {
                if (board[moveX][moveY] == 'K') {
                    output.push_back('K');
                }
            }
        }

/////////////////////////////////////////////////////////////////////////////    

    }
        if (output == "") {
            output.push_back('O');
        }

/////////////////////////////////////////////////////////////////////////////        

        foutput += sort_destroy(output) + "\n";
        output = "";
    }

    cout << foutput;
    return 0;
} 
