#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> cave(N, vector<char>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> cave[i][j];
        }
    }
    for (int i = N - 1; i >= 0; --i) {
        for (int j = 0; j < M; ++j) {
            if (cave[i][j] == 'S') {
                int k = i + 1;
                while (k < N && cave[k][j] == 'O') {
                    ++k;
                }
                --k;
                bool hasStone = false;
                for (int l = i + 1; l < k; ++l) {
                    if (cave[l][j] == 'X') {
                        hasStone = true;
                        break;
                    }
                }
                if (!hasStone) {
                    cave[i][j] = 'O';
                    cave[k][j] = 'S';
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
    return 0;
}