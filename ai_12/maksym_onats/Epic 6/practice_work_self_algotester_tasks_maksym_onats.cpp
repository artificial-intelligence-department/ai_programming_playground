#include <iostream>
using namespace std;

int main() {
int N, M;
cin >> N >> M;

char cave[1000][1000];

for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
    cin >> cave[i][j];
    }
}

for (int i = 0; i < M; i++) {
    for (int j = N - 1; j >= 0; j--) {
    if (cave[j][i] == 'S') {
        int k = j;
        while (k < N - 1 && cave[k + 1][i] == 'O') {
        cave[k + 1][i] = 'S';
        cave[k][i] = 'O';
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
