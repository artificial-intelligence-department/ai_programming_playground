#include <iostream>
#include <vector>

using namespace std;

void caveEarthquake(vector<vector<char>>& cave, int col) {
    for (int i = cave.size() - 1; i >= 0; --i) {
        if (cave[i][col] == 'S') {
            int k = i + 1;
            while (k < cave.size() && cave[k][col] == 'O') {
                swap(cave[k][col], cave[k - 1][col]);
                ++k;
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> cave(N, vector<char>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> cave[i][j];
        }
    }

    for (int j = 0; j < M; ++j) {
        caveEarthquake(cave, j);
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << cave[i][j];
        }
        cout << endl;
    }

    return 0;
}