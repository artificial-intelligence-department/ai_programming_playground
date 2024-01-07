#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double sum_result = 0.0;
    int n = 0;

    while (true) {
        double term = (pow(2, n) * tgamma(n + 1)) / pow(n, n);  
        sum_result += term;

        if (term < 0.0001) {
            break;  
        }

        n++;
    }
    cout << "The sum of the series for a_n = ((2^n * n!)/n^n) with precision e=0.0001: " << sum_result << '\n';

    return 0;
}
