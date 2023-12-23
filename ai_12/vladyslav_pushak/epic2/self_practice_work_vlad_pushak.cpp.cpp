#include <iostream>

using namespace std;

int main() {
    // Оголошуємо змінні
    double inputNumber, result;

    // Введення числа  користувача
    cout << "Введіть число: ";
    cin >> inputNumber;

    // Обчислення 60% від введеного числа
    result = 0.6 * inputNumber;

    // Виведення результату
    cout << "60% від введеного числа буде: " << result << endl;

    return 0;
}
