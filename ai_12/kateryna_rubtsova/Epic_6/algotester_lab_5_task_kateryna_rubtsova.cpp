#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    char cave[N][M];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> cave[i][j];
        }
    }

    
    for (int j = 0; j < M; ++j) {
        for (int i = 0; i < N - 1; ++i) {
            if (cave[i][j] == 'S' && cave[i + 1][j] == 'O') {
                char temp = cave[i][j];
                cave[i][j] = cave[i + 1][j];
                cave[i + 1][j] = temp;
                i -= 2;  
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
