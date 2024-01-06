//
// Created by olehio-p on 12/10/2023.
//
#include <iostream>
#include <cmath>

double calculateY(double, double, double);
double calculateZ(double, double, double);

int main(int argc, char const *argv[])
{
    double a, b, x;
    a = 3.2;
    b = 17.5;
    x = -4.8;

    printf("The value of the function with these parameters: "
           "a = %.2f, b = %.2f, x = %.2f is y: %f\n",
           a, b, x, calculateY(a, b, x));

    printf("The value of the function with these parameters: "
           "a = %.2f, b = %.2f, x = %.2f is z: %f\n",
           a, b, x, calculateZ(a, b, x));
    return 0;
}

double calculateY(double a, double b, double x) {
    double y;
    y = pow(b, 3) * pow(tan(x), 2) - (a / pow(sin(x / a), 2));

    return y;
}

double calculateZ(double a, double b, double x) {
    double z;
    z = a * exp(-sqrt(3)) * cos((b * x) / a);

    return z;
}