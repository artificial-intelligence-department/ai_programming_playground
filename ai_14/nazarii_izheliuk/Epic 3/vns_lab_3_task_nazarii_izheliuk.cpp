#include <iostream>
#include <cmath>

double term(double x, int n) {
    double result = 0.0;
    double term = 1.0;

    for (int i = 1; i <= n; ++i) {
        term *= (-1) * (2 * x) * (2 * x) / (2 * i * (2 * i - 1));
        result += term;
    }

    return result;
}

int main() {
    double a, b, e, sum_e, y, sum_n, x, step ;
    int c, n;

    a = 0.1; 
    b = 1.0; 
    
    c = 10; 
    n = 15; 
    e = 0.0001; 

    step = 0.1;

    for (x = a; x <= b; x += step) {
        y = 2 * ((cos(x) * cos(x)) - 1);
        sum_n = term(x, n);

        double sum_e= 0.0;
        double term = 1.0;
        int i = 1;

        while (std::abs(term) > e) {
            term *= (-1) * (2 * x) * (2 * x) / (2 * i * (2 * i - 1));
            sum_e += term;
            ++i;
        }

        std::cout << "X=" << x << " SN=" << sum_n << " SE=" << sum_e << " Y=" << y << std::endl;
    }

    return 0;
}