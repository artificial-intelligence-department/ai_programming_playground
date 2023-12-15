#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
// Варіант 11

int main()
{
    double a, b, c, d, h;
    a = 100;
    b = 0.001;
    c = (pow(a - b, 4) - (pow(a, 4) - 4 * pow(a, 3) * b));
    // c = Чисельник
    d = (6 * pow(a, 2) * pow(b, 2) - 4 * a * pow(b, 3) + pow(b, 4));
    // d = Знаменник
    h = c / d;
    cout << "Result is: " << h << endl;

    return 0;
}