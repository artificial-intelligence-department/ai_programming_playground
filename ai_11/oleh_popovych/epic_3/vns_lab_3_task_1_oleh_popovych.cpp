//
// Created by olehio-h on 11/22/2023.
//
#include <iostream>
#include <cmath>


double calculateByStdMethod(double);
double calculateByPartialSumMethod(double, int);
double calculateWithGivenPrecision(double, double);

int main(int argc, char const *argv[])
{

    double a = 0.1, b = 1, k = 10;
    double x = a, n = 10;
    double epsilon = 0.0001;

    while(x <= b) {
        printf("X = %-5.2f", x);
        printf("SN = %-10f", calculateByPartialSumMethod(x, n));
        printf("SE = %-10f", calculateWithGivenPrecision(x, epsilon));
        printf("Y = %6f\n", calculateByStdMethod(x));

        x += (b - a) / k;
    }
    return 0;
}

double calculateByStdMethod(double x) {
    return (exp(x) + exp(-x)) / 2;
}

double calculateByPartialSumMethod(double x, int n) {
    double current = 1, sum = 1, prev;

    for(int i = 0; i < n; i++) {
        prev = current;
        current = prev * pow(x, 2) / ((2 * i + 2) * (2 * i + 1));
        sum += current;
    }
    return sum;
}

double calculateWithGivenPrecision(double x, double epsilon) {
    double current = 1, sum = 1, prev;
    int i = 0;

    while(current >= epsilon) {
        prev = current;
        current = prev * pow(x, 2) / ((2 * i + 2) * (2 * i + 1));
        sum += current;
        i++;
    }
    return sum;
}
