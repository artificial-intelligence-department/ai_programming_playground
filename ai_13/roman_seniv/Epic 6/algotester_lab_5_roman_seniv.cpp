#include <iostream>
#include <vector>

using namespace std;

// Функція для вирішення задачі
void simulateEarthquake(vector<vector<char>> &cave) {
    int rows = cave.size();
    int cols = cave[0].size();

    for (int col = 0; col < cols; ++col) {
        int bottomEmptyCell = rows - 1;  // Індекс найнижчої порожньої клітини

        // Проходження віднизу вгору
        for (int row = rows - 1; row >= 0; --row) {
            if (cave[row][col] == 'S') {
                // Якщо знаходимо пісок
                if (bottomEmptyCell < rows - 1) {
                    // Якщо є порожні клітини вище, перемістимо пісок вгору
                    cave[bottomEmptyCell][col] = 'S';
                    cave[row][col] = 'O';
                    ++bottomEmptyCell;
                }
            } else if (cave[row][col] == 'O') {
                // Запам'ятовуємо індекс найнижчої порожньої клітини
                bottomEmptyCell = row;
            }
        }
    }
}

// Функція для виведення стану печери
void printCave(const vector<vector<char>> &cave) {
    for (const auto &row : cave) {
        for (char cell : row) {
            cout << cell;
        }
        cout << endl;
    }
}

int main() {
    // Розмір печери (N - висота, M - ширина)
    int N, M;
    cout << "Enter the height and width of the cave (1 <= N, M <= 1000): ";
    cin >> N >> M;

    // Перевірка обмежень
    if (N < 1 || N > 1000 || M < 1 || M > 1000) {
        cerr << "Incorrect constraints for the height or width of the cave." << endl;
        return 1;
    }

    // Ініціалізація печери
    vector<vector<char>> cave(N, vector<char>(M));

    // Заповнення печери
    cout << "Enter the cave state (O - empty, S - sand, X - rock):" << endl;
    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;

        // Перевірка довжини рядка
        if (row.length() != M) {
            cerr << "Incorrect row length." << endl;
            return 1;
        }

        for (int j = 0; j < M; ++j) {
            cave[i][j] = row[j];
        }
    }

    // Симуляція землетрусу
    simulateEarthquake(cave);

    // Виведення оновленого стану печери
    cout << "Cave state after the earthquake:" << endl;
    printCave(cave);

    return 0;
}
