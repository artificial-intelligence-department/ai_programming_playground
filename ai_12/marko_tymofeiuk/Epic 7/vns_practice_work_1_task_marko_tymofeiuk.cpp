#include <iostream>
#include <cmath>

int main(){
    const long double a = 1.1, b = 0.004, x = 0.2;

    long double y = pow(sin(pow(a, 2)), 3) - cbrt(x/b);

    long double z = pow(x, 2)/a + pow(cos(pow((x+b), 3)), 2);

    std::cout << "y = " << y << std::endl;

    std::cout << "z = " << z << std::endl;

    return 0;
}
