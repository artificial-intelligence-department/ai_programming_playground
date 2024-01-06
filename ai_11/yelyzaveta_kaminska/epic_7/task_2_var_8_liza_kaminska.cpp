#include <iostream> // Підключення бібліотеки для введення/виведення на консоль
#include <cmath>    // Підключення бібліотеки для математичних функцій
using namespace std; // Використання простору імен std

int main() {
    // Оголошення змінних для обчислень
    double x; // Змінна для значення x
    double y; // Змінна для результату обчислення
    double z; // Допоміжна змінна

    for (x = 1; x <= 4; x += 0.5) {  // Цикл, який проходить значення x від 1 до 4 з кроком 0.5
        z = abs(x) + pow(x, 3); // Обчислення z як сума модуля та x в 3 степені
        y = z * (sin(pow(2 + x, 2))) / (2 + x); // Обчислення y за виразом

        cout << "If x = " << x << "   than y = " << y << endl;  // Виведення результату на екран
    }

    return 0; // Успішне завершення програми
}
