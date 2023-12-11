#include <iostream>
#include <cmath>

int main()
{
    int x = 2, y = 2; 

    double a = (sqrt(abs(x-1))- sqrt(y))/ (1 + pow(x, 2)/2 + pow(y, 2)/4);
    std::cout << "A = " << a << std::endl;

    double b = 1/(tan(exp(x)));
    std::cout << "B = " <<b;
}