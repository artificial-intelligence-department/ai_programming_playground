#include <iostream>
#include <math.h>
#include <stdio.h>

int main() {
   
    double a = 1000;
    double b = 0.0001;

    double x = pow((a-b), 3);
    double y = pow(a, 3);
    double z = pow(b, 3);

    std :: cout << "Result:" << (x-(y-3*a*a*b))/(z-3*a*b*b) << std :: endl;

    return 0;
}