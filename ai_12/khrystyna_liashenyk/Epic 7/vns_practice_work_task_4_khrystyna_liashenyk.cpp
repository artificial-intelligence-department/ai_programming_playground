#include <iostream>
using namespace std;

int main() {
    int number, sum = 0;

    cout << "Enter a number: ";
    cin >> number;

    // Знаходимо суму цифр введеного числа
    while (number != 0) {
        sum += number % 10; // Додаємо останню цифру числа до суми
        number /= 10; // Видаляємо останню цифру числа
    }

    // Виводимо суму цифр введеного числа на екран
    cout << "Sum of digits in the entered number: " << sum << endl;

    return 0;
}
