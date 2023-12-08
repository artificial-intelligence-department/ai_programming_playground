#include <iostream>
#include <cmath>

using namespace std;

double current (double m, double n) // використано параметри та аргументи функції, та дійсних змінних
{
    if (n == 0) // використано умовний оператор та розгалуження
    {
        cout << "Помилка!!!, опір має бути більший нуля\n";
    }

    return m / n;
}

int main()
{
    int way; // цілочисельна змінна
    double cost, cost_fuel, fuel_consumtion; // дійсні з подвійною точністю

    cout << "Відстань до дачі (км): "; // використання оператора виведення
    cin >> way; // використання оператора введення
    cout << "Витрата бензину (літрів на 100 км пробігу): ";
    cin >> fuel_consumtion;
    cout << "Ціна літра бензину (грн.): ";
    cin >> cost_fuel;

    cost = (fuel_consumtion / 100) * way * 2 * cost_fuel;

    cout << "Поїздка на дачу і назад обійдеться в " << round(cost * 100)/100 << endl << endl;

    double m, n, p;

    cout << "Введіть напругу: ";
    cin >> m;
    cout << "введіть опір: ";
    cin >> n;

    p = current (m, n);

    cout << "Струм в електричному ланцюгу = " << p << endl;

    return 0;
}