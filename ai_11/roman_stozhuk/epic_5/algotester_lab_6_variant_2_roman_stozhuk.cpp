#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    //Input figures
    vector<vector<char>> figures(8);
    for (short i = 0; i<8; i++) {
        figures[i].resize(8);
        for (short j = 0; j<8; j++) { cin >> figures[i][j]; }
    }
    //Input requests
    short req_quantity=0; cin >> req_quantity;
    vector<short> req_y(req_quantity), req_x(req_quantity);
    for (short i = 0; i<req_quantity; i++) {
        cin >> req_y[i] >> req_x[i];
        req_y[i]--;
        req_x[i]--;
    }
    vector<vector<char>> result(req_quantity);
    //Searching answer
    for (short cur_req = 0; cur_req < req_quantity; cur_req++) {
        //Something is here
        if(figures[req_y[cur_req]][req_x[cur_req]] != 'O') {
            result[cur_req].push_back('X');
        }
        //Something attacks it
        else {
            short x = req_x[cur_req], y = req_y[cur_req];
            //kings & pawns
            if (0 <= x-1 && x-1 < 8 && 0<=y-1 && y-1 < 8) {
                if (figures[y-1][x-1] == 'K')
                result[cur_req].push_back('K');
                if (figures[y-1][x-1] == 'P')
                result[cur_req].push_back('P');
            }
            if (0<=y-1 && y-1 < 8) {
                if (figures[y-1][x] == 'K')
                result[cur_req].push_back('K');
            }
            if (0 <= x+1 && x+1 < 8 && 0<=y-1 && y-1 < 8) {
                if (figures[y-1][x+1] == 'K')
                result[cur_req].push_back('K');
                if (figures[y-1][x+1] == 'P')
                result[cur_req].push_back('P');
            }
            if (0 <= x+1 && x+1 < 8) {
                if (figures[y][x+1] == 'K')
                result[cur_req].push_back('K');
            }
            if (0 <= x+1 && x+1 < 8 && 0<=y+1 && y+1 < 8) {
                if (figures[y+1][x+1] == 'K')
                result[cur_req].push_back('K');
            }
            if (0<=y+1 && y+1 < 8) {
                if (figures[y+1][x] == 'K')
                result[cur_req].push_back('K');
            }
            if (0 <= x-1 && x-1 < 8 && 0<=y+1 && y+1 < 8) {
                if (figures[y+1][x-1] == 'K')
                result[cur_req].push_back('K');
            }
            if (0 <= x-1 && x-1 < 8) {
                if (figures[y][x-1] == 'K')
                result[cur_req].push_back('K');
            }
            //knights
            if (0 <= x-1 && x-1 < 8 && 0<=y-2 && y-2 < 8) {
                if (figures[y-2][x-1] == 'N')
                result[cur_req].push_back('N');
            }
            if (0 <= x+1 && x+1 < 8 && 0<=y-2 && y-2 < 8) {
                if (figures[y-2][x+1] == 'N')
                result[cur_req].push_back('N');
            }
            if (0 <= x+2 && x+2 < 8 && 0<=y-1 && y-1 < 8) {
                if (figures[y-1][x+2] == 'N')
                result[cur_req].push_back('N');
            }
            if (0 <= x+2 && x+2 < 8 && 0<=y+1 && y+1 < 8) {
                if (figures[y+1][x+2] == 'N')
                result[cur_req].push_back('N');
            }
            if (0 <= x+1 && x+1 < 8 && 0<=y+2 && y+2 < 8) {
                if (figures[y+2][x+1] == 'N')
                result[cur_req].push_back('N');
            }
            if (0 <= x-1 && x-1 < 8 && 0<=y+2 && y+2 < 8) {
                if (figures[y+2][x-1] == 'N')
                result[cur_req].push_back('N');
            }
            if (0 <= x-2 && x-2 < 8 && 0<=y+1 && y+1 < 8) {
                if (figures[y+1][x-2] == 'N')
                result[cur_req].push_back('N');
            }
            if (0 <= x-2 && x-2 < 8 && 0<=y-1 && y-1 < 8) {
                if (figures[y-1][x-2] == 'N')
                result[cur_req].push_back('N');
            }
            //rooks and first half of queens
            for (short i = 0; i<8; i++) {
                    if (figures[i][x] == 'R')
                    result[cur_req].push_back('R');
                    if (figures[i][x] == 'Q')
                    result[cur_req].push_back('Q');
            }
            for (short j = 0; j<8; j++) {
                    if (figures[y][j] == 'R')
                    result[cur_req].push_back('R');
                    if (figures[y][j] == 'Q')
                    result[cur_req].push_back('Q');
            }
            //bishops and second half of queens
            while (1) {
                if (0 <= --x && x < 8 && 0<=--y && y < 8) {
                    if (figures[y][x] == 'B')
                    result[cur_req].push_back('B');
                    if (figures[y][x] == 'Q')
                    result[cur_req].push_back('Q');
                }
                else {x = req_x[cur_req], y = req_y[cur_req]; break;}
            }
            while (1) {
                if (0 <= ++x && x < 8 && 0<=--y && y < 8) {
                    if (figures[y][x] == 'B')
                    result[cur_req].push_back('B');
                    if (figures[y][x] == 'Q')
                    result[cur_req].push_back('Q');
                }
                else {x = req_x[cur_req], y = req_y[cur_req]; break;}
            }
            while (1) {
                if (0 <= ++x && x < 8 && 0<=++y && y < 8) {
                    if (figures[y][x] == 'B')
                    result[cur_req].push_back('B');
                    if (figures[y][x] == 'Q')
                    result[cur_req].push_back('Q');
                }
                else {x = req_x[cur_req], y = req_y[cur_req]; break;}
            }
            while (1) {
                if (0 <= --x && x < 8 && 0<=++y && y < 8) {
                    if (figures[y][x] == 'B')
                    result[cur_req].push_back('B');
                    if (figures[y][x] == 'Q')
                    result[cur_req].push_back('Q');
                }
                else {x = req_x[cur_req], y = req_y[cur_req]; break;}
            }

            if(result[cur_req].empty()) {result[cur_req].push_back('O'); }
            else {
                sort(result[cur_req].begin(), result[cur_req].end());
                for (short i = 0; i+1<result[cur_req].size(); i++){
                    if (result[cur_req][i] != result[cur_req][i+1]) {cout << result[cur_req][i]; }
                }
            }
        }
        cout << result[cur_req][result[cur_req].size()-1] << '\n';
    }
    return 0;
}