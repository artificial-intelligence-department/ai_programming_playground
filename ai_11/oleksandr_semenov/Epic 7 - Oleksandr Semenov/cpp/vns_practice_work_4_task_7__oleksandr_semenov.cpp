#include <iostream>

using namespace std;

int main() {
    int n;  // Кількість членів ряду
    cout << "Введіть кількість членів ряду для сумування: ";
    cin >> n;

    int sum = 0;  // Змінна для збереження суми

    // Обчислення суми перших n непарних чисел
    for (int i = 1, count = 0; count < n; i += 2, ++count) {
        sum += i;
    }

    // Виведення результату
    cout << "Сума перших " << n << " непарних членів ряду: " << sum << endl;

    return 0;
}
