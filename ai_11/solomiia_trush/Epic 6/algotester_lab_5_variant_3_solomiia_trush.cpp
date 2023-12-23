#include <iostream>
#include <queue>
using namespace std;

struct Cell {
    int x, y, height;
};

int main() {
    int N, M, x, y;
    cin >> N >> M >> x >> y;

    int map[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] = -1;  // -1 means unvisited
        }
    }

    queue<Cell> q;
    q.push({x - 1, y - 1, 0});  
    map[x - 1][y - 1] = 0;

    while (!q.empty()) {
        Cell current = q.front();
        q.pop();

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == -1) {
                map[nx][ny] = current.height + 1;
                q.push({nx, ny, current.height + 1});
            }
        }
    }

    int maxHeight = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            maxHeight = max(maxHeight, map[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] = maxHeight - map[i][j];
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
