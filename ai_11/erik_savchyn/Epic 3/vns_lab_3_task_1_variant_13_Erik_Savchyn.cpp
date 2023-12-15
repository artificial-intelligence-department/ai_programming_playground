#include <iostream>
#include <cmath>

int main() {
    double a = 0.2;
    double b = 1.0;
    int k = 10;
    int n = 10;
    double epsilon = 0.0001;

    for (int i = 0; i <= k; i++) {
        double x = a + i * (b - a) / k;

        double exactValue = 0.5 * log(x);

        double sumN = 0.0;
        for (int j = 0; j <= n; j++) {
            double term = 1.0 / (2 * j + 1) * pow((x - 1) / (x + 1), 2 * (j + 1) - 1);
            sumN += term;
        }

        double sumE = 0.0;
        double term = 1.0;
        int j = 0;
        while (fabs(term) >= epsilon) {
            term = 1.0 / (2 * j + 1) * pow((x - 1) / (x + 1), 2 * (j + 1) - 1);
            sumE += term;
            j++;
        }

        printf("X=%f SN=%f SE=%f Y=%f\n", x, sumN, sumE, exactValue);
    }

    return 0;
}