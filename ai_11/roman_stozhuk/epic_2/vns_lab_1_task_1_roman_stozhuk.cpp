#include <iostream>
#include <cmath>

int main() {
    double a = 100, b = 0.001;
    double c = pow((a-b),4);
    double d = pow(a,4);
    double e = 4*b*pow(a,3);
    double f = 6*pow((a*b),2);
    double g = 4*a*pow(b,3);
    double h = pow(b,4);
    double numerator = (c-(d-e));
    double denominator = (f-g+h);
    double result = numerator/denominator;
    std::cout << result;
    return 0;
}