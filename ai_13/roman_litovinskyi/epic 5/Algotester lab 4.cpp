#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ost0; // Вектор для чисел, остаток від ділення на 3 яких дорівнює 0
vector<int> ost1; // Вектор для чисел, остаток від ділення на 3 яких дорівнює 1
vector<int> ost2; // Вектор для чисел, остаток від ділення на 3 яких дорівнює 2
vector<int> final; // Вектор для зберігання відсортованих та унікальних чисел

// Функція для сортування у зворотньому порядку
bool sortDescending(int a, int b);

int main() {
    int N;
    cin >> N;

    vector<int> chusla(N);
    for (int i = 0; i < N; i++) {
        cin >> chusla[i];
    }

    // Розділення чисел за остатками від ділення на 3
    for (int i = 0; i < N; i++) {
        if ((chusla[i] % 3) == 0) {
            ost0.push_back(chusla[i]);
        } else if ((chusla[i] % 3) == 1) {
            ost1.push_back(chusla[i]);
        } else if ((chusla[i] % 3) == 2) {
            ost2.push_back(chusla[i]);
        }
    }

    // Сортування та видалення дублікатів для кожного вектора
    sort(ost0.begin(), ost0.end());
    ost0.erase(unique(ost0.begin(), ost0.end()), ost0.end());

    sort(ost1.begin(), ost1.end(), sortDescending);
    ost1.erase(unique(ost1.begin(), ost1.end()), ost1.end());

    sort(ost2.begin(), ost2.end());
    ost2.erase(unique(ost2.begin(), ost2.end()), ost2.end());

    // Додавання унікальних чисел у final з усіх векторів
    for (int i = 0; i < ost0.size(); i++) {
        final.push_back(ost0.at(i));
    }

    for (int i = 0; i < ost1.size(); i++) {
        final.push_back(ost1.at(i));
    }

    for (int i = 0; i < ost2.size(); i++) {
        final.push_back(ost2.at(i));
    }

    // Виведення кількості унікальних чисел та їх значень
    cout << final.size() << endl;
    for (int i = 0; i < final.size(); i++) {
        cout << final.at(i) << " ";
    }

    return 0;
}

// Функція для сортування у зворотньому порядку
bool sortDescending(int a, int b) {
    return a > b;
}
