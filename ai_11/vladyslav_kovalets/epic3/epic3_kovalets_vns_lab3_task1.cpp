#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    long double S = 0;  
    const long double pi = 3.14159265358979323846;  
    const long double a = pi / 5, b = (9 * pi) / 5;
    const int n = 40, k = 10; // при заданому n
    long double r = (b - a) / k; 

    for (double x = a; x <= b ; x += r) 
    {
        S = 0;  
        for (int i = 1; i <= n; i++) 
        {
            S += cos(i * x) / i;
        }
        cout << "S(" << x << ") = " << S << endl;
    }

    return 0;
}
