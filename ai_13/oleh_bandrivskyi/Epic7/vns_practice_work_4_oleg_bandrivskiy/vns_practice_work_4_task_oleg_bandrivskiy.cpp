#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Введіть кількість членів ряду: ";
    cin >> n;

    if (n <= 0) {
        cerr << "Помилка: Кількість членів ряду повинна бути більше за 0." << endl;
        return 1; 
    }

    int sum = 0;
    for (int i = 1; i <= 2 * n; i += 2) {
        sum += i;
    }


    cout << "Сума перших " << n << " непарних чисел: " << sum << endl;

    return 0;
}
