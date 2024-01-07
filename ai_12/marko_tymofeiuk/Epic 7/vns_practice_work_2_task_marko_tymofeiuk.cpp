#include <iostream>
#include <cmath>

int main(){
    double x = 1, a = 2, y;

    while(x <= 8 && a <= 10){
        if (a > x){
            y = pow(a, 2) + x;
        } else if (a == x){
            y = pow(a, 2);
        } else if (a < x){
            y = pow(a, 2) - x;
        }

        std::cout << "x = " << x << "    y = " << y << "    a = " << a << std::endl;

        x += 0.5;
        a += 1;
    }
}