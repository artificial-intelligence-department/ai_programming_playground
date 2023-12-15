#include <iostream>
#include <math.h>
using namespace std;

void task1();
double countPolynomial(double a, double b);
double polynomial1(double a, double b);
double polynomial2(double a, double b);
double polynomial3(double a, double b);

int main()
{
    task1();
    return 0;
}

void task1()
{
    double a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << countPolynomial(a, b) << "\n";
}

double countPolynomial(double a, double b)
{
    return (polynomial2(a, b) - polynomial1(a, b)) / polynomial3(a, b);
}

double polynomial1(double a, double b)
{
    return pow(a - b, 4);
}

double polynomial2(double a, double b)
{
    return pow(a, 4) - 4 * pow(a, 3) * b + 6 * pow(a, 2) * pow(b, 2);
}

double polynomial3(double a, double b)
{
    return pow(b, 4) - 4 * a * pow(b, 3);
}
