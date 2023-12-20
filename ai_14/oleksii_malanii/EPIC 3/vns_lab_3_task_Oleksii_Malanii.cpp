#include <iostream>
#include <cmath>
double f(double x) {
    return exp(x);
}
int factr(int n) {
    return (n == 0 || n == 1) ? 1 : n * factr(n - 1);
}
double p(double x, int n) {
    double result = 0;
    for (int i = 0; i <= n; ++i) {
        result += pow(x, i) / factr(i);
    }
    return result;
}
int main() {
    const double a = 1.0;
    const double b = 2.0;
    const int k = 10;
    const double epsilon = 0.0001;
    for (double x = a; x <= b; x += (b - a) / k) {
        double Result = f(x);
        int n = 5;  
        double Resultser = p(x, n);

        std::cout << "x = " << x << "\tExact: " << Result << "\tSeries: " << Resultser << std::endl;
    }
    return 0;
}
