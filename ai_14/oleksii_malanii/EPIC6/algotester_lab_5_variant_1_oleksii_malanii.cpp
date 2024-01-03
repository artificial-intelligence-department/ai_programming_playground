#include <iostream>
#include <vector>
using namespace std;
int main() {
    int height, width;
    cin >> height >> width;
    vector<vector<char>> caveMap(height, vector<char>(width));
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            cin >> caveMap[row][col];
        }
    }
    for (int row = height - 1; row >= 0; --row) {
        for (int col = 0; col < width; ++col) {
            if (caveMap[row][col] == 'S') {
                int nextRow = row + 1;
                while (nextRow < height && caveMap[nextRow][col] == 'O') {
                    ++nextRow;
                }
                --nextRow;
                bool stoneBelow = false;
                for (int checkRow = row + 1; checkRow < nextRow; ++checkRow) {
                    if (caveMap[checkRow][col] == 'X') {
                        stoneBelow = true;
                        break;
                    }
                }
                if (!stoneBelow) {
                    caveMap[row][col] = 'O';
                    caveMap[nextRow][col] = 'S';
                }
            }
        }
    }
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            cout << caveMap[row][col];
        }
        cout << endl;
    }
    return 0;
}

