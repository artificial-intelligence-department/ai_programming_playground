#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a = 100;
    double b = 0.001;
    cout << (pow(a + b, 4) - (pow(a, 4) + 4 * b * pow(a, 3))) / (6 * pow(a, 2) * pow(b, 2) + 4 * a * pow(b, 3) + pow(b, 4));

    return 0;
}