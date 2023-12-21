#include <iostream>

int main() {
    double epsilon = 0.0001;
    double sum = 0;
    double term = 1;

    for (int n = 0; fabs(term) >= epsilon; ++n) {
        sum += term;
        term /= (9.0 * n * n + 9.0 * n + 2.0);
    }
    sum--;
    printf("a(n)=%f < ε=%.4f; ans: %f\n", term, epsilon, sum);

    return 0;
}
