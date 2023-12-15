#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void paint_the_landscape(int r, int c, int X, int Y) {
    vector<vector<int>> land(r, vector<int>(c, -1));
    queue<pair<int, int>> queue_mountain;
    queue_mountain.push({X - 1, Y - 1});
    land[X - 1][Y - 1] = 0;
    const int x[] = {1, -1, 0, 0};
    const int y[] = {0, 0, 1, -1};
    while (!queue_mountain.empty()) {
        pair<int, int> current = queue_mountain.front();
        queue_mountain.pop();
        for (int i = 0; i < 4; ++i) {
            int new_X = current.first + x[i];
            int new_Y = current.second + y[i];
            if (new_X >= 0 && new_X < r && new_Y >= 0 && new_Y < c && land[new_X][new_Y] == -1) {
                land[new_X][new_Y] = land[current.first][current.second] + 1;
                queue_mountain.push({new_X, new_Y});
            }
        }
    }
    int max_height = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            max_height = max(max_height, land[i][j]);
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << max_height - land[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int MIN = 1;
    int MAX = 1000;
    int r, c, X, Y;
    cin >> r >> c;
    cin >> X >> Y;
    if (r >= MIN && r <= MAX && c >= MIN && c <= MAX &&
        X >= MIN && X <= r && Y >= MIN && Y <= c) {
        paint_the_landscape(r, c, X, Y);
    } else {
        cout << "Invalid input, please try again.";
    }
    return 0;
}
