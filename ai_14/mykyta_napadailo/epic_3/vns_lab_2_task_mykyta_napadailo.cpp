#include <iostream>
#include <cmath>
using namespace std;

int factorial(int n);

int main ()
{
    const float e = 2.71828, epsilon = 0.0001;
    int n = 1;
    float a, sum = 0;
    do 
    {
        int f = factorial(3*n - 3);
        a = pow(n, 3) / f;
        sum += a;
        n++;
    }
    while (abs(a) > epsilon);
    cout << "The sum of series is equal to " << sum;
    return 0;
}

int factorial(int n)
{
    if (n == 0) 
    {
        return 1;
    }
    else return n *= factorial(n - 1);
}