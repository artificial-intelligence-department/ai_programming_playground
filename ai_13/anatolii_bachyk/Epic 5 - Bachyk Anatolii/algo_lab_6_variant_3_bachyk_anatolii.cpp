#include <iostream>
#include <vector>

using namespace std;

vector<int> PossibleValues(const vector<vector<int>>& matrix, int x, int y) { // Функція повертає можливі значення для клітинки матриці
    int size = matrix.size();
    vector<bool> Values_present(size + 1, false);

    for (int i = 0; i < size; ++i) { // Створення вектору для перевірки наявності значень в клітинці
        if (matrix[x - 1][i] != 0) {
            Values_present[matrix[x - 1][i]] = true;
        }
        if (matrix[i][y - 1] != 0) {
            Values_present[matrix[i][y - 1]] = true;
        }
    }

    vector<int> values; // Створення вектору для можливих значень
    for (int i = 1; i <= size; ++i) {
        if (!Values_present[i]) {
            values.push_back(i);
        }
    }

    return values;
}

int main() {
    int size;
    cin >> size;

    if (size < 1 || size > 9) {
        return 0;
    }

    vector<vector<int>> matrix(size, vector<int>(size, 0)); // Створення та заповнення матриці введеними значеннями
    string matrixRow;
    for (int i = 0; i < size; ++i) {
        cin >> matrixRow;
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = matrixRow[j] - '0';
            if (matrix[i][j] < 0 || matrix[i][j] > 9) {
                return 0;
            }
        }
    }

    int Q;
    cin >> Q;

    if (Q < 1 || Q > 1000) {
        return 0;
    }

    vector<pair<int, int>> coordinates(Q);
    for (int q = 0; q < Q; ++q) {
        int x, y;
        cin >> x >> y;
        if (x < 1 || x > size || y < 1 || y > size) {
            return 0;
        }
        coordinates[q] = make_pair(x, y);
    }

    for (int q = 0; q < Q; ++q) {
        int x = coordinates[q].first;
        int y = coordinates[q].second;

        if (matrix[x - 1][y - 1] != 0) {
            cout << 1 << endl;
            cout << matrix[x - 1][y - 1] << endl << endl;
            continue;
        }

        vector<int> possibleValues = PossibleValues(matrix, x, y); // Отримання можливих значень для порожньої клітинки та виводимо їх
        cout << possibleValues.size() << endl;
        for (const auto& value : possibleValues) {
            cout << value << endl;
        }
    }

    return 0;
}