#include <iostream>
using namespace std;

int main() {
    int N, M; // N - rows, M - columns
    cin >> N >> M;
    char cave[N][M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> cave[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = N - 1; j >= 0; j--) {
            if (cave[j][i] == 'S') {
                int k = j + 1;
                while (k < N && cave[k][i] == 'O') {
                    swap(cave[k - 1][i], cave[k][i]);
                    k++;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << cave[i][j];
        }
        cout << endl;
    }

    return 0;
}
