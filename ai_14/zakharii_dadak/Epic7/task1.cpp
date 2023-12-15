#include <iostream>
#include <cmath>


using namespace std;

int main() {
    float a = 0.7;
    float b = 0.05;
    float x = 0.05;
    float R = 0;
    float S = 0;
    R = pow(x,3) * (x+1) / (pow(b,2) - pow(sin(x*(x+a)), 2));
    S = sqrt(x*b/a) + pow(cos(pow((x+b), 3)), 2);
    std::cout << R << std::endl << S;

}