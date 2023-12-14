#include <iostream>
#include <cmath>

using namespace std;

// ініціалізуємо всі зміни, які будемо використовувати
double a = 1.5;
double b = 15.5;
double x = -2.9;
double y, P;

int main()
{

    // розрахунок значення у за даною формулою
    y = pow(cos(pow(x, 3)), 2) - (x / pow((pow(a, 2) + pow(b, 2)), 0.5));
    // розрахунок значення Р за даною формулою
    P = pow(pow(x, 2) + b, 0.5) - ((pow(b, 2) * pow(sin(x + a), 3)) / (x * y));

    // виведення результатів
    cout << y << endl;
    cout << P << endl;

    return 0;
}
