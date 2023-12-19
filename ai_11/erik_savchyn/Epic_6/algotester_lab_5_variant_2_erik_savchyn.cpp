#include <iostream>

using namespace std;

int main() {
    int N;
    int M;
    cin >> N;
    cin >> M;

    char cave[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> cave[i][j];
        }
    }
    
    char earthquake[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            earthquake[i][j] = 'O';
        }
    }

    for (int i = 0; i < M; i++) {
        int sandTop = 0;
        for (int j = 0; j < N; j++) {
            if (cave[j][i] == 'O') {
                earthquake[j][i] = 'O';
                if (j == N-1 || cave[j+1][i] == 'X') {
                    for (int k = 0; k < sandTop; k++) {
                        earthquake[j-k][i] = 'S';
                    }
                    sandTop = 0;
                }
                continue;
            } else if (cave[j][i] == 'X') {
                earthquake[j][i] = 'X';
                continue;
            } else if (cave[j][i] == 'S') {
                sandTop++;
                if (j == N-1 || cave[j+1][i] == 'X') {
                    for (int k = 0; k < sandTop; k++) {
                        earthquake[j-k][i] = 'S';
                    }
                    sandTop = 0;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << earthquake[i][j];
        }
        cout << endl;
    }

    return 0;
}
