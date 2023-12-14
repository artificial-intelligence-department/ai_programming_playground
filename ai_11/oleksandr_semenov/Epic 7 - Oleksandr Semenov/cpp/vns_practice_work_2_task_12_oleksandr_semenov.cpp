#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Вхідні дані
    int studentNumber; // 1. в коді використана як мінімум одна цілочисельна змінна
    double x, y, z; // 2. в коді використана як мінімум одна дійсна змінна

    // Задані константи
    const double h_x = 2.0; // 3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
    const double h_y = 1.0; // 3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
    const double nu_lower_bound = -4.0; // 3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
    const double nu_upper_bound = 3.0; // 3. в коді використана як мінімум одна дійсний з подвійною точністю змінна

    // Введення номера студента
    cout << "Введіть номер студента: ";
    cin >> studentNumber;

    // Розрахунок x за формулою x = 1 + h_x * i, де i - номер студента
    x = 1.0 + h_x * studentNumber;

    // Розрахунок y за формулою y = nu - h_y * i, де i - номер студента
    double nu = nu_lower_bound + h_y * studentNumber;
    y = (nu <= 0) ? fabs(nu) : nu;

    // Розгалуження для розрахунку z відповідно до умов
    if (x > y) { // 5. в коді використані умовні оператори та розгалуження
        z = pow(x, 2) / pow((x - 5), 3);
    } else {
        z = pow(x - 2, 3) / (y * pow(x - 5, 4));
    }

    // Виведення результатів у консоль
    cout << "Результат для x = " << x << ", y = " << y << ": " << z << endl;

    return 0;
}
