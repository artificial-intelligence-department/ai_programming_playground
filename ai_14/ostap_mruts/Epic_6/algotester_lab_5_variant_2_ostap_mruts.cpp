#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    vector<vector<char>> cave(N, vector<char>(M));

    for (int i = 0; i < N; ++i) {
        char row[M + 1];
        scanf("%s", row);
        for (int j = 0; j < M; ++j) {
            cave[i][j] = row[j];
        }
    }

    for (int j = 0; j < M; ++j) {
        int emptyCellIdx = N - 1;

        for (int i = N - 1; i >= 0; --i) {
            if (cave[i][j] == 'S') {
                cave[i][j] = 'O';
                cave[emptyCellIdx--][j] = 'S';
            } else if (cave[i][j] == 'X') {
                emptyCellIdx = i - 1;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%c", cave[i][j]);
        }
        printf("\n");
    }

    return 0;
}