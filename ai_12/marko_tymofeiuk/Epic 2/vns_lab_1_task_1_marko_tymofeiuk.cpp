#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long double a = 1000, b = 0.0001, c, d, e, f, g;

    c = pow((a + b), 2);       // Зменшуване
    d = pow(a, 2) + 2 * a * b; // Від'ємник
    e = c - d;                 // Різниця
    f = pow(b, 2);             // Знаменник
    g = e / f;                 // Остаточний результат
    cout << g;

    return 0;
}