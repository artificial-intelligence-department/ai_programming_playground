#include <iostream>
#include <cmath>

using namespace std;

double calculateY(double z, double x);
float calculateY(float z, float x);

int main()
{
    double z, y, x;  // Вимога #3 - в коді використана як мінімум одна дійсна з подвійною точністю змінна
    for(x = -2.5;; x += 0.5) // Вимога #10 - в коді використаний for цикл, для отримання параметрів функції, що віріюються.
    {
        if(x == -2)
        {
            continue; // Вимога #11 - в коді використано оператори break і continue, бо на нуль ділити не можна.
        }
        else  // Вимога #5 - в коді використані умовні оператори та розгалуження
        {
            z = abs(x) + pow(x, 2);
            y = calculateY(z, x);

            cout << "x = " << x << ", z = " << z << ", y = " << y << endl;
        }

        if(x > 2)
        {
            break;  // Вимога #11 - в коді використано оператори break і continue, щоб зупинити цикл for.
        }
    }

    return 0;
}
double calculateY(double z, double x)   // Вимога #16 - в коді використано параметри та аргументи функції
{
    double y = z * pow( sin(2 + x), 2 ) / (2 + x); // Вимога #17 - в коді використано математичні операції та математичні функції

    return y;
}
float calculateY(float z, float x)   // Вимога #12 - в коді використано перевантаження функції для іншого типу даних.
{
    float y = z * pow( sin(2 + x), 2 ) / (2 + x);
    
    return y;
}
