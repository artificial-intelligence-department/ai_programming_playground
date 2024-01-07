#include <iostream>
#include <vector>
using namespace std;

void earthquake(int N, int M, vector<vector<char>>& cave) {
    for (int j = 0; j < M; ++j) {
        for (int i = 0; i < N - 1; ++i) {
            if (cave[i][j] == 'S') {
                int k = i + 1;
                while (k < N && (cave[k][j] == 'O' || cave[k][j] == 'S')) {
                    if (cave[k][j] == 'O') {
                        swap(cave[i][j], cave[k][j]);
                        break;
                    }
                    ++k;
                }
            }
        }
    }
}

int main() {
    int N, M; //висота і ширина
    cin >> N >> M;

    vector<vector<char>> cave(N, vector<char>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> cave[i][j];
        }
    }

    earthquake(N, M, cave);

    // Виведення результату
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << cave[i][j];
        }
        cout << endl;
    }

    return 0;
}


















