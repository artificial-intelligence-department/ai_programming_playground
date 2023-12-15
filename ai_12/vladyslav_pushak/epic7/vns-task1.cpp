#include <cmath>
#include <iostream>

int main() {
    double x = 1.25;
    double y = 0.93;
    double a = (1-y)*pow((x+y),2)/pow((x+4),2)/exp(x-2) + pow(x,3) + 4;
    double b = (1+cos(y-2))/pow(x,2) + pow(sin(y-2),2);
    double p = a/b;
   
    std::cout << p;

    
    return 0;

   
}
