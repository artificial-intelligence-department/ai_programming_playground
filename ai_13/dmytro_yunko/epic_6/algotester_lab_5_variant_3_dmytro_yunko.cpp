#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void setHeight(int x, int y, int N, int M, vector<vector<int>>& ar, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    ar[x][y] = 0;

    int xDir[] = {-1, 0, 1, 0};
    int yDir[] = {0, 1, 0, -1};

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int xi = current.first + xDir[i];
            int yi = current.second + yDir[i];

            if (xi >= 0 && xi < N && yi >= 0 && yi < M && !visited[xi][yi]) {

                ar[xi][yi] = ar[current.first][current.second] + 1;
                visited[xi][yi] = true;
                q.push({xi, yi});
                
            }
        }
    }
}

int main() {
    int N, M, x, y;
    cin >> N >> M >> x >> y;
    x--; y--;
    vector<vector<int>> mntn(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    setHeight(x, y, N, M, mntn, visited);

    int maxHeight = 0;
    for (int i = 0; i < N; i++) {
       
        for (int j = 0; j < M; j++) {
            
            maxHeight = max(maxHeight, mntn[i][j]);
        }
        
        
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << maxHeight - mntn[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
