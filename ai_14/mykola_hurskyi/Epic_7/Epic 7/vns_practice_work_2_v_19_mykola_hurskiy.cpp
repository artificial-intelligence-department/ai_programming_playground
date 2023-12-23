#include<iostream>      //Підключаю бібліотеку С++, а також математичну бібліотеку
#include<cmath>

using namespace std;

void factorial(double x, int& count);

int main() {
    double minus_variable = 0.3, plus_variable = 5.0, krok = 0.1;
    int count = 0;

    for (double x = minus_variable; x <= plus_variable; x += krok) {
        factorial(x, count); // Передаємо змінну count у функцію factorial

        // Немає потреби в окремій перевірці тут; можна виконати її всередині функції factorial
    }

    cout << count;

    return 0;
}

void factorial(double x, int& count) { // Додаємо count як посилання
    double result = exp(-x) * cos(pow(x, 2));
    cout << result << endl;

    if (result < 0) {
        count++;
    }
}
