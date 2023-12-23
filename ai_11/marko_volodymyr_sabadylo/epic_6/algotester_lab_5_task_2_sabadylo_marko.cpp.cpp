#include <iostream>
using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) {
        cerr << "Invalid input format!\n";
        return 1;
    }

    char cave[1000][1000];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cave[i][j];
        }
    }

    // Цикл для імітації землетрусу
    for (int j = 0; j < m; j++) {
        for (int i = n - 2; i >= 0; i--) {
            if (cave[i][j] == 'S') {
                int counter = 1, newRow = i;
                while (i + counter < n && cave[i + counter][j] == 'O') {
                    newRow++;
                    counter++;
                }

                cave[i][j] = 'O';
                cave[newRow][j] = 'S';
            }
        }
    }

    // Виведення результату
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << cave[i][j];
        }
        cout << endl;
    }

    return 0;
}
