#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    char cave[N][M];

    // Зчитування стану печери до землетрусу
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> cave[i][j];
        }
    }

    // Проходження печери від низу до верху та видалення піску
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            if (cave[i][j] == 'O') {
                for (int k = i; k >= 0; k--) {
                    if (cave[k][j] == 'S') {
                        cave[i][j] = 'S';
                        cave[k][j] = 'O';
                        break;
                    } else if (cave[k][j] == 'X') {
                        break;
                    }
                }
            }
        }
    }

    // Виведення стану печери після землетрусу
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << cave[i][j];
        }
        cout << endl;
    }

    return 0;
}
