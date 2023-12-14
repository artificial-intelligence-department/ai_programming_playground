#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int number, digit, sum = 0;

    cout << "Введіть число: ";
    cin >> number;

    while (number != 0) {
        digit = number % 10;
        sum += digit;
        number /= 10;
    }

    cout << "Сума цифр введеного числа: " << sum << endl;

    return 0;
}