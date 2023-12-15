//
// Created by olehio-p on 10/28/2023.
//
#include <iostream>
#include <cmath>


int main(int argc, char const *argv[])
{
    double sum = 0, nominator, denominator;

    // As natural log of 1 is 0, we get 0 in denominator
    // and the result becomes the infinity, so I start with 2
    for(int n = 2; n <= 16; n++)
    {
        nominator = pow(n, log(n));
        denominator = pow(log(n), n);
        sum += nominator / denominator;
    }

    printf("Sum of 15 members of the series is %.4f\n", sum);

    return 0;
}
