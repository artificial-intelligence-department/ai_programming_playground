#include <iostream>
#include <stdio.h>
#include <math.h>
// варіант 4
int main()
{
    double a, b, x, t, h, result;
    a = 1000;
    b = 0.0001;

    x = pow(a+b,3);
    t = pow(a,3);
    h = 3*a*pow(b,3) + pow(b,3) + 3*pow(a,3)*b;

    result = (x-t)/h;

    std::cout << "The result  is: " << result;
    
    return 0;
}
