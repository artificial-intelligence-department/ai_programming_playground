#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void paintGrid(int rws, int cls, int pkx, int pky) {
    vector<vector<int>> grid(rws, vector<int>(cls, -1)); // Задаємо двовимірний вектор для зберігання поля

    queue<pair<int, int>> q; // Створення черги для пошуку у ширину
    q.push({pkx - 1, pky - 1});
    grid[pkx - 1][pky - 1] = 0; 

    int dx[] = {-1, 0, 1, 0}; // Масиви для зручності переходу між комірками вверх/вниз та вліво/вправо
    int dy[] = {0, 1, 0, -1};

    while (!q.empty()) { // Цикл, що проходить по всіх клітинках та присвоює їм власне значення
        pair<int, int> current = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];

            if (nx >= 0 && nx < rws && ny >= 0 && ny < cls && grid[nx][ny] == -1) {
                grid[nx][ny] = grid[current.first][current.second] + 1;
                q.push({nx, ny});
            }
        }
    }

    int maxVal = 0; 
    for (int i = 0; i < rws; ++i) { // Знаходиться максимальне значення на сітці
        for (int j = 0; j < cls; ++j) {
            maxVal = max(maxVal, grid[i][j]);
        }
    }

    for (int i = 0; i < rws; ++i) { // Цикл, що виводить кінцевий результат сітки
        for (int j = 0; j < cls; ++j) {
            cout << maxVal - grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rws, cls, pkx, pky;

    cin >> rws >> cls;
    cin >> pkx >> pky;

    if (rws >= 1 && rws <= 1000 && cls >= 1 && cls <= 1000 && pkx >= 1 && pkx <= rws && pky >= 1 && pky <= cls) {
        paintGrid(rws, cls, pkx, pky);
    } else {
        cout << "invalid input";
    }

    return 0;
}