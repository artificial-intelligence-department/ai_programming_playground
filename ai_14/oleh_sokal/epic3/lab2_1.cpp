#include <stdio.h>
#include <math.h>

int main() {
    double sum = 2.0;
    int n = 2;
    double expression;
    double epsilon = 0.0001;

    do {
        expression = (n + 1.0) / pow(n, 2);
        sum += expression;
        n++;
    } while (expression >= epsilon);

    printf("%.10lf\n", sum);
    return 0;
}