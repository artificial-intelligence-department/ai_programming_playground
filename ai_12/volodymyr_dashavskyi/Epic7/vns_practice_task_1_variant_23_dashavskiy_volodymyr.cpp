#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    // Вимога 3 дійсна змінна з подвійною точністю
    double m = 0.7;
    double x = 1.77;
    double a = 0.5;
    double b = 1.08;
    double Z, S;
    // Вимога 17 математичні операції та математичні функції
    Z = (sin(x) / sqrt(1 + pow(m, 3) * pow(sin(x), 2))) - (m * x * log(m * x));
    cout << Z << endl;

    S = (pow(M_E, ((-a) * x))) * sqrt(x + 1) + pow(M_E, (b * x)) * sqrt(abs(x - 3));
    cout << S << endl;
    return 0;
}