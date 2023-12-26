// Судоку для Клінта, який не хоче вчити програмування
#include <iostream>
#include <vector>
#include <set> // Контейнер для зберігання унікальних значень

using namespace std;

set<int> getvls(const vector<vector<int>> &matrix, int x, int y) { // Функція, яка розраховує всі можливі значення у нульовій комірці
    int size = matrix.size();
    set<int> vls;
    for (int i = 1; i <= size; ++i) {
        vls.insert(i);
    }

    for (int i = 0; i < size; ++i) {
        vls.erase(matrix[x - 1][i]); // Видаляємо значення, які зустрічаються у рядку чи стовпці
        vls.erase(matrix[i][y - 1]);
    }

    return vls;
}

int main() {
    int size;

    cin >> size; // Задаємо розмір ігрового поля

    if (size < 1 || size > 9) {
        return 0;
    }

    vector<vector<int>> matrix(size, vector<int>(size, 0)); // Використовуємо двовимірний масив, як контейнер для значень
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

    int qst; // Кількість комірок, які хочемо перевірити
    cin >> qst;

    if (qst < 1 || qst > 1000) {
        return 0;
    }

    vector<pair<int, int>> cords(qst);
    for (int q = 0; q < qst; ++q) {

        int x, y;
        cin >> x >> y;
        if (x < 1 || x > size || y < 1 || y > size) {
            return 0;
        }
        cords[q] = make_pair(x, y);
    }

    for (int q = 0; q < qst; ++q) {
        int x = cords[q].first;
        int y = cords[q].second;


        if (matrix[x-1][y-1] != 0) { // Якщо комірка має ненульове значення, то виводимо його
            cout << 1 << endl;
            cout << matrix[x-1][y-1] << endl << endl;
            continue;
        }

        set<int> vls = getvls(matrix, x, y); // Викликаємо функцію getvls 
        cout << vls.size() << endl;
        for (const auto &value : vls) {
            cout << value << endl;
        }
        cout << endl << endl;
    }

    return 0;
}