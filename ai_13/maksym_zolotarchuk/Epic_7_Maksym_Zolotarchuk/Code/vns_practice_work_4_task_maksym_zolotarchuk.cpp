#include <iostream>
#include <cmath>
using namespace std;

double Function(double x)
{
 return 5 * pow(x, 2) - x + 2;
}

double MethodofRectangles(double a, double b, double n) // a і b - відрізок n - кількість прямокутників(чим більше тим більша точність)
{
    double h, x;
    h = (b - a) / n;
    double S = 0;
    int i = 0;
    while (i < n - 1)
    {
        x = a + i * h;
        S += Function(x);
        ++i;
    }
    S = h * S;
    return S;
 
}

int main()
{
 
 double result;
 result = MethodofRectangles(2, 4, 6);

 cout << result << endl;

    return 0;

}
