//
// Created by olehio_p on 10/28/2023.
//
#include <iostream>
#include <cmath>

int main(int argc, char const *argv[])
{
    int a = 1000;
    double b = 0.0001;
    double nominator, denominator, c, d, e, f, g, h, j, k, result;


    c = a + b;
    d = pow(c, 3);
    e = pow(a, 3);
    nominator = d - e;

    f = pow(b, 2);
    g = 3 * a * f;
    h = pow(b, 3);
    j = pow(a, 2);
    k = 3 * j * b;
    denominator = g + h + k;

    result = nominator / denominator;
    printf("Result using double data type is %f\n", result);
    return 0;
}
