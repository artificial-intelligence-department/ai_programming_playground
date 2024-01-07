#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Функція для розфарбовування ландшафту
void paintTheLandscape(int r, int c, int X, int Y) {
    // Створення двовимірного вектору для представлення ландшафту
    vector<vector<int> > land(r, vector<int>(c, -1));

    // Черга для обробки гірських вершин
    queue<pair<int, int> > queueMountain;

    // Початкова гірська вершина
    queueMountain.push(make_pair(X - 1, Y - 1));
    land[X - 1][Y - 1] = 0;

    // Масиви для зручного переходу до сусідніх клітин
    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    // Пошук гірських вершин та їх розфарбовування
    while (!queueMountain.empty()) {
        pair<int, int> current = queueMountain.front();
        queueMountain.pop();

        // Перевірка сусідніх клітин
        for (int i = 0; i < 4; ++i) {
            int newX = current.first + dx[i];
            int newY = current.second + dy[i];

            // Перевірка чи знаходиться клітина у межах ландшафту і чи не була відвідана
            if (newX >= 0 && newX < r && newY >= 0 && newY < c && land[newX][newY] == -1) {
                // Розфарбовування та додавання у чергу для подальшої обробки
                land[newX][newY] = land[current.first][current.second] + 1;
                queueMountain.push(make_pair(newX, newY));
            }
        }
    }

    // Знаходження максимальної висоти
    int maxHeight = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            maxHeight = max(maxHeight, land[i][j]);
        }
    }

    // Виведення результуючого ландшафту
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << maxHeight - land[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Константи для перевірки введених даних
    const int MIN = 1;
    const int MAX = 1000;

    int r, c, X, Y;

    // Введення розмірів ландшафту та початкової гірської вершини
    cout << "Введіть розміри ландшафту (r c): ";
    cin >> r >> c;
    cout << "Введіть початкову гірську вершину (X Y): ";
    cin >> X >> Y;

    // Перевірка валідності введених даних
    if (r >= MIN && r <= MAX && c >= MIN && c <= MAX &&
        X >= MIN && X <= r && Y >= MIN && Y <= c) {
        // Виклик функції для розфарбовування ландшафту
        paintTheLandscape(r, c, X, Y);
    } else {
        cout << "Неправильний ввід, будь ласка, спробуйте знову." << endl;
    }

    return 0;
}