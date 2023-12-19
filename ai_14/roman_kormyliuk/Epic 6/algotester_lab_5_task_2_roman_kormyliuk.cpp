#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    cin.ignore();

    vector<vector<char>> cave(N, vector<char>(M));
    string input;

    for (int i = 0; i < N; i++) {
        getline(cin, input);

        for (int j = 0; j < M; j++) {
            cave[i][j] = input[j];
        }
    }

    for (int j = 0; j < M; j++) {
        for (int i = N - 1; i >= 0; i--) {
            if (cave[i][j] == 'S') {
                int q = i;
                while (q < N - 1 && cave[q + 1][j] == 'O' && cave[q][j] != 'X') {
                    swap(cave[q][j], cave[q + 1][j]);
                    q++;
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