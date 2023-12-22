#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 1001;
int heights[MAX_N][MAX_N];

void assignHeights(int N, int M, int x, int y) {
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            heights[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    q.push({x - 1, y - 1}); 
    heights[x - 1][y - 1] = 0; 

    int dx[] = {-1, 1, 0, 0}; 
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && heights[nx][ny] == -1) {
                heights[nx][ny] = heights[curr.first][curr.second] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    int N, M, x, y;
    cin >> N >> M >> x >> y;

    assignHeights(N, M, x, y);

    
    int max_height = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            max_height = max(max_height, heights[i][j]);
        }
    }

    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << max_height - heights[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

