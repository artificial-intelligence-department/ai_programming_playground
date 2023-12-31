#include <iostream>
#include <cmath>

using namespace std;


int main() {
    float a = 100, b = 0.001;
    float numerator = pow((a + b), 4) - (pow(a, 4) + 4 * pow(a, 3) * b);
    float denominator = 6 * pow(a, 2) * pow(b, 2) + 4 * a * pow(b, 3) + pow(b, 4);
    float result = numerator / denominator;

    cout << "Your result = " << result << endl;

    return 0;
}