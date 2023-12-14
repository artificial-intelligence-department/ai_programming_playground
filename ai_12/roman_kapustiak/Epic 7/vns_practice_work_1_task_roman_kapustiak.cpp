#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    float x = 1.45, y = -1.22, z = 3.5; // Вимога #2 - в коді використана як мінімум одна дійсна змінна

    float b = 1 + pow(z, 2) / (3 + pow(z, 2) / 5);  // Вимога #17 - в коді використано математичні операції та математичні функції
    float a = 2 * cos(x - M_PI / 6) * b / (1 / 2 + pow(sin(y), 2));

    cout << "b = " << b << endl; // Вимога #21 - в коді використано оператори виведення даних
    cout << "a = " << a << endl;


    return 0;
}
