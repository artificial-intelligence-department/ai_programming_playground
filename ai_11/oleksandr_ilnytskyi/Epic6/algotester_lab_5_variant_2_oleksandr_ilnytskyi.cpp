#include <iostream>
#include <vector>

using namespace std;

int main() {
    int height, width;
    cin >> height;
    cin >> width;
    vector<vector<char>> cave(width, vector<char>(height));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cin >> cave[x][y];
        }
    }

    for (int x = 0; x < width; x++) {
        int sCount = 0;
        int y = 0;
        while (y <= height - 1) {
            if (cave[x][y] == 'S') {
                sCount += 1;
                cave[x][y] = 'O';
                if (y == height - 1) {
                    for (int i = 0; i < sCount; i++) {
                        cave[x][y - i] = 'S';
                    }
                }
                y += 1;
            } else if (cave[x][y] == 'X') {
                for (int i = 1; i <= sCount; i++) {
                    cave[x][y - i] = 'S';
                }
                sCount = 0;
                y += 1;
            } else if (y == height - 1) {
                for (int i = 0; i < sCount; i++) {
                    cave[x][y - i] = 'S';
                }
                y += 1;
            } else {
                y += 1;
            }
        }
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cout << cave[x][y];
        }
        cout << endl;
    }

    return 0;
}