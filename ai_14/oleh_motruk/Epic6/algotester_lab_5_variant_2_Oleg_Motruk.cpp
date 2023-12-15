#include <iostream>
#include <vector>

using namespace std;

void simulateEarthquake(int N, int M, vector<vector<char>>& cave) {
    for (int col = 0; col < M; ++col) {
        for (int row = N - 1; row >= 0; --row) {
            if (cave[row][col] == 'S') {
                for (int k = row + 1; k < N; ++k) {
                    if (cave[k][col] == 'X' || cave[k][col] == 'S') {
                        break;
                    } else if (cave[k][col] == 'O') {
                        swap(cave[k][col], cave[k - 1][col]);
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << cave[i][j];
        }
        cout << endl;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> caveMap(N, vector<char>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> caveMap[i][j];
        }
    }

    simulateEarthquake(N, M, caveMap);

    return 0;
}