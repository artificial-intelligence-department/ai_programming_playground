#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Функція для розфарбовування гори на карті
void paintMountain(vector<vector<int>>& map, int x, int y) {
    // Отримання розмірів карти
    int N = map.size();
    int M = map[0].size();

    // Заповнення карти висотами відносно вершини гори
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            map[i][j] = abs(i - x) + abs(j - y);
        }
    }

    // Знаходження максимальної висоти на карті
    int maxHeight = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (maxHeight < map[i][j])
                maxHeight = map[i][j];
        }
    }

    // Зміщення висот так, щоб найвища точка гори мала висоту 0
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            map[i][j] = abs(map[i][j] - maxHeight);
        }
    }
}

int main() {
    // Зчитування розмірів карти
    int N, M;
    cin >> N >> M;

    // Зчитування координат вершини гори
    int x, y;
    cin >> x >> y;
    --x;
    --y; // Зменшення координат на 1 для внутрішнього представлення вектора

    // Створення карты
    vector<vector<int>> map(N, vector<int>(M));

    // Розфарбовування гори
    paintMountain(map, x, y);

    // Виведення результату
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
