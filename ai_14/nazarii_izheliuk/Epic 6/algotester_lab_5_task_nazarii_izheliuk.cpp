#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    cin.ignore(); 

    string cave[N][M];
    string input;
    
    for (int i = 0; i < N; i++) {
        getline(cin, input);

        for (int j = 0; j < M; j++) {
            cave[i][j] = input[j];
        }
    }

    for (int j = 0; j < M; j++) {
        for (int i = N - 1; i >= 0; i--) {
            if (cave[i][j] == "S") {
                int k = i;
                while (k < N - 1 && cave[k + 1][j] == "O" && cave[k][j] != "X") {
                    swap(cave[k][j], cave[k + 1][j]);
                    k++;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << cave[i][j][0];
        }
        cout << endl;
    }

    return 0;
}
