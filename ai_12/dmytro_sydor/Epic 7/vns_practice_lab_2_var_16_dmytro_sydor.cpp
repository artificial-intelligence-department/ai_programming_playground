#include <iostream>
#include <cmath>
#include <iomanip>

// Вимога 16 - використано параметри та аргументи функції.
void outPut(double x, double y, double a)
{
    // Вимога 1 - в коді використана як мінімум одна цілочисельна змінна.
    int size = 3;
    // Вимога 21 - в коді використано оператори введення та виведення даних.
    std::cout << std::fixed << std::setprecision(size) << " X = " << x << "\t Y = " << y << "\t A = " << a << std::endl;
}

int main()
{
    // Вимога 3 - в коді використана як мінімум одна дійста з подвійною точністю змінна.
    double b = 3.11, a = 0.1;
    double x = 0.5;

    // Вимога 9 - в коді використаний цикл while.
    while (x <= b)
    {
        double y = 0.0;

        // Вимога 5 - в коді використані умовні оператори та розгалуження

        if (x > 2)
        {
            y = cos(a * x + 2);
        }

        else if (x <= 2)
        {
            y = tan(fabs(x - 2 * a));
        }
        outPut(x, y, a);
        a += 0.3;
        x += 0.2;
    }

    return 0;
}