//
// Created by olehio-p on 12/10/2023.
//
#include <iostream>
#include <cmath>

double calculateY(double, double);

int main(int argc, char const *argv[])
{
    double x, xLowerBound, xUpperBound, hx, a, aLowerBound, aUpperBound, ha;
    xLowerBound = 1;
    xUpperBound = 8;
    hx = 0.5;

    aLowerBound = 2;
    aUpperBound = 10;
    ha = 1;

    x = xLowerBound;
    while (std::abs(x - xUpperBound) > 0.00001) {
        a = aLowerBound;
        std::cout << "-------------------------------------------------" << std::endl;
        while(std::abs(a - aUpperBound) > 0.00001) {
            printf("X: %.2f, A: %.2f, the value of y: %5.2f\n", x, a, calculateY(x, a));
            a += ha;
        }
        x += hx;
    }

    return 0;
}

double calculateY(double a, double x) {
    if (a > x) {
        return pow(a, 2) + x;
    } else if (a < x) {
        return pow(a, 2) - x;
    } else {
        return pow(a, 2);
    }
}
