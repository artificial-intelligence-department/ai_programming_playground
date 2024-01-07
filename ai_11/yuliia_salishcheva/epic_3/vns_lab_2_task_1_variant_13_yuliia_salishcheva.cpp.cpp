#include <iostream>
#include <cmath>

//int factorial(int n) {
//    int result = 1;
//    for (int i = 1; i <= n; i++) {
//        result *= i;
//    }
//    return result;
//}
int main() {
    const double epsilon = 0.0001;
    int n = 1;
    double sum_result = 0;
    double value = (pow(3, n) * tgamma(n+1) / tgamma(3 * n+1));

    while (value >= epsilon) {


        sum_result += value;
        n++;

        value = value / ((3 * n + 1) * (3 * n + 2));
    }

    std::cout << "The sum of the series with precision epsilon = 0.0001: " << sum_result << std::endl;

    return 0;
}