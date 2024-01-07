#include <iostream>
#include <cmath>

int main(){
    double a = 0.3, b = 0.9, x = 0.53, R, Y;

    Y = (pow(a, 2*x)+pow(b, -x)*cos(a+b)*x)/fabs(x+1);
    R = sqrt(pow(x,2)+b) - (pow(b,2) * pow(sin(x+a),3))/x;
    
    std::cout << "Y = " << Y << std::endl;
    std::cout << "R = " << R << std::endl;

    return 0;
}