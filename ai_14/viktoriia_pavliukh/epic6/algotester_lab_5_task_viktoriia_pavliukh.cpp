#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N;
    cin >> M;
    vector<vector<char> > row(N, vector<char>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> row[i][j];
        }
    }
                for (int t = 0; t < M; t++) {
                    int temp = N-1;
                        for (int k = N - 1; k >= 0; k--) {
                            if (row[k][t] == 'S') {
                                swap(row[k][t], row[temp][t]);
                                temp--;
                            } else if (row[k][t] == 'X') {
                                temp = k - 1;
                                continue;
                            }
                        }
                }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << row[i][j];
        }
        cout << endl;
    }
    return 0;
}
