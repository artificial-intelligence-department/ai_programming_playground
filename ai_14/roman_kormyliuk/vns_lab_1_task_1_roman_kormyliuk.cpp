#include <iostream>
#include <cmath>

int main() {
    //double a, b, c, d, e, result; 
    float a, b, c, d, e, result;
    a = 1000;
    b = 0.0001;
    c = pow((a-b), 3);
    d = pow(a, 3);
    e = pow(b, 3);
    result = (c-(d-3*a*a*b))/(e-3*a*b*b);

    std::cout << "Result: " << result << std::endl;

    return 0;
}