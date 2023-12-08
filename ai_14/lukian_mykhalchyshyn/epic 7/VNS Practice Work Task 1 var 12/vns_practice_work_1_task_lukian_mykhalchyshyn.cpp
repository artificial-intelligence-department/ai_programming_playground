#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main()
{
    double P, V, M, N, x = 0.25, y = 1.31, a = 3.5, b = 0.9, pi = 3.14159; //дійсні змінні з подвійною точністю
    
    M = pow(sin(a * pow(x,3) + b * pow(y,2) - a * b),3); // математична операція pow, sin
    
    N = cbrt(a * pow(x,3) + b * pow(y,2) - a) * (a * pow(x,3) + b * pow(y,2) - a) + pi; // математична операція pow, cbrt

    V = tan(a * pow(x,3) + b * pow(y,2) - a * b); // математична операція pow, tan

    P = (M/N)+V;

    cout << "P = " << P; // оператор виведення

    return 0;
}