#include <iostream>

using namespace std;

int main() {
    int N, M;
    cout << "Введіть висоту та ширину печери (N M): ";
    cin >> N >> M;

    char cave[N][M];
    cout << "Введіть стан печери до землетрусу:\n";
    for (int i = 0; i < N; i++) {
        cin >> cave[i];
    }

    // Землетрус: обробка піску
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            if (cave[i][j] == 'S') {
                int k = i;
                while (k + 1 < N && (cave[k + 1][j] == 'O' || cave[k + 1][j] == '.')) {
                    swap(cave[k][j], cave[k + 1][j]);
                    k++;
                }
            }
        }
    }

    // Виведення результатів
    cout << "Стан печери після землетрусу:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << cave[i][j];
        }
        cout << endl;
    }

    return 0;
}

/*
SSOSS
OOOOO
SOOXX
OOOOS
OOSOO
*/