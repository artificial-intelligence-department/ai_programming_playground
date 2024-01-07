#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

vector<char> get_attacking_figures(vector<string>& board, int x, int y) {
    set<char> attacking_figures;

    if (board[x][y] != 'O') {
        return {'X'};
    }
    
    else {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                char figure = board[i][j];
                if (figure != 'O') {

                    if (figure == 'P' && (abs(i - x == -1 && abs(j - y) == 1))) {
                        attacking_figures.insert(figure);
                    }

                    else if (figure == 'R' && (i == x || j == y)) {
                        attacking_figures.insert(figure);
                    }
                
                    else if (figure == 'N' && ((abs(i - x) == 2 && abs(j - y) == 1) || (abs(i - x) == 1 && abs(j - y) == 2))) {
                        attacking_figures.insert(figure);
                    }
                
                    else if (figure == 'B' && abs(i - x) == abs(j - y) && board[x][y]!='B' ) {
                        attacking_figures.insert(figure);
                    }
                
                    else if (figure == 'K' && abs(i - x) <= 1 && abs(j - y) <= 1 && (abs(i - x) != 0 || abs(j - y) != 0)) {
                        attacking_figures.insert(figure);
                    }
                
                    else if (figure == 'Q' && ((i == x || j == y || abs(i - x) == abs(j - y)) && board[x][y]!='Q')) {
                        attacking_figures.insert(figure); 
                    }

                    else if ((board[x][y]=='O'))
                        attacking_figures.insert('O');
                }
            }
        }
    }
    if(attacking_figures.size()>1) {
        attacking_figures.erase('O');
    }
    vector<char> result(attacking_figures.begin(), attacking_figures.end());
    sort(result.begin(), result.end());
    return result;
    
}

int main() {
    vector<string> board(9);
    
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }

    int Q;
    cin >> Q;
    int count=(Q*2)-1;
    int arr[count];
    int x, y;

    for (int q=0; q < count; q+=2) {
        cin >> x >> y;
        arr[q-1]=x;
        arr[q]=y;
        vector<char> result = get_attacking_figures(board, arr[q-1]-1, arr[q]-1);
        for (char figure : result) {
            cout << figure;
        }
        cout << endl;
    }
    return 0;
}