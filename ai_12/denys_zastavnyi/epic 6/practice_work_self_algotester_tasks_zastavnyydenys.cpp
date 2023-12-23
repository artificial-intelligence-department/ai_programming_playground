#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void generate_landscape(int rows, int cols, int start_row, int start_col) {
    vector<vector<int>> heights(rows, vector<int>(cols, -1));

    queue<pair<int, int>> mountain_queue;
    mountain_queue.push({start_row - 1, start_col - 1});

    heights[start_row - 1][start_col - 1] = 0;

    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    while (!mountain_queue.empty()) {
        pair<int, int> current = mountain_queue.front();
        mountain_queue.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && heights[nx][ny] == -1) {
                heights[nx][ny] = heights[current.first][current.second] + 1;
                mountain_queue.push({nx, ny});
            }
        }
    }
    int max_height = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            max_height = max(max_height, heights[i][j]);
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << max_height - heights[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int min_val = 1;
    int max_val = 1000;

    int rows, cols, start_row, start_col;

    cin >> rows >> cols;
    cin >> start_row >> start_col;

    if (rows >= min_val && rows <= max_val && cols >= min_val && cols <= max_val &&
        start_row >= min_val && start_row <= rows && start_col >= min_val && start_col <= cols) {
        generate_landscape(rows, cols, start_row, start_col);
    } else {
        cout << "Invalid input, please try again.";
    }
    return 0;
}
