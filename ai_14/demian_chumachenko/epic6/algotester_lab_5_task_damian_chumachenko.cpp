#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Peak{
    int row;
    int col;
};

int main() {
    int H = 3, W = 4;
    int row = 2, col = 2;
    int maxHeight;

    cin >> H >> W;
    cin >> row >> col;
    Peak peak = {row-1, col-1};

    vector<std::vector<int>> myVector(H, vector<int>(W, 0));

    maxHeight = max({(W-col)+(H-row), (W-col)+peak.row, peak.row+peak.col, peak.col+(H-row)});

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            myVector[i][j] = maxHeight - abs(row-1-i) - abs(col-1-j);
            cout << myVector[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}