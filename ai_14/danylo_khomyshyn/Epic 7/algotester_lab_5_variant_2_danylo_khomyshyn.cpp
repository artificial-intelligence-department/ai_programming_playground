#include <iostream>
#include <vector>

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

    for (int i = N - 2; i >= 0; --i) {
        for (int j = 0; j < M; ++j) {
            if (cave[i][j] == 'S' && cave[i + 1][j] == 'O') {
                int k = i + 1;
                while (k < N && cave[k][j] == 'O') {
                    k++;
                }
                k--;
                cave[i][j] = 'O';
                cave[k][j] = 'S';
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