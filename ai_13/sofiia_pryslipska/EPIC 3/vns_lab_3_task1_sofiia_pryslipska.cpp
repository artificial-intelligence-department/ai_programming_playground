#include <iostream>
#include <cmath>
using namespace std;

double function(double x)
{
    return (1 + 2 * pow(x, 2)) * exp(pow(x, 2));
}

int main()
{
    double a = 0.1;
    double b = 1.0;
    int k = 10; // Кількість кроків
    int n = 10;
    double epsilon = 0.0001;
    double step = (b - a) / k; // Розрахунок кроку

    

    // Цикл для зміни параметра x
    for (double x = a; x <= b; x += step)
    {
        double sn = 1; // Значення суми для заданого n
        double se = 1; // Значення суми для заданої точності

        double an = 1; // Початковий член ряду для заданого n
        double ae = 1; // Початковий член ряду для заданої точності

        int i = 1;

        // Цикл для обчислення суми за заданим n
        while (i <= n)
        {
            an *= (2 * i + 1) * pow(x, 2) / (i * (i + 1)); // Обчислення кожного члена ряду
            sn += an;
            i++;
        }

        i = 1;
        // Цикл для обчислення суми за заданою точністю epsilon
        while (ae >= epsilon)
        {
            ae *= (2 * i + 1) * pow(x, 2) / (i * (i + 1)); // Обчислення кожного члена ряду
            se += ae;
            i++;
        }

        // Виведення результатів
        cout << "X:\t " << x << " SN:\t " << sn << " SE:\t " << se << " Y:\t " << function(x) << "\n";
    }

    return 0;
}
