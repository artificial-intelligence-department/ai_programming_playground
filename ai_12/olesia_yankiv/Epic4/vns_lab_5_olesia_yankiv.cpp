#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // Користувач вводить значення N
    int N;
    cout << "Введіть значення N: ";
    cin >> N;

    // Розрахунок розміру масиву
    int size = N * N;
    string input;
    cout << "Введіть рядок з " << size << " чисел: ";
    cin.ignore(); // Пропуск символу нового рядка
    getline(cin, input);

    // Розділення рядка на підрядки довжиною N
    vector<string> substrings;
    for (int i = 0; i < size; i += N) {
        string substring = input.substr(i, N);
        substrings.push_back(substring);
    }

    // Сортування підрядків у порядку зростання
    sort(substrings.begin(), substrings.end());

    // Розташувати відсортовані підрядки у двовимірному масиві
    int index = 0;
    vector<vector<int>> array(N, vector<int>(N));
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            array[row][col] = substrings[index][col] - '0';
        }
        index++;
    }

    // Вивід отриманого двовимірного масиву
    cout << "Ось ваш двовимірний масив:" << endl;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << array[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}
