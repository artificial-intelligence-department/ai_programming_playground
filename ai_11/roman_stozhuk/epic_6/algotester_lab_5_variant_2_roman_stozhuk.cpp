#include <iostream>
#include <vector>

using namespace std;

int main() {
    short rows, columns;
    cin >> rows >> columns;
    vector<vector<char>> cave(rows);
    for (short i = 0; i<rows; i++) {
        cave[i].resize(columns);
        for (short j=0; j<columns; j++) {cin >> cave[i][j];}
    }
    for (short j=0; j<columns; j++) {
        for (short i=rows-1; i>=0; i--) {
            if((cave[i][j] == 'S') && (i+1<rows) && (cave[i+1][j] == 'O')) {
                char tmp = cave[i][j];
                cave[i][j] = cave[i+1][j];
                cave[i+1][j] = tmp;
                i=rows-1;
            }
        }
    }
    for (short i=0; i<rows; i++) {
        for (short j=0; j<columns; j++) {
            cout << cave[i][j];
        }
        std::cout << '\n';
    }
    return 0;
}