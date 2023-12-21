#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void SH(int x, int y, int N, int M, vector<vector<int>>& ar, vector<vector<bool>>& visited) { //setheight
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

void PG(int rws, int cls, int pkx, int pky) {//paintgrid
    vector<vector<int>> mntn(rws, vector<int>(cls, 0));
    vector<vector<bool>> visited(rws, vector<bool>(cls, false));

    SH(pkx - 1, pky - 1, rws, cls, mntn, visited);

    int maxHeight = 0;
    for (int i = 0; i < rws; i++) {
        for (int j = 0; j < cls; j++) {
            maxHeight = max(maxHeight, mntn[i][j]);
        }
    }

    for (int i = 0; i < rws; i++) {
        for (int j = 0; j < cls; j++) {
            cout << maxHeight - mntn[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rws, cls, pkx, pky;

    cin >> rws >> cls;
    cin >> pkx >> pky;

    if (rws >= 1 && rws <= 1000 && cls >= 1 && cls <= 1000 && pkx >= 1 && pkx <= rws && pky >= 1 && pky <= cls) {
        PG(rws, cls, pkx, pky);
    } else {
        cout << "invalid input";
    }

    return 0;
}
