#include <iostream>
#include <cmath>

int main() {
    double x=1.0,h_x=0.5, a=-0.5,h_a=0.2;
    do {
        if ((a<=-0.5) || (x-2)==0) {
            //Вимога #5 - в коді використані умовні оператори та розгалуження
            a+=h_a; 
            x+=h_x;
            continue;
            //Вимога #11 - в коді використано оператори break і continue
        }
        double z = (sqrt(x-1.5)+pow(x, a)) / cbrt(x-2);
        std::cout << "x=" << x << "    a=" << a << "    z=" << z << std::endl;
        a+=h_a;
        x+=h_x;

    } while (x <= 4);
    //Вимога #8 - в коді використаний do while цикл
    return 0;
}