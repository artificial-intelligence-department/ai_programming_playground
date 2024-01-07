#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double sum = 0;
    double value = 0;

    for(int n = 1; n <= 15; n++)
    {
        value = pow(n, log10(n)) / pow(log10(n), n);
        sum += value;
    }

    cout << "The sum of the first 15 terms of the sequence is " << sum << "\n";

    return 0;
}