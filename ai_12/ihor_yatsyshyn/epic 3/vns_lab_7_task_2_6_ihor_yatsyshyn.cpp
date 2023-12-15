#include <iostream>

double substract(double x, double y);
void substract(double r1, double r2, double i1, double i2, double &real, double &imaginable);

int main() {
    double real, imaginable;
    char op;

    std::cout << substract(12.34, 7.9) << std::endl;

    substract(5, 2.5, 4.3, 2.3, real, imaginable);
    if(imaginable > 0) {
        op = '+';
    }else {
        op ='-';
    }

    std::cout << "z = " << real << op << imaginable << "i" << std::endl;

    return 0;
}

double substract(double x, double y) {
    double res;
    res = x - y;

    return res;
}

void substract(double r1, double r2, double i1, double i2, double &real, double &imaginable) {
    real = substract(r1, r2);
    imaginable = substract(i1, i2);
}