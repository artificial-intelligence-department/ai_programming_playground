    #include <stdio.h>
#include <math.h>

int main() {
    double a = 16.5, b = 3.4, x = 0.61;

    double S = ((pow(x, 3) * pow(tan(x), 2) * pow((x + b), 2) + a) / sqrt(x + b));
    double C = ((b * pow(x, 2) - a) / ((exp(a * x)) - 1));

    printf("S = %lf\n", S);
    printf("C = %lf\n", C);

    return 0;
}
