#include <iostream>

using namespace std;

void simulateEarthquake(int N, int M, char cave[1000][1000]) {

    for (int i = N - 2; i >= 0; --i) {
        for (int j = 0; j < M; ++j) {
            if (cave[i][j] == 'S' && (cave[i + 1][j] == 'O' || (j > 0 && cave[i + 1][j - 1] == 'X') || (j < M - 1 && cave[i + 1][j + 1] == 'X'))) {
                int k = i + 1;
                while (k < N && cave[k][j] == 'O') {    
                    cave[k][j] = 'S';
                    cave[k - 1][j] = 'O';
                    ++k;
                }
            }
        }
    }
}

int main() {
    int cols, rows;
    cin >> cols >> rows;

    char cave[1000][1000];
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            cin >> cave[i][j];
        }
    }

    simulateEarthquake(cols, rows, cave);

    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            cout << cave[i][j];
        }
        cout << endl;
    }

    return 0;
}
