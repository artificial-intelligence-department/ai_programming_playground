#include <iostream>
#include <cmath>

struct Result {
    double P;
    double tg;
};

int main() {
    const int x = 0.25;
    const int y = 1.31;
    const int a = 3.5;
    const int b = 0.9;
    const double pi = 3.14159;

    double expression1 = pow(sin(pow(a*x*x*x + b*y*y - a*b, 3)), 3);
    double expression2 = cbrt(pow(a*x*x*x + b*y*y - pow(a, 2), 3)) + pi;
    double expression3 = tan(a*x*x*x + b*y*y - a*b);

    Result result;
    result.P = abs(expression1 / expression2) + expression3;
    result.tg = expression3;

    std::cout << "P = " << result.P << std::endl;
    std::cout << "tg = " << result.tg << std::endl;

    return 0;
}