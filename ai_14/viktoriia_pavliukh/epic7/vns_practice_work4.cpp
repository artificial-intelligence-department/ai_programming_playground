#include <iostream>

using namespace std;

int main() {
    // Оголошення змінних
    int x, result;

    // Введення значення x з клавіатури
    cout << "Enter x: ";
    cin >> x;

    // Цикл для обчислення та виведення таблиці множення для заданого x
    for (int i = 1; i <= 10; i++) {
        // Обчислення результату множення
        result = x * i;

        // Виведення результату
        cout << x << " * " << i << " = " << result << endl;
    }

    return 0;
}