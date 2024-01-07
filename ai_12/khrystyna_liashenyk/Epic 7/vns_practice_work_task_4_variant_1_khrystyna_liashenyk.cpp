#include <iostream>
using namespace std;

int main() {
    int number, sum = 0;
    int digits[10]; // Масив для зберігання цифр введеного числа

    cout << "Enter a number: ";
    cin >> number;

    int index = 0;
    while (number != 0) {
        digits[index++] = number % 10; // Зберігаємо останню цифру числа в масиві
        sum += digits[index - 1]; // Додаємо останню цифру до суми
        number /= 10; // Видаляємо останню цифру числа
    }

    cout << "Sum of digits in the entered number: " << sum << endl;

    return 0;
}
