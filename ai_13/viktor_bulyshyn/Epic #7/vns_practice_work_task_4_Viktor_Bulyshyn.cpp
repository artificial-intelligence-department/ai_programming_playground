#include <iostream>

using namespace std;

int main() {
    // Задання змінних
    double number;
    double sum = 0;

    // Введення 5 дробових чисел
    cout << "enter numbers" << endl;

    for (int i = 0; i < 5; ++i) {
        cout << (i + 1) << ": ";
        cin >> number;
        sum = sum + number;
    }

    double average = sum / 5;

    cout << average;

    return 0;
}
