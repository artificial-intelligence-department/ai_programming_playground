#include <iostream>
#include <vector>

using namespace std;

// Функція для моделювання землетрусу в печері
void simulateEarthquake(int N, int M, vector<vector<char>>& cave) {
    // Проходимо кожний стовпець в печері
    for (int col = 0; col < M; ++col) {
        // Проходимо від нижнього рядка до верхнього
        for (int row = N - 1; row >= 0; --row) {
            // Якщо поточна клітина містить камінь ('S')
            if (cave[row][col] == 'S') {
                // Перевіряємо клітини нижче каменя
                for (int k = row + 1; k < N; ++k) {
                    // Якщо клітина нижче - перешкода ('X') або ще один камінь ('S'), зупиняємо переміщення каменя
                    if (cave[k][col] == 'X' || cave[k][col] == 'S') {
                        break;
                    }
                    // Якщо клітина нижче - порожній простір ('O'), міняємо місцями камінь та порожню клітину
                    else if (cave[k][col] == 'O') {
                        swap(cave[k][col], cave[k - 1][col]);
                    }
                }
            }
        }
    }

    // Виводимо оновлену карту печери після моделювання землетрусу
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << cave[i][j];
        }
        cout << endl;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    // Створюємо двовимірний вектор, що представляє розміщення печери
    vector<vector<char>> caveMap(N, vector<char>(M));

    // Вводимо розміщення печери символ за символом
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> caveMap[i][j];
        }
    }

    // Виконуємо моделювання землетрусу для розміщення печери
    simulateEarthquake(N, M, caveMap);

    return 0;
}
